package com.jt.sdk_platform_Letv;


import java.util.HashMap;
import java.util.UUID;

import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.Toast;

import com.jt.activity.WelcomeActivity;
import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate.OrderListener;
import com.jt.user.UserLoginInfo;
import com.letv.lepaysdk.smart.LePayInfo;
import com.letv.letvsdk.LetvSDK;
import com.letv.letvsdk.LetvSDK.ExitCallback;
import com.letv.letvsdk.LetvSDK.InitCallback;
import com.letv.letvsdk.LetvSDK.LoginCallback;
import com.letv.letvsdk.LetvSDK.PayCallback;

public class SDKControl extends com.jt.sdk_platform_base.SDKControlOriginal {
	private LetvSDK letvSDK;

	private String TAG = "LetvSDK";

//	private String letv_uid = null;
	private String access_token = null;

	private String product_image = null;

	private boolean isPay = false;
	
	private boolean isLogout = false;
	
	private LePayInfo payInfo = null;
	
	public SDKControl(){
		/** SDK初始化 */
		/* 初始化回调*/
		InitCallback initCallback_ = new InitCallback() {
		@Override
			public void onSdkInitResult(String status, String resultMessage) {
				Log.i("TAG", "===onSdkInitResult is called===");
				Log.i(TAG, "Init_Status: "+status+", resultMessage: "+resultMessage);
			}
		};
		letvSDK = LetvSDK.init((Activity) _context, initCallback_);
	}
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		Intent intent = new Intent();
		intent.setClass(_context, WelcomeActivity.class);
		_context.startActivity(intent);
	}
	
	@Override
	public byte AccountType() {
		return (byte) _LetvAccount;
	};
	
	@Override
	public void CCLoginType(JSONObject response) {
		// TODO Auto-generated method stub
		JSONObject j1 = new JSONObject();
		try {
			j1.put("loginType",AccountType());
			j1.put("visible",true);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_PlatForm_LogonType",j1);
	}
	
	@Override
	public boolean isLogined() {
		return false;
	}

	@Override
    public void CCGameLogin(JSONObject response){
    	setAccountType(AccountType());
    	// 调用SDK执行登陆操作
    	LoginCallback loginCallback = new LoginCallback(){
    		@Override
    		public void onLoginResult(HashMap<String, Object> userInfo) {
    		// TODO Auto-generated method stub
	    		if (userInfo != null) {
		    		// 获取 access_token
		    		access_token = (String) userInfo.get("access_token");
		    		// 获取 letv_uid
		    		uuid = (String) userInfo.get("letv_uid");
		    		String nickname = (String) userInfo.get("nickname");
		    		String faceFile = (String) userInfo.get("file_70*70");
		    		
		            UserLoginInfo userLogoInfo = getUserLogoInfo();
		            userLogoInfo.reset();
					userLogoInfo.setAcccount(nickname);
					userLogoInfo.setAccountType(AccountType());
					userLogoInfo.setFaceID(uuid);
					userLogoInfo.setBigFace(faceFile);
					userLogoInfo.setGender(1);
					getDelegate().onLoginResulet(1);
					isLogout = false;
		    		Log.i("info", access_token + "..." + uuid + "..." + nickname);
	    		}
	    		else{
					getDelegate().onLoginResulet(0);
	    		}
		}

			@Override
			public void onLoginQuit() {
				// TODO Auto-generated method stub
			}
    	};
    	letvSDK.login((Activity) _context, loginCallback, isLogout);
    }
	

	@Override
	public void CCGameLogout(JSONObject response){
		isLogout = true;
	}
	
	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		ProductInfoItem item = ProductInfoItem.parseObject(response);
		
		String id = "";
		String notify_url = "";
		String product_price = "";
		String product_id= "";
		String product_name = "";
		String product_dec = "";
		try {
			id = response.getString("gameID");
			notify_url = response.getString("domainURL")+"/lenoticeurl.aspx";
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		product_price = String.valueOf(item.getMoney());
		product_name = item.getProductName();
		product_dec = item.getDesc();
		product_id = item.getProductId();
		
		payInfo = new LePayInfo();
		payInfo.setLetv_user_access_token(access_token);
		payInfo.setLetv_user_id(uuid);// 乐视集团用户 id
		payInfo.setNotify_url(notify_url);// 支付结果回调地址
		
		
		payInfo.setPrice(product_price);// 产品价格
		payInfo.setProduct_name(product_name);// 商品名称
		payInfo.setProduct_desc(product_dec);// 商品描述
		payInfo.setPay_expire("10");// 支付结束期限
		payInfo.setProduct_id(product_id);// 商品 id
		payInfo.setCurrency("RMB");// 货币种类
		payInfo.setProduct_urls("file://android_asset/res/drawable/aaa.png");// 商品图片

		getDelegate().getOrderInfo(response, new OrderListener() {
			
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub
				payInfo.setCooperator_order_no(order);// 商户订单号,生成随机数，由 cp 定义，唯一；
				payInfo.setExtro_info(order);//cp 自定义参数
				PayCallback payCallback = new PayCallback() {
					@Override
					public void onPayResult(String status, String errorMessage) {
						Log.i("info", "==onPayResult is called==");
						Log.i("info", "Status:" + status + ", ErrorMessage" + errorMessage);
						if (status.equals("success")) {
							//支付成功
							getDelegate().onPayResult(-1,1);
						}else {
							//支付失败
							getDelegate().onPayResult(-1,0);
						}
					}
				};
				letvSDK.pay((Activity) _context, payInfo, payCallback);//发起支付
			}
		});
	}
	
	@Override
	public void onResume(){
		super.onResume();
		Log.i(TAG, "===LeTV onResume is called===");
		letvSDK.resume((Activity) _context);
	}
	
	@Override
	public void onPause() {
		super.onPause();
		Log.i(TAG, "===LeTV onPause is called===");
		letvSDK.pause((Activity) _context);
	}
	
	@Override
	public Boolean CCQueryExitGame(JSONObject response) {
		ExitCallback back = new ExitCallback() {
		@Override
		public void onSdkExitCanceled() {
			// TODO Auto-generated method stub
			Log.i(TAG, "===LeTV onSdkExitCanceled===");
			}

		@Override
		public void onSdkExitConfirmed() {
			// TODO Auto-generated method stub
			Log.i(TAG, "===LeTV onSdkExitConfirmed===");
				((Activity)_context).finish();
				System.exit(0);
			}
		};
		letvSDK.exit((Activity) _context,back );
		return true;
	}
}
