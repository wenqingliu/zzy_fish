package com.jt.sdk_platform_base;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;

import com.easyndk.classes.AndroidNDKHelper;
import com.jt.user.UserLoginDBManager;
import com.jt.user.UserLoginInfo;

import android.app.Activity;
import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.View;

public abstract class SDKControlOriginal {
	public static final int _GuestAccount = 0;//游客
	public static final int _QQAccount = 1;//应用宝
	public static final int _SinaAccount = 2;//新浪
	public static final int _GameAccount = 3;//普通帐号
	public static final int _91Account = 4;//91平台
	public static final int _WeChatAccount = 5;//微信
	public static final int _360Account = 6;//360
	public static final int _FeitionAccount = 7;//飞信
	public static final int _PasswordGame = 8;//口令
	public static final int _XiaoMiAccount = 9;//小米
	public static final int _UCAccount = 10;//UC
	public static final int _LetvAccount = 11;//乐视
	public static final int _MeizuAccount = 12;//魅族
	public static final int _WandoujiaAccount = 13;//豌豆荚
	public static final int _UUCAccount = 14;//UUC
	public static final int _UUMonAccount = 15;//UU盟
	public static final int _SamsungAccount = 16;//三星
	public int AccountType = _GameAccount;
	
	protected static SDKDelegate instance;
	protected static UserLoginInfo userLoginInfo;
	public static String uuid = "";

	public Context _context;
	
	protected SDKControlOriginal() {
		_context = Cocos2dxActivity.getContext();
	}
	
	public static void setDelegate(SDKDelegate sdk){
		instance = sdk;
	}
	
	public static SDKDelegate getDelegate(){
		return instance;
	}

	public boolean isLogined(){return false;};
	
	public void onPayResult(int type,int result){};

	public abstract byte AccountType();
	
	public void onLoginResulet(int result){};

	public void ccNd_PlatFormNotify(JSONObject response){};

	
	
	public abstract void CCGameLogin(JSONObject response);
	
	public abstract void CCPay(JSONObject response);

	public void CCLoginType(JSONObject response){};

	public void CCShare(JSONObject response){};
	
	public void CCInvite(JSONObject response){};
	
	public void CCNotify(JSONObject response){};
	
	public Boolean CCQueryExitGame(JSONObject response) {
		return false;
	}
	
	//生命周期start
	public void onCreate(Bundle savedInstanceState) {}
	
	public void onDestroy() {}
	
	public void onActivityResult(int requestCode, int resultCode, Intent data){};
	
	public void onRestart() {};
	
	public void onResume() {};
	
	public void onPause() {};
	
	public void onStop() {};
	
	public void onNewIntent(Intent intent) {};
	//生命周期end
	

	public static UserLoginInfo getUserLogoInfo(){
		if(userLoginInfo == null){
			userLoginInfo = new UserLoginInfo();
		}
		return userLoginInfo;
	}

	public void setAccountType(int code) {
		AccountType = code;
	}

	public void CCGameLogout(JSONObject response){
		getUserLogoInfo().reset();
		UserLoginDBManager.getInstance(Cocos2dxActivity.getContext()).updateAllNoAutoLogin();
	};
	
	public boolean saveLogin(){
		UserLoginInfo 	userLogoInfo = getUserLogoInfo();
		long res = -1;
		if(userLogoInfo!=null && userLogoInfo.getAcccount() !=null && userLogoInfo.getPassword() != null)
		{
			String id = userLogoInfo.getFaceID();
			res = UserLoginDBManager.getInstance(Cocos2dxActivity.getContext()).
					insertAutoLogin(userLogoInfo.getAcccount(),userLogoInfo.getPassword(),id,AccountType(),userLogoInfo.getBigFace(),userLogoInfo.getGender());
		}
		return res>0;
	}
	
	public boolean isAutoLogin(Context context){
		UserLoginInfo info= UserLoginDBManager.getInstance(context).queryisAutoLogin(AccountType());
		if(info==null)
			return false;
		else
		{	UserLoginInfo userLogoInfo = getUserLogoInfo();
			userLogoInfo.reset();
			userLogoInfo.setPassword(info.password);
			userLogoInfo.setAcccount(info.acccount);
//			userLogoInfo.setDefaultFace(info.faceID);
			userLogoInfo.setFaceID(info.faceID);//UUID
			userLogoInfo.setAccountType((byte)info.AccountType);
			userLogoInfo.setBigFace(info.bigFace);
			userLogoInfo.setGender(info.gender);
			return true;
		}
	}
	
	/**
	 * 发送至C++方法
	 * @param methodToCall 回调方法
	 * @param paramList 参数
	 */
	public void SendMessageWithParameters(final String methodToCall,final JSONObject paramList){
		try {
			paramList.put("methodToCall", methodToCall);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		((Activity)Cocos2dxActivity.getContext()).runOnUiThread(new Runnable() {
			public void run() {
				AndroidNDKHelper.SendMessageWithParameters(methodToCall, paramList);
			}
		});
	}
}
