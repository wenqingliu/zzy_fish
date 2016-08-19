package com.jt.sdk_platform_wechat;


import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.util.Log;
import android.widget.Toast;

import com.hjwl.newoxqq.R;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.user.UserLoginInfo;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask.ReadGetExecute;
import com.tencent.mm.sdk.modelmsg.SendAuth;
import com.tencent.mm.sdk.openapi.IWXAPI;
import com.tencent.mm.sdk.openapi.WXAPIFactory;


public class SDKControl extends SDKControlOriginal {
	public static final String TAG = "SDKControl";
	
	private IWXAPI api = null;
	
	private SDKControlOriginal sdkPay;
	
	@Override
	public byte AccountType() {
		return (byte) _WeChatAccount;
	};
	
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
	public boolean isLogined() {
		// 用户登陆方式
		UserLoginInfo userLogoInfo = getUserLogoInfo();
		if(userLogoInfo.getFaceID() != null && userLogoInfo.getFaceID().length() > 2){
			return true;
		}else{
			return false;
		}
	}

	@Override
    public void CCGameLogin(JSONObject response){
		if(JniHelper.getAppDebug() != 0){
			Toast.makeText(_context,((Activity)_context).getString(R.string.no_release), Toast.LENGTH_SHORT).show();
			return;
		}
		
    	setAccountType(AccountType());
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
    	if(api == null){
    		api = WXAPIFactory.createWXAPI(_context, Constants.APP_ID);
    		api.registerApp(Constants.APP_ID);
    	}
    	
    	boolean isWXAppInstalled = api.isWXAppInstalled() && api.isWXAppSupportAPI();
		if (!isWXAppInstalled) {
			Toast.makeText(_context, ((Activity)_context).getString(R.string.no_install_wechat),Toast.LENGTH_SHORT).show();
			return;
		}
    	
    	//拉起微信打开授权登录页,返回见WXEntryActivity类
    	final SendAuth.Req req = new SendAuth.Req();
		req.scope = "snsapi_userinfo";
		req.state = "wechat_sdk_NiuOxCC";
		api.sendReq(req);
    	
    }
	
	//通过code获取token
	public static void getAccessToken(String code){
		String url = String.format("https://api.weixin.qq.com/sns/oauth2/access_token?appid=%1$s&secret=%2$s&code=%3$s&grant_type=authorization_code",Constants.APP_ID,Constants.SECRET,code);
		Log.i(TAG, url);
		ReadGetUrlAsyncTask readGetUrlAsyncTask = new ReadGetUrlAsyncTask(url);
		readGetUrlAsyncTask.addReadGetExecute(new ReadGetExecute() {
			
			@Override
			public void onGetExecute(String str) {
				// TODO Auto-generated method stub
				Log.i(TAG, str);
				getUserInfo(str);
			}
		});
		readGetUrlAsyncTask.execute("");
	}
	
	//获取用户信息
	public static void getUserInfo(String str){
		String token = "";
		String openid = "";
		try {
			JSONObject jobj = new JSONObject(str);
			token = jobj.getString("access_token");
			openid = jobj.getString("openid");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		String url = String.format("https://api.weixin.qq.com/sns/userinfo?access_token=%1$s&openid=%2$s",token,openid);
		Log.i(TAG,url);
		ReadGetUrlAsyncTask readGetUrlAsyncTask = new ReadGetUrlAsyncTask(url);
		readGetUrlAsyncTask.addReadGetExecute(new ReadGetExecute() {
			@Override
			public void onGetExecute(String str) {
				Log.i(TAG, str);
				try {
					JSONObject jobj = new JSONObject(str);
					UserLoginInfo userLogoInfo = getUserLogoInfo();
					userLogoInfo.setAccountType(_WeChatAccount);
					userLogoInfo.setAcccount(jobj.getString("nickname"));
					userLogoInfo.setFaceID(jobj.getString("openid"));
					userLogoInfo.setGender(jobj.getInt("sex") == 1 ? 1 : 0);
					userLogoInfo.setBigFace(jobj.getString("headimgurl"));
					uuid = getUserLogoInfo().getFaceID();
					getDelegate().onLoginResulet(1);//登录成功
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					getDelegate().onLoginResulet(0);//登录失败
				}
			}
		});
		readGetUrlAsyncTask.execute("");
	}
	

	@Override
	public void CCGameLogout(JSONObject response){
		
	}

	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		if(this.sdkPay == null){
			this.sdkPay = getDelegate().createSDKControl("com.jt.sdk_platform_pay.SDKPay");
		}
		
		if(this.sdkPay != null){
			sdkPay.CCPay(response);
		}else{
			Toast.makeText(_context, "未接入支付",Toast.LENGTH_LONG).show();
		}
	}

}
