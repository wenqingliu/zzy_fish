package com.jt.sdk_platform_uuc;

import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate.OrderListener;
import com.jt.sdk_platform_pay.UucPay;
import com.jt.user.UserLoginInfo;
import com.uucun.android.passport.openApi.SdkCallback;
import com.uucun.android.passport.openApi.SdkOpenApi;
import com.uucun.android.passport.openApi.UserSimpleInfo;

public class SDKControl extends SDKControlOriginal {
	public static final String TAG = "SDKControl";
	private UucPay uucPay = null;
	private String uupayPassId = null;
	public SDKControl() {

	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		SdkOpenApi.sdkStart();
	}

	@Override
	public byte AccountType() {
		return (byte) _UUCAccount;
	}
	
	@Override
	public void CCLoginType(JSONObject response) {
		JSONObject j1 = new JSONObject();
		try {
			j1.put("loginType", _UUCAccount);
			j1.put("visible", true);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_PlatForm_LogonType", j1);
	}
	
	@Override
	public void CCGameLogin(JSONObject response) {
		SdkOpenApi.openPassportSdk(_context, new SdkCallback() {
			
			@Override
			public void onResult(boolean ret) {
				// 此处ret值只为true
				if (SdkOpenApi.isLogined()) {
//					Toast.makeText(_context, "回调-退出sdk-登录成功",
//							Toast.LENGTH_SHORT).show();
					onUUCLogin();
				} else {
					Toast.makeText(_context, "uuc 登录失败",
							Toast.LENGTH_SHORT).show();
					
					onLoginResulet(0);
				}
				// 显示logo
				SdkOpenApi.showFloatButton(this);
			}
		});

	}

	private void onUUCLogin(){
		UserSimpleInfo usi = SdkOpenApi.getUserInfo();
		
		Log.e(TAG, ""+usi.accessToken);
		Log.e(TAG, ""+usi.uuptid);
		
		
			// 获取成功
			UserLoginInfo userLogoInfo = getUserLogoInfo();
			userLogoInfo.reset();

//			JSONObject dataJobj = response.getJSONObject("data");
			String accountId = usi.uuptid;
			uuid = accountId;
			uupayPassId = accountId;
			String nickName = usi.nickName;

			userLogoInfo.setAcccount(nickName);
			userLogoInfo.setAccountType(_UCAccount);
			userLogoInfo.setFaceID(uuid);

			userLogoInfo.setBigFace("");
			userLogoInfo.setGender(0);
			onLoginResulet(1);
	}
	
	public void onLoginResulet(int result) {
		if (uuid.length() <= 2) {
			result = 0;
		}

		if (uuid.length() != 0) {
			
		}

		JSONObject jUser = new JSONObject();
		UserLoginInfo userLogoInfo = getUserLogoInfo();
		try {
			jUser.put("result", result);
			jUser.put("acccount", userLogoInfo.getAcccount());
			jUser.put("uuid", uuid);
			jUser.put("accountType", userLogoInfo.getAccountType());
			jUser.put("szMachineID", JniHelper.m_Mac);
			jUser.put("bigFace", userLogoInfo.getBigFace());
			jUser.put("gender", userLogoInfo.getGender());
		} catch (JSONException e) {
			e.printStackTrace();
		}
		Log.i(TAG, userLogoInfo.toString());
		Log.i(TAG, "onLoginResulet:" + result);
		SendMessageWithParameters("ccNd_Platform_LogonResult", jUser);
	}
	
	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		final ProductInfoItem item = ProductInfoItem.parseObject(response);
		if (uucPay == null) {
			initUucPay();
		}
		getDelegate().getOrderInfo(response, new OrderListener() {
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub
				uucPay.pay(order, item.getMoney() + "", item.getProductName(),
						item.getProductName(), item.getProductId(), "1",
						item.getUserID() + "", item.getDomainURL(),uupayPassId);
			}
		});

	}

	private void initUucPay() {
		uucPay = new UucPay(_context);
	}

}
