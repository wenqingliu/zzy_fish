package com.jt.sdk_platform_wandoujia;


import java.util.HashMap;
import java.util.UUID;

import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.webkit.WebView.FindListener;
import android.widget.Toast;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate.OrderListener;
import com.jt.user.UserLoginInfo;
import com.wandoujia.mariosdk.plugin.api.api.WandouGamesApi;
import com.wandoujia.mariosdk.plugin.api.model.callback.OnLoginFinishedListener;
import com.wandoujia.mariosdk.plugin.api.model.callback.OnLogoutFinishedListener;
import com.wandoujia.mariosdk.plugin.api.model.callback.OnPayFinishedListener;
import com.wandoujia.mariosdk.plugin.api.model.model.LoginFinishType;
import com.wandoujia.mariosdk.plugin.api.model.model.LogoutFinishType;
import com.wandoujia.mariosdk.plugin.api.model.model.PayResult;
import com.wandoujia.mariosdk.plugin.api.model.model.UnverifiedPlayer;
import com.wandoujia.mariosdk.plugin.api.model.model.WandouPlayer;
public class SDKControl extends com.jt.sdk_platform_base.SDKControlOriginal {
	private String TAG = "wandoujiaSDK";
	private String token = "";

    private static final long APP_KEY = 100037712;//100000225; // 100008237;
    private static final String SECURITY_KEY = "1d1d58d27c40911ad7c07dd5269420fe";// "9e45e1d5cfcd2ad21f86c1b43a12b3d8"; //"10159606448b775c8de9d0e79a4bfff3";
    
    private String productName = "";
    private long productPrice = 0;
    
    private static WandouGamesApi wandouGamesApi;
	public SDKControl(){
		/** SDK��ʼ�� */

	    WandouGamesApi.initPlugin(_context, APP_KEY, SECURITY_KEY);
	    
	    wandouGamesApi = new WandouGamesApi.Builder(_context, APP_KEY, SECURITY_KEY).create();
	    wandouGamesApi.setLogEnabled(true);
	    
		wandouGamesApi.init((Activity) _context);
	}
	
	@Override
	public byte AccountType() {
		return (byte) _WandoujiaAccount;
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
    	// ����SDKִ�е�½����
    	OnLoginFinishedListener loginCallBack = new OnLoginFinishedListener(){
    		@Override
    		public void onLoginFinished(LoginFinishType type, UnverifiedPlayer player){
    			if(player==null){
    				Log.i(TAG, type.toString());
    				return;
    			}
    			uuid = player.getId();
    			token = player.getToken();
    			WandouPlayer wandouplayer = wandouGamesApi.getCurrentPlayerInfo();
    			String id = wandouplayer.getId();
    			String name = wandouplayer.getNick();
    			
	            UserLoginInfo userLogoInfo = getUserLogoInfo();
	            userLogoInfo.reset();
				userLogoInfo.setAcccount(name);
				userLogoInfo.setAccountType((byte)SDKControl._WandoujiaAccount);
				userLogoInfo.setFaceID(uuid);
				userLogoInfo.setGender(0);
				getDelegate().onLoginResulet(1);
    		}
    	};
    	wandouGamesApi.login(loginCallBack);
	}
	@Override
	public void CCGameLogout(JSONObject response){
    	OnLogoutFinishedListener loginCallBack = new OnLogoutFinishedListener(){
			@Override
			public void onLoginFinished(LogoutFinishType finishType) {
				// TODO Auto-generated method stub
				
			}
    	};
    	wandouGamesApi.logout(loginCallBack);
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
		productName = product_name;
		productPrice = (long) (Float.parseFloat(product_price)*100); //转化分为单位
		if (JniHelper.getAppDebug()!= 0) {
			productPrice = 1;
		}
//		productPrice = 1;
		getDelegate().getOrderInfo(response, new OrderListener() {
			
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub
				wandouGamesApi.pay((Activity) _context, productName, productPrice, order, new OnPayFinishedListener() {
					
					@Override
					public void onPaySuccess(PayResult result) {
						// TODO Auto-generated method stub
						if (result.getSuccess()) {
							getDelegate().onPayResult(-1,1);
						}else {
							getDelegate().onPayResult(-1,0);
						}
						
					}
					
					@Override
					public void onPayFail(PayResult result) {
						// TODO Auto-generated method stub
						getDelegate().onPayResult(-1,0);
					}
				});
			}
		});
	}
	
	@Override
	public void onResume(){
		super.onResume();
		Log.i(TAG, "===wandoujia onResume is called===");
		wandouGamesApi.onResume((Activity) _context);
	}
	
	@Override
	public void onPause() {
		super.onPause();
		Log.i(TAG, "===wandoujia onPause is called===");
		wandouGamesApi.onPause((Activity) _context);
	}
	
}
