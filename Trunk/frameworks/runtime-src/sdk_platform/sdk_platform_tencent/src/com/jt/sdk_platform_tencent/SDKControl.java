package com.jt.sdk_platform_tencent;


import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.text.TextUtils;
import android.util.Log;
import android.widget.Toast;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_tencent.BaseUIListener;
import com.jt.user.UserLoginInfo;
import com.tencent.connect.UserInfo;
import com.tencent.connect.common.Constants;

import com.tencent.tauth.Tencent;
import com.tencent.tauth.UiError;

public class SDKControl extends com.jt.sdk_platform_base.SDKControlOriginal {
	public static final String TAG = "SDKControl";
	public static String APP_ID = "1104540804";//1104540804;//222222
	static{
		if(JniHelper.getAppDebug()==0){
			APP_ID = "1104540804";//发行版
		}else{
			APP_ID = "222222";//测试版
		}
	}
	
	public final static String APP_KEY = "7IcL3m2HVP94R5qD";//7IcL3m2HVP94R5qD
	public static Tencent mTencent;
	private UserInfo mInfo;
	private boolean isLoading;
	private SDKControlOriginal sdkPay;
	
	@Override
	public byte AccountType() {
		return (byte) _QQAccount;
	};
	
	@Override
	public boolean isLogined() {
		// 用户登陆方式
		UserLoginInfo userLogoInfo = getUserLogoInfo();
		if(userLogoInfo.getFaceID() != null && userLogoInfo.getFaceID().length() > 2){
			return true;
		}else{
			return mTencent != null && mTencent.isSessionValid();
		}
	}
	
	@Override
	public void CCLoginType(JSONObject response) {
		// TODO Auto-generated method stub
		JSONObject j1 = new JSONObject();
		try {
			//开启微信登录
			j1.put("loginType",AccountType());
			j1.put("visible",true);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_PlatForm_LogonType",j1);
	}

	@Override
    public void CCGameLogin(JSONObject response){
    	setAccountType(AccountType());
    	if(isLoading){
    		Toast.makeText(_context, "正在获取用户资料，请稍候...",Toast.LENGTH_SHORT).show();
    		return;
    	}
    	
    	if(isAutoLogin(Cocos2dxActivity.getContext())){
    		//记录了原uuid，直接登录
			 uuid = getUserLogoInfo().getFaceID();
			 getDelegate().onLoginResulet(1);
			 return;
    	}else if(isLogined())
		{
			 //记录了原uuid，直接登录
			 uuid = getUserLogoInfo().getFaceID();
			 getDelegate().onLoginResulet(1);
			 return;
		}
		if(mTencent == null){
			mTencent = Tencent.createInstance(APP_ID,_context);
		}
		if (!mTencent.isSessionValid()) {
			mTencent.login((Activity)_context, "get_simple_userinfo", new BaseUIListener(_context,mLoginHandler));
			Log.d("SDKQQAgentPref", "FirstLaunch_SDK:" + SystemClock.elapsedRealtime());
			mInfo = new UserInfo(_context, mTencent.getQQToken());
		} else {
//		    mTencent.logout(_context);
		}
    }
	

	@Override
	public void CCGameLogout(JSONObject response){
		if (isLogined()) {
			mTencent.logout(_context);
		}
	}

	private Handler mLoginHandler = new Handler() {
	    @Override
	    public void handleMessage(Message msg) {
	        switch (msg.what) {
	        case BaseUIListener.ON_COMPLETE:
				isLoading = true;
	            JSONObject response = (JSONObject)msg.obj;
	            Log.i(TAG, "onComplete:" + "登录成功");
	            initOpenidAndToken(response);
	    		JSONObject params = new JSONObject();
	    		try {
	    			params.put("result",1);
	    		} catch (JSONException e) {
	    			// TODO Auto-generated catch block
	    			e.printStackTrace();
	    		}
	    		//获取用户资料事件
	            SendMessageWithParameters("ccNd_Platform_LogonLoading", params);
	            mInfo.getUserInfo(new BaseUIListener(_context,mAccountHandler,"get_simple_userinfo"));
	            break;
	        case BaseUIListener.ON_ERROR:
	            UiError err = (UiError)msg.obj;
	            if(err!=null){
	            	Toast.makeText(Cocos2dxActivity.getContext(), err.errorMessage, Toast.LENGTH_SHORT).show();
	            }
	            Log.i(TAG,"ON_ERROR");
	            break;
	        case BaseUIListener.ON_CANCEL:
	            Log.i(TAG,"onCancel");
	            break;
	        }
	    }	    
	};
	
    public static void initOpenidAndToken(JSONObject jsonObject) {
        try {
            String token = jsonObject.getString(Constants.PARAM_ACCESS_TOKEN);
            String expires = jsonObject.getString(Constants.PARAM_EXPIRES_IN);
            if (!TextUtils.isEmpty(token) && !TextUtils.isEmpty(expires)
                    && !TextUtils.isEmpty(uuid)) {
                mTencent.setAccessToken(token, expires);
                mTencent.setOpenId(jsonObject.getString(Constants.PARAM_OPEN_ID));
            }
        } catch(Exception e) {
        	
        }
    }
    
	
	private Handler mAccountHandler = new Handler() {
	    @Override
	    public void handleMessage(Message msg) {
	    	isLoading = false;
	        switch (msg.what) {
	        case BaseUIListener.ON_COMPLETE:
	            JSONObject response = (JSONObject)msg.obj;
	            Log.i(TAG,"ON_COMPLETE:" + response.toString());
	            
	            JSONObject jUser = new JSONObject();
	            UserLoginInfo userLogoInfo = getUserLogoInfo();
	            userLogoInfo.reset();
	            uuid = mTencent.getOpenId();
				try {
					userLogoInfo.setAcccount(response.getString("nickname"));
					userLogoInfo.setAccountType((byte)SDKControl._QQAccount);
					userLogoInfo.setFaceID(uuid);
					userLogoInfo.setBigFace(response.getString("figureurl_qq_2"));
					int gender = response.getString("gender").equals( "男" ) ? 1 : 0; 
					userLogoInfo.setGender(gender);
				} catch (JSONException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				getDelegate().onLoginResulet(1);
	            break;
	        case BaseUIListener.ON_ERROR:
	        	Log.i(TAG,"ON_ERROR");
	            UiError err = (UiError)msg.obj;
	            if(err!=null){
	            	Toast.makeText(Cocos2dxActivity.getContext(), err.errorMessage, Toast.LENGTH_SHORT).show();
	            }
	            CCGameLogout(null);
	            getDelegate().onLoginResulet(0);
	            break;
	        case BaseUIListener.ON_CANCEL:
	            Log.i(TAG,"onCancel");
	            break;
	        }
	    }	    
	};
	
	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		if(this.sdkPay == null){
			this.sdkPay = getDelegate().createSDKControl("com.jt.sdk_platform_pay.SDKPay");
		}
		
		if(this.sdkPay != null){
			sdkPay.CCPay(response);
		}else{
			Toast.makeText(_context, "未接入支付sdk",Toast.LENGTH_LONG).show();
		}
	}
}
