package com.jt.sdk_platform_mi;


import java.util.UUID;

import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.Toast;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate.OrderListener;
import com.jt.user.UserLoginInfo;
import com.xiaomi.gamecenter.sdk.MiCommplatform;
import com.xiaomi.gamecenter.sdk.MiErrorCode;
import com.xiaomi.gamecenter.sdk.OnLoginProcessListener;
import com.xiaomi.gamecenter.sdk.OnPayProcessListener;
import com.xiaomi.gamecenter.sdk.entry.MiAccountInfo;
import com.xiaomi.gamecenter.sdk.entry.MiAppInfo;
import com.xiaomi.gamecenter.sdk.entry.MiBuyInfo;
import com.xiaomi.gamecenter.sdk.gam.MiResponseHandler;

public class SDKControl extends com.jt.sdk_platform_base.SDKControlOriginal implements OnLoginProcessListener,OnPayProcessListener {
	public static final String TAG = "SDKControl";
	public static String APP_ID = "2882303761517447705";
	public static String APP_KEY = "5951744795705";
	private MiAccountInfo accountInfo;
	private String session;
	
	public static MiAppInfo appInfo;
	
	public SDKControl(){
		/** SDK初始化 */
		appInfo = new MiAppInfo();
		appInfo.setAppId(APP_ID);
		appInfo.setAppKey(APP_KEY);
		MiCommplatform.Init( _context, appInfo );
	}
	
	@Override
	public byte AccountType() {
		return (byte) _XiaoMiAccount;
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
		MiCommplatform.getInstance().miLogin((Activity) _context,this);
    }
	

	@Override
	public void CCGameLogout(JSONObject response){
		
	}
	
	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		ProductInfoItem item = ProductInfoItem.parseObject(response);
		Log.i(TAG, "");
		int money = (int)item.getMoney();
		final MiBuyInfo miBuyInfo = new MiBuyInfo();
		miBuyInfo.setCpUserInfo(item.getProductId());
		miBuyInfo.setAmount( money );
		
		getDelegate().getOrderInfo(response, new OrderListener() {
			
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub
				miBuyInfo.setCpOrderId(order);
				MiCommplatform.getInstance().miUniPay((Activity) _context,
						miBuyInfo, SDKControl.this);
			}
		});
		
	}
	
	private MiBuyInfo createMiBuyInfo( String productCode, int count )
	{
		MiBuyInfo miBuyInfo = new MiBuyInfo();
		miBuyInfo.setProductCode( productCode );
		miBuyInfo.setCount( count );
		miBuyInfo.setCpOrderId( UUID.randomUUID().toString() );
		
		return miBuyInfo;
	}
	
	private Handler handler = new Handler()
	{
		public void handleMessage( Message msg )
		{
			switch (msg.what) {
			case 10000:
				MiBuyInfo miBuyInfo = (MiBuyInfo) msg.obj;
				MiCommplatform.getInstance().miUniPay((Activity) _context,
						miBuyInfo, SDKControl.this);
				break;
			case 20000:
				break;
			case 30000:
				// Toast.makeText(_context, "登录成功", Toast.LENGTH_SHORT ).show();
				UserLoginInfo userLogoInfo = getUserLogoInfo();
				userLogoInfo.reset();
				uuid = String.valueOf(accountInfo.getUid());
				userLogoInfo.setAcccount("小米手机用户");
				userLogoInfo.setAccountType(AccountType());
				userLogoInfo.setFaceID(uuid);
				userLogoInfo.setBigFace("");
				userLogoInfo.setGender(0);
				getDelegate().onLoginResulet(1);
				break;
			case 40000:
				Toast.makeText(_context, "登录失败", Toast.LENGTH_SHORT).show();
				break;
			case 70000:
				Toast.makeText(_context, "正在执行，不要重复操作", Toast.LENGTH_SHORT)
						.show();
				break;
			case 80000:
				boolean isLogin = (Boolean) msg.obj;
				String text = "已登录";
				if (!isLogin)
					text = "未登录";
				Toast.makeText(_context, text, Toast.LENGTH_SHORT).show();
				break;
			case MiErrorCode.MI_XIAOMI_PAYMENT_SUCCESS:
				Toast.makeText(_context, "购买成功", Toast.LENGTH_LONG).show();
				getDelegate().onPayResult(-1,1);
				break;
			case MiErrorCode.MI_XIAOMI_PAYMENT_ERROR_CANCEL:
			case MiErrorCode.MI_XIAOMI_PAYMENT_ERROR_PAY_CANCEL:
				Toast.makeText(_context, "取消购买", Toast.LENGTH_LONG).show();
				break;
			case MiErrorCode.MI_XIAOMI_PAYMENT_ERROR_PAY_FAILURE:
				Toast.makeText(_context, "购买失败", Toast.LENGTH_LONG).show();
				getDelegate().onPayResult(-1,0);
				break;
			case MiErrorCode.MI_XIAOMI_PAYMENT_ERROR_PAY_REPEAT:
				Toast.makeText(_context, "您已经购买过，无需购买", Toast.LENGTH_LONG)
						.show();
				break;
			case MiErrorCode.MI_XIAOMI_PAYMENT_ERROR_ACTION_EXECUTED:
				Toast.makeText(_context, "正在执行，不要重复操作", Toast.LENGTH_SHORT)
						.show();
				break;
			case MiErrorCode.MI_XIAOMI_PAYMENT_ERROR_LOGIN_FAIL:
				Toast.makeText(_context, "您还没有登陆，请先登陆", Toast.LENGTH_LONG)
						.show();
				break;
			default:
				break;
			}
		};
	};

	@Override
	public void finishLoginProcess(int arg0, MiAccountInfo arg1) {
		// TODO Auto-generated method stub
		if ( MiErrorCode.MI_XIAOMI_PAYMENT_SUCCESS == arg0 )
		{
			accountInfo = arg1;
			session = arg1.getSessionId();
			handler.sendEmptyMessage( 30000 );
		}
		else if ( MiErrorCode.MI_XIAOMI_PAYMENT_ERROR_ACTION_EXECUTED == arg0 )
		{
			handler.sendEmptyMessage( 70000 );
		}
		else
		{
			handler.sendEmptyMessage( 40000 );
		}
	}

	@Override
	public void finishPayProcess(int arg0) {
		// TODO Auto-generated method stub
		handler.sendEmptyMessage( arg0 );
	}
	
}
