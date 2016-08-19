package com.jt.sdk_platform_msdk;


import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;


import YYProjectJni.JniHelper;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.BroadcastReceiver;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.RemoteException;
import android.os.SystemClock;
import android.support.v4.content.LocalBroadcastManager;
import android.text.format.Time;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.example.wegame.MsdkCallback;
import com.example.wegame.PlatformTest;
import com.hjwl.newox.jpush.Jpush;
import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.user.UserLoginInfo;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask.ReadGetExecute;
import com.qp.lib.asynctask.ReadPostUrlAsyncTask;
import com.qp.lib.asynctask.ReadPostUrlAsyncTask.ReadPostExecute;
import com.qq.open.OpensnsException;
import com.qq.open.SnsSigCheck;
import com.tencent.connect.UserInfo;
import com.tencent.mm.sdk.modelmsg.SendAuth;
import com.tencent.mm.sdk.openapi.IWXAPI;
import com.tencent.mm.sdk.openapi.WXAPIFactory;
import com.tencent.msdk.WeGame;
import com.tencent.msdk.api.LoginRet;
import com.tencent.msdk.api.MsdkBaseInfo;
import com.tencent.msdk.api.TokenRet;
import com.tencent.msdk.api.WGPlatform;
import com.tencent.msdk.api.WGQZonePermissions;
import com.tencent.msdk.consts.CallbackFlag;
import com.tencent.msdk.consts.EPlatform;
import com.tencent.msdk.consts.TokenType;
import com.tencent.msdk.tools.Logger;
import com.tencent.tauth.Tencent;
import com.tencent.tmassistantbase.util.MD5;
import com.tencent.tmgp.niuox.R;
import com.tencent.unipay.plugsdk.IUnipayServiceCallBackPro;
import com.tencent.unipay.plugsdk.UnipayPlugAPI;
import com.tencent.unipay.plugsdk.UnipayResponse;
import com.tencent.unipay.request.UnipayGameRequest;
import com.tencent.unipay.request.UnipayUserInfo;


public class SDKControl extends SDKControlOriginal {
	public static final String TAG = "SDKControl";
	
	private String LANG = "java";// 开发语言 java cpp
	
	//URL
	public final static String APP_URL = "http://msdk.qq.com";
//	public final static String APP_URL = "http://msdktest.qq.com";

	public static String APP_ID = "";
	public static String APP_KEY = "";
	public static String APP_KEY_PAY = "";
	public static String wxAppId = "";
	public static String msdkKey = "";
	public static String offerId = "";
	public static String discountid = "UM160226151003720";
	public static String giftID = "65682073PID201602261510037400";
	
	static{
		if(JniHelper.getAppDebug()==0){
			//发行版
			APP_ID = "1105125571";
			APP_KEY = "WPccATx7WTCM2Je7";//现网：JIUBtL4gCB7GgigX8RF24AfPdfojNis6;沙箱：WPccATx7WTCM2Je7;
			APP_KEY_PAY = "JIUBtL4gCB7GgigX8RF24AfPdfojNis6";
			wxAppId = "wx75c8a9e911510672";
			msdkKey = "d76a46308933b358f335a001ddbc9094";
			offerId = "1105125571";
		}else{
			//MSDK
			APP_ID = "100703379";
			APP_KEY = "4578e54fb3a1bd18e0681bc1c734514e";
			APP_KEY_PAY = APP_KEY;
			wxAppId = "wxcde873f99466f74a";
			msdkKey = "5d1467a4d2866771c3b289965db335f4";
			offerId = "100703379";
		}
	}
	
	private String userId   	= "";    
    private String userKey 		= "";  
    private String sessionId 	= "";   
    private String sessionType	= "";  
    private String zoneId  		= "";   
//    private String saveValue 	= "";   
    private String pf 			= "";   
    private String pfKey		= "";  
    private String acctType     = "";  
//    private String tokenUrl     = "";
//    private int    resId        = 0;
//    private byte[] appResData = null;
	public String pay_token 	= "";
	public String orderid 	= "";
	public ProductInfoItem proItem;
	
	private boolean isFirstLogin = false;
	public LocalBroadcastManager lbm;
	public BroadcastReceiver mReceiver;
	
	private UnipayPlugAPI unipayAPI = null;
	
	private String domainURL = "";

	private int presenttimes;
	
	private SDKControlOriginal sdkPay;
	private Jpush jpush;
	
	public SDKControl(){

		Activity activity = (Activity)_context;
		
		// TODO GAME 初始化MSDK
        /***********************************************************
         *  TODO GAME 接入必须要看， baseInfo值因游戏而异，填写请注意以下说明:      
         *  	baseInfo值游戏填写错误将导致 QQ、微信的分享，登录失败 ，切记 ！！！     
         * 		只接单一平台的游戏请勿随意填写其余平台的信息，否则会导致公告获取失败  
         *      offerId 为必填，一般为手QAppId
         ***********************************************************/
        MsdkBaseInfo baseInfo = new MsdkBaseInfo();
        baseInfo.qqAppId = APP_ID;
        baseInfo.qqAppKey = APP_KEY; 
        baseInfo.wxAppId = wxAppId;
        baseInfo.msdkKey = msdkKey;
        baseInfo.offerId = offerId;
        
        // TODO GAME 自2.7.1a开始游戏可在初始化msdk时动态设置版本号，灯塔和bugly的版本号由msdk统一设置
        // 1、版本号组成 = versionName + versionCode
        // 2、游戏如果不赋值给appVersionName（或者填为""）和appVersionCode(或者填为-1)，
        // msdk默认读取AndroidManifest.xml中android:versionCode="51"及android:versionName="2.7.1"
        // 3、游戏如果在此传入了appVersionName（非空）和appVersionCode（正整数）如下，则灯塔和bugly上获取的版本号为2.7.1.271
        baseInfo.appVersionName = JniHelper.getAppVersionName();;
        baseInfo.appVersionCode = JniHelper.getAppVersionCode();
        
        // 注意：传入Initialized的activity即this，在游戏运行期间不能被销毁，否则会产生Crash
        WGPlatform.Initialized((Activity) _context, baseInfo); 
        // 设置拉起QQ时候需要用户授权的项
		WGPlatform.WGSetPermission(WGQZonePermissions.eOPEN_ALL);
        
		// 设置java层或c++层回调,如果两层都设置了则会只回调到java层
		if (LANG.equals("java")) {
			// 全局回调类，游戏自行实现
            WGPlatform.WGSetObserver(new MsdkCallback(this));
        } else {
            // cpp层 回调设置
        	PlatformTest.setObserver(true);
            PlatformTest.WGLogPlatformSDKVersion();
            PlatformTest.SetActivity(activity);
        }
		
		// MSDKDemo 界面实现
//        initView();
        
        // TODO GAME 处理游戏被拉起的情况
        // launchActivity的onCreat()和onNewIntent()中必须调用
        // WGPlatform.handleCallback()。否则会造成微信登录无回调
        if (WGPlatform.wakeUpFromHall(activity.getIntent())) {
        	// 拉起平台为大厅 
        	Logger.d("LoginPlatform is Hall");
            Logger.d(activity.getIntent());
        } else {  
        	// 拉起平台不是大厅
            Logger.d("LoginPlatform is not Hall");
            Logger.d(activity.getIntent());
            WGPlatform.handleCallback(activity.getIntent());
        }
        isFirstLogin = true;
        
		
		//自定义,引用支付包
		if(this.sdkPay == null){
			this.sdkPay = getDelegate().createSDKControl("com.jt.sdk_platform_pay.SDKPay");
		}
		
	}
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		//推送
		jpush = new Jpush((Activity) _context);
	}
	
	public void initUnipayAPI(){
		
		//支付
		unipayAPI = new UnipayPlugAPI(_context);
		setParams();
		UnipayUserInfo userInfo = new UnipayUserInfo();
		
		LoginRet lr = new LoginRet();
        WGPlatform.WGGetLoginRecord(lr);
        userInfo.userId = lr.open_id;
        
        userInfo.userKey =  userKey;
        userInfo.sessionId = sessionId;
        userInfo.sessionType = sessionType;
        
        userInfo.pf = pf;
        userInfo.pfKey =  pfKey;
        userInfo.offerid = APP_ID;
//        //调用初始化接口
        if(JniHelper.getAppDebug()==0){
        	 unipayAPI.init(userInfo, "release");
        }else{
        	unipayAPI.init(userInfo, "test");
        }
        unipayAPI.setLogEnable(true);

	}
	
	//设置支付参数
    private void setParams()
    {
    	LoginRet lr = new LoginRet();
        WGPlatform.WGGetLoginRecord(lr);
        
    	//用户ID,demo中调用即通登录模块获取，应用根据不同平台传递相应的登录id
    	userId		= lr.open_id;

    	//用户登录态,demo中从即通登录模块获取，应用根据不同平台传递相应的登录票据
    	 if (lr.platform == WeGame.WXPLATID) {
             userKey =  lr.getTokenByType(TokenType.eToken_WX_Access);
             sessionType = "wc_actoken";
             sessionId = "hy_gameid";
         } else if (lr.platform == WeGame.QQPLATID) {
        	 userKey =  lr.getTokenByType(TokenType.eToken_QQ_Pay);
             sessionType = "kp_actoken";
             sessionId =  "openid";
         }
    	
    	//游戏分区id（若无分区， 默认传1）
    	zoneId      = "1";	
    	
    	pf			=  WGPlatform.WGGetPf("");
    	
		//由平台下发，游戏传递给支付sdk,自研应用不校验，可以设置为pfKey
//		pfKey       = "877047063A36265C24233774959A0D34";
		pfKey		=   WGPlatform.WGGetPfKey();
		
		acctType	= UnipayPlugAPI.ACCOUNT_TYPE_COMMON;
		//货币类型   ACCOUNT_TYPE_COMMON:基础货币； ACCOUNT_TYPE_SECURITY:安全货币
	
		//用户的充值数额（可选，调用相应充值接口即可）
//	    saveValue   = "1";	
    } 
	
	@Override
	public byte AccountType() {
		
		if(getPlatform() == EPlatform.ePlatform_QQ){
			return _QQAccount;
		}else if(getPlatform() == EPlatform.ePlatform_Weixin){
			return _WeChatAccount;
		}

		return _QQAccount;
	};
	
	@Override
	public void CCLoginType(JSONObject response) {
		// TODO Auto-generated method stub
		JSONObject j1 = new JSONObject();
		JSONObject j2 = new JSONObject();
		try {
			j1.put("loginType",_QQAccount);
			j1.put("visible",true);
			j2.put("loginType",_WeChatAccount);
			j2.put("visible",true);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_PlatForm_LogonType",j1);
		SendMessageWithParameters("ccNd_PlatForm_LogonType",j2);
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
//		UpdateManager update = new UpdateManager(_context);
//		update.checkUpdate();
//		if(true)return;
		
		int loginType = 0;
		try {
			loginType = response.getInt("loginType");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		setAccountType(loginType);
		
		EPlatform ep = EPlatform.ePlatform_None;
		if(loginType == _QQAccount){
			ep = EPlatform.ePlatform_QQ;
		}else if(loginType == _WeChatAccount){
			ep = EPlatform.ePlatform_Weixin;
		}
		if(getPlatform() != ep){
			//调用不同登录,注销原记录
			letUserLogout();
		}
		
		if (getPlatform() == EPlatform.ePlatform_QQ && loginType == _QQAccount) {
			LoginRet ret = new LoginRet();
			WGPlatform.WGGetLoginRecord(ret);
			getUserInfo(ret);
		}else if (getPlatform() == EPlatform.ePlatform_Weixin
				&& loginType == _WeChatAccount) {
			LoginRet ret = new LoginRet();
			WGPlatform.WGGetLoginRecord(ret);
			getUserInfo(ret);
		} else if (getPlatform() == EPlatform.ePlatform_None) {
			// 调用登录
			if(loginType == _QQAccount){
				WGPlatform.WGLogin(EPlatform.ePlatform_QQ);
			}else if(loginType == _WeChatAccount){
				if(JniHelper.getAppDebug() != 0){
					Toast.makeText(_context,"当前版本非线上发行版，请选用其它登录方式", Toast.LENGTH_SHORT).show();
					return;
				}
				WGPlatform.WGLogin(EPlatform.ePlatform_Weixin);
			}
		}
    }
	
	public void letUserLogin()
	{
		LoginRet ret = new LoginRet();
        WGPlatform.WGGetLoginRecord(ret);
        Logger.d("flag: " + ret.flag);
        Logger.d("platform: " + ret.platform);
        if(ret.flag != CallbackFlag.eFlag_Succ){
    		Toast.makeText(_context, "UserLogin error!!!",
                    Toast.LENGTH_LONG).show();
    		Logger.d("UserLogin error!!!");
            letUserLogout();
            return; 
    	}
		getUserInfo(ret);
	}
	
	public void letUserLogout() {
		WGPlatform.WGLogout();
		unipayAPI = null;
//		endModule();
	}
	
	 // 获取当前登录平台
    public EPlatform getPlatform() {
        LoginRet ret = new LoginRet();
        WGPlatform.WGGetLoginRecord(ret);
        if (ret.flag == CallbackFlag.eFlag_Succ) {
            return EPlatform.getEnum(ret.platform);
        } 
        return EPlatform.ePlatform_None;
    }
    
    // 展示相应的功能模块
 	public void startModule() {
 		
 	}
    
	//获取用户信息
	public void getUserInfo(final LoginRet ret){
		
		String timestamp = System.currentTimeMillis()/1000+"";
		// 计算签名
		String sig = "";
		sig = MD5.toMD5(APP_KEY+timestamp).toLowerCase();
		String param = String.format("timestamp=%1$s&appid=%2$s&sig=%3$s&openid=%4$s&encode=1",timestamp,APP_ID,sig,ret.open_id);
		JSONObject jParam = new JSONObject();
		try {
			jParam.put("appid",APP_ID);
			jParam.put("accessToken",ret.getAccessToken());
			jParam.put("openid",ret.open_id);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		//获取微信资料
		if(getPlatform() == EPlatform.ePlatform_Weixin){
			String url = APP_URL + "/relation/wxuserinfo";
			//获取用户资料
	    	ReadPostUrlAsyncTask post = new ReadPostUrlAsyncTask(url+"?"+param,"",jParam);
			post.addReadPostExecute(new ReadPostExecute() {
				
				@Override
				public void onPostExecute(String str) {
					// TODO Auto-generated method stub
					try {
						JSONObject response = new JSONObject(str);
						if(response.getInt("ret") == 0){
							//获取成功
							UserLoginInfo userLogoInfo = getUserLogoInfo();
				            userLogoInfo.reset();
							try {
								uuid = response.getString("openid");
								userLogoInfo.setAcccount(response.getString("nickname"));
								userLogoInfo.setAccountType(_WeChatAccount);
								userLogoInfo.setFaceID(uuid);
								String pic = response.getString("picture");
								userLogoInfo.setBigFace(pic+"/132");
								int gender = Integer.parseInt(response.getString("sex"))==1 ? 1 : 0;
								userLogoInfo.setGender(gender);
								onLoginResulet(1);
							} catch (JSONException e1) {
								// TODO Auto-generated catch block
								e1.printStackTrace();
								Toast.makeText(_context,e1.getMessage(), Toast.LENGTH_LONG).show();
								onLoginResulet(0);
							}
						}else
						{
							Toast.makeText(_context, response.getString("msg"), Toast.LENGTH_LONG).show();
							onLoginResulet(0);
						}
						
					} catch (JSONException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			});
			post.execute("");
			
			return;
		}
		
		
		//获取QQ资料
    	String url = APP_URL + "/relation/qqprofile";
		
    	//获取用户资料
    	ReadPostUrlAsyncTask post = new ReadPostUrlAsyncTask(url+"?"+param,"",jParam);
		post.addReadPostExecute(new ReadPostExecute() {
			
			@Override
			public void onPostExecute(String str) {
				// TODO Auto-generated method stub
				try {
					JSONObject response = new JSONObject(str);
					if(response.getInt("ret") == 0){
						//获取成功
						UserLoginInfo userLogoInfo = getUserLogoInfo();
			            userLogoInfo.reset();
			            uuid = ret.open_id;
						try {
							userLogoInfo.setAcccount(response.getString("nickName"));
							userLogoInfo.setAccountType(_QQAccount);
							userLogoInfo.setFaceID(uuid);
							String pic = response.getString("picture100");
							if(pic.equals("")){
								pic = response.getString("picture40");
							}
							userLogoInfo.setBigFace(pic);
							int gender = response.getString("gender").equals( "男" ) ? 1 : 0; 
							userLogoInfo.setGender(gender);
							onLoginResulet(1);
						} catch (JSONException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
							onLoginResulet(0);
						}
					}else
					{
						Toast.makeText(_context, response.getString("msg"), Toast.LENGTH_LONG).show();
						onLoginResulet(0);
					}
					
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		post.execute("");
	}
	
	public String mapToString(HashMap<String, String> encodeMap) {
		StringBuffer strBuff = new StringBuffer();
		for (Map.Entry<String, String> entry : encodeMap.entrySet()) {
			strBuff.append(entry.getKey());
			strBuff.append("=");
			strBuff.append(entry.getValue());
			strBuff.append("&");
		}
		if (strBuff.length() > 0) {
			strBuff.deleteCharAt(strBuff.length() - 1);
		}
		return strBuff.toString();
	}
	
	@Override
	public void onLoginResulet(int result){
		if(result==1 && unipayAPI == null){
			initUnipayAPI();
		}
		getDelegate().onLoginResulet(result);
	}

	@Override
	public void CCGameLogout(JSONObject response){
		WGPlatform.WGLogout();
	}

	@Override
	public void CCPay(final JSONObject response) {

		if(this.sdkPay != null){
			sdkPay.CCPay(response);
			return;
		}
		
		proItem = ProductInfoItem.parseObject(response);
		
		//获取订单编号
		String OrderURL = "";
		try {
			OrderURL = response.getString("OrderURL");
			domainURL = response.getString("domainURL");
		} catch (JSONException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		ReadGetUrlAsyncTask task = new ReadGetUrlAsyncTask(OrderURL,null,null);
		task.addReadGetExecute(new ReadGetExecute() {
			
			@Override
			public void onGetExecute(String str) {
				Log.i(TAG, str);
				JSONObject jobj;
				try {
					jobj = new JSONObject(str);
					orderid = jobj.getString("result");
					LaunchPay(response);
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					Toast.makeText(_context,"支付失败:"+e.getMessage(), Toast.LENGTH_LONG).show();
				}
			}
		});
		task.execute("");
	}
	
	public void LaunchPay(JSONObject response){
		
		if(unipayAPI == null){
			initUnipayAPI();
		}
		int ratio = 10/1;//兑换比例
		int saveValue = 1;
		String Remark = "1";
		saveValue = ((int)proItem.getMoney()*ratio);
		try {
			Remark = response.getString("Remark");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		UnipayGameRequest request = new UnipayGameRequest();
		request.offerId = APP_ID;
		request.openId = userId;
		request.openKey = userKey;
		request.sessionId = sessionId;
		request.sessionType = sessionType;
		request.zoneId = zoneId;
		request.pf = pf;
		request.pfKey = pfKey;
		request.acctType = acctType;
//		request.resData =appResData;
		request.resId = R.drawable.icon_diamond;
		request.isCanChange= false;
		request.saveValue = saveValue+"";
		request.extendInfo.unit="颗";
		Log.i("TencentPay", "userId, userKey, sessionId, sessionType, zoneId, pf, pfKey, acctType" + "====" + userId + "," + userKey + "," + sessionId + "," + sessionType + "," + zoneId + "," + pf + "," + pfKey + "," + acctType);
		
		presenttimes = (int)(Integer.parseInt(Remark) - saveValue);//获取赠送数量
		if(presenttimes>=1){
			int debug = 1;
			if(debug==0){
				presentPay();
				return;
			}
		}
		
//		Toast.makeText(_context,"本地充值将花费"+proItem.getMoney()+"元得到"+saveValue+"个钻石，另外"+presenttimes+"个钻石将以赠送形式发放", Toast.LENGTH_LONG).show();
		
		unipayAPI.LaunchPay(request, unipayStubCallBack);
	}
	
	//回调接口
	IUnipayServiceCallBackPro.Stub unipayStubCallBack = new IUnipayServiceCallBackPro.Stub() {
		
		@Override
		public void UnipayNeedLogin() throws RemoteException
		{
			Log.i("UnipayPlugAPI", "UnipayNeedLogin");
			Message msg = handler.obtainMessage();
			msg.what = -1;
			msg.obj = "登录过期，请重新登录再进行购买支付";
			handler.sendMessage(msg);
		}

		@Override
		public void UnipayCallBack(UnipayResponse response)
				throws RemoteException {
			// TODO Auto-generated method stub
			Log.i("UnipayPlugAPI", "UnipayCallBack \n" + 
					"\nresultCode = " + response.resultCode + 
					"\npayChannel = "+ response.payChannel + 
					"\npayState = "+ response.payState + 
					"\nproviderState = " + response.provideState+
					"\nsavetype = "+ response.extendInfo);
			
			Message msg = handler.obtainMessage();
			msg.what = response.resultCode;
			msg.obj = response.resultMsg;
			handler.sendMessage(msg);
		}
	};
	
	Handler handler = new Handler()
	{
		public void handleMessage(Message msg)
		{
//			Toast.makeText(_context, "call back retCode=" + String.valueOf(msg.what) + " retMessage=" + msg.obj.toString(), Toast.LENGTH_SHORT).show();
			switch (msg.what) {
			case 0:
				SDKControlOriginal.getDelegate().onPayResult(3,1);
				presentPay();
//				addVipExp();
				
				break;

			default:
				SDKControlOriginal.getDelegate().onPayResult(3,0);
				break;
			}

		}
	};
	
	public void addVipExp(){
		String url = domainURL + "/cftnoticeurl.aspx";
		JSONObject jParam = new JSONObject();
		try {
			jParam.put("userid",proItem.getUserID());
			jParam.put("appid",27);
			jParam.put("productid",proItem.getProductId());
			jParam.put("orderid",orderid);
			jParam.put("transactionid","");
		} catch (JSONException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		ReadPostUrlAsyncTask post = new ReadPostUrlAsyncTask(url,"",jParam);
		post.addReadPostExecute(new ReadPostExecute() {
			
			@Override
			public void onPostExecute(String str) {
				Log.i(TAG, str);
				JSONObject jobj;
				int state = 1;
				try {
					jobj = new JSONObject(str);
					state = jobj.getInt("state");
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				if(state!=0){
					Toast.makeText(_context, "VIP经验添加失败", Toast.LENGTH_LONG).show();
				}
			}
		});
		post.execute("");
	}
	
	public void getBalance()
	{
		String url = APP_URL + "/mpay/get_balance_m";
		String org_loc = "/mpay/get_balance_m";
		String cookie = String.format("session_id=%1$s;session_type=%2$s;org_loc=%3$s",sessionId,sessionType,org_loc);
		String ts = System.currentTimeMillis()/1000+"";
		HashMap<String,String> jParam = new HashMap<String, String>();
		jParam.put("openid",userId);
		jParam.put("openkey",userKey);
		jParam.put("pay_token",pay_token);
		jParam.put("appid",APP_ID);
		jParam.put("ts",ts);
		jParam.put("pf",pf);
		jParam.put("pfkey",pfKey);
		jParam.put("zoneid",zoneId);
		// 签名密钥
        HashMap<String, String> params = jParam;
        
//		String secret = APP_KEY + "&";
		String secret = APP_KEY_PAY + "&";
		// 计算签名
		String sig = "";
		try {
			sig = SnsSigCheck.makeSig("GET", "/mpay/get_balance_m", params,
					secret);
			sig = SnsSigCheck.encodeUrl(sig);
		} catch (OpensnsException e) {
			e.printStackTrace();
		}
		jParam.put("sig",sig);
		String p = mapToString(jParam);
		Log.i(TAG, p);
		ReadGetUrlAsyncTask task = new ReadGetUrlAsyncTask(url+"?"+p,null,cookie);
		task.addReadGetExecute(new ReadGetExecute() {
			
			@Override
			public void onGetExecute(String str) {
				// TODO Auto-generated method stub
				JSONObject jobj = new JSONObject();
				try {
					jobj.put("result",0);
					jobj.put("mainType",3);
					jobj.put("subType",524);
					
					JSONObject response = new JSONObject(str);
					int result = response.getInt("ret");
					if(result == 0){
						String balance = response.getString("balance");
						jobj.put("balance", balance);
						jobj.put("result",1);
					}else{
						Toast.makeText(_context, "获取余额失败:"+response.getString("msg"), Toast.LENGTH_LONG).show();
					}
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				SendMessageWithParameters("ccNd_Notify",jobj);
			}
		});
		task.execute("");
	}
	
	// 支付兑换
	public void payBalance(final JSONObject response) {
		
		String amt = "1";
		String userid = "";
		try {
			userid = response.getString("userid");
			domainURL = response.getString("domainURL");
			amt = response.getString("amt");
		} catch (JSONException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

//		String url = APP_URL + "/mpay/pay_m";
		String url = domainURL+"/cfttoscore.aspx";
		String org_loc = "/mpay/pay_m";
		String cookie = String.format(
				"session_id=%1$s;session_type=%2$s;org_loc=%3$s", sessionId,
				sessionType, org_loc);
		String ts = System.currentTimeMillis() / 1000 + "";
		HashMap<String, String> jParam = new HashMap<String, String>();

		// 自定义参数
		jParam.put("userid", userid);
		jParam.put("sessionid", sessionId);
		jParam.put("sessiontype", sessionType);
		
		// sdk参数
		jParam.put("openid", userId);
		jParam.put("openkey", userKey);
		jParam.put("pay_token", pay_token);
		jParam.put("appid", APP_ID);
		jParam.put("ts", ts);
		jParam.put("pf", pf);
		jParam.put("zoneid", zoneId);
		jParam.put("amt", amt);
		jParam.put("pfkey", pfKey);
		jParam.put("billno", getOutTradeNo(userid));
		
		// 签名密钥
		HashMap<String, String> params = jParam;

//		String secret = APP_KEY + "&";
		String secret = APP_KEY_PAY + "&";
		
		// 计算签名
		String sig = "";
		try {
			sig = SnsSigCheck.makeSig("GET", "/mpay/pay_m", params, secret);
			sig = SnsSigCheck.encodeUrl(sig);
		} catch (OpensnsException e) {
			e.printStackTrace();
		}
		jParam.put("sig", sig);
		
		String p = mapToString(jParam);
		Log.i(TAG, p);
		
		ReadGetUrlAsyncTask task = new ReadGetUrlAsyncTask(url+"?"+p, null,
				cookie);
		task.addReadGetExecute(new ReadGetExecute() {

			@Override
			public void onGetExecute(String str) {
				// TODO Auto-generated method stub
				JSONObject jobj = response;// new JSONObject();
				try {
					jobj.put("result", 0);

					JSONObject response = new JSONObject(str);
					int result = response.getInt("ret");

					if (result == 0) {
						String balance = response.getString("balance");
						jobj.put("balance", balance);
						jobj.put("newscore",response.getString("newscore"));
						jobj.put("result", 1);
						getBalance();
					} else {
						jobj.put("msg", response.getString("msg"));
						// Toast.makeText(_context,
						// "兑换失败："+response.getString("msg"),
						// Toast.LENGTH_LONG).show();
					}
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					 Toast.makeText(_context,
					 "获取数据失败："+e.getMessage(),
					 Toast.LENGTH_LONG).show();
				}
				SendMessageWithParameters("ccNd_Notify", jobj);
			}
		});
		task.execute("");
	}
	
	public void cancelPay(final JSONObject response){

		String amt = "1";
		String userid = "";
		try {
			userid = response.getString("userid");
			domainURL = response.getString("domainURL");
			amt = response.getString("amt");
		} catch (JSONException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}

		String url = APP_URL + "/mpay/cancel_pay_m";
		String org_loc = "/mpay/cancel_pay_m";
		String cookie = String.format(
				"session_id=%1$s;session_type=%2$s;org_loc=%3$s", sessionId,
				sessionType, org_loc);
		String ts = System.currentTimeMillis() / 1000 + "";
		HashMap<String, String> jParam = new HashMap<String, String>();

		// 自定义参数
//		jParam.put("userid", userid);
//		jParam.put("sessionid", sessionId);
//		jParam.put("sessiontype", sessionType);
		
		// sdk参数
		jParam.put("openid", userId);
		jParam.put("openkey", userKey);
		jParam.put("pay_token", pay_token);
		jParam.put("appid", APP_ID);
		jParam.put("ts", ts);
		jParam.put("pf", pf);
		jParam.put("zoneid", zoneId);
		jParam.put("amt", amt);
		jParam.put("pfkey", pfKey);
		
		String billno = getOutTradeNo(userid);
		jParam.put("billno", billno);
		
		// 签名密钥
		HashMap<String, String> params = jParam;

//		String secret = APP_KEY + "&";
		String secret = APP_KEY_PAY + "&";
		
		// 计算签名
		String sig = "";
		try {
			sig = SnsSigCheck.makeSig("GET", org_loc, params, secret);
			sig = SnsSigCheck.encodeUrl(sig);
		} catch (OpensnsException e) {
			e.printStackTrace();
		}
		jParam.put("sig", sig);
		
		String p = mapToString(jParam);
		Log.i(TAG, p);
		
		ReadGetUrlAsyncTask task = new ReadGetUrlAsyncTask(url+"?"+p, null,
				cookie);
		task.addReadGetExecute(new ReadGetExecute() {

			@Override
			public void onGetExecute(String str) {
				// TODO Auto-generated method stub
				JSONObject jobj = response;// new JSONObject();
				try {
					jobj.put("result", 0);

					JSONObject response = new JSONObject(str);
					int result = response.getInt("ret");

					if (result == 0) {
						String balance = response.getString("balance");
						jobj.put("balance", balance);
//						jobj.put("newscore",response.getString("newscore"));
						jobj.put("result", 1);
						getBalance();
					} else {
						jobj.put("msg", response.getString("msg"));
					}
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					 Toast.makeText(_context,
					 "获取数据失败："+e.getMessage(),
					 Toast.LENGTH_LONG).show();
				}
				SendMessageWithParameters("ccNd_Notify", jobj);
			}
		});
		task.execute("");
	}
	
	public void presentPay(){
		
//		String url = APP_URL + "/mpay/present_m";
		String url = domainURL+"/cfgifturl.aspx";
		String org_loc = "/mpay/present_m";
		String cookie = String.format(
				"session_id=%1$s;session_type=%2$s;org_loc=%3$s", sessionId,
				sessionType, org_loc);
		String ts = System.currentTimeMillis() / 1000 + "";
		HashMap<String, String> jParam = new HashMap<String, String>();

		// 自定义参数
		jParam.put("userid",proItem.getUserID()+"");
		jParam.put("sessionid", sessionId);
		jParam.put("sessiontype", sessionType);
		jParam.put("productid",proItem.getProductId());
		
		// sdk参数
		jParam.put("openid", userId);
		jParam.put("openkey", userKey);
		jParam.put("pay_token", pay_token);
		jParam.put("appid", APP_ID);
		jParam.put("ts", ts);
		jParam.put("pf", pf);
		jParam.put("zoneid", zoneId);
		jParam.put("pfkey", pfKey);
		jParam.put("billno",orderid);
		jParam.put("discountid",discountid);
		jParam.put("giftid",giftID);
		jParam.put("presenttimes",(presenttimes)+"");
		
		// 签名密钥
		HashMap<String, String> params = jParam;

//		String secret = APP_KEY + "&";
		String secret = APP_KEY_PAY + "&";
		
		// 计算签名
		String sig = "";
		try {
			sig = SnsSigCheck.makeSig("GET", org_loc, params, secret);
			sig = SnsSigCheck.encodeUrl(sig);
		} catch (OpensnsException e) {
			e.printStackTrace();
		}
		jParam.put("sig", sig);
		
		String p = mapToString(jParam);
		Log.i(TAG, p);
		
		ReadGetUrlAsyncTask task = new ReadGetUrlAsyncTask(url+"?"+p, null,
				cookie);
		task.addReadGetExecute(new ReadGetExecute() {

			@Override
			public void onGetExecute(String str) {
				// TODO Auto-generated method stub
//				Toast.makeText(_context, str,Toast.LENGTH_LONG).show();
				JSONObject jobj = new JSONObject();
				try {
					
					JSONObject response = new JSONObject(str);

					if(presenttimes==0){
						//没有赠送，服务器直接返回当前VIP经验值，重新查询当前钻石数量
						getBalance();
						return;
					}

					jobj.put("result", 0);
					jobj.put("mainType",3);
					jobj.put("subType",524);
					int ret = response.getInt("ret");
					if (ret == 0) {
						String balance = response.getString("balance");
						jobj.put("balance", balance);
						jobj.put("result", 1);
//						getBalance();
					} else {
						jobj.put("msg", response.getString("msg"));
					}
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					 Toast.makeText(_context,
					 "获取数据失败："+e.getMessage(),
					 Toast.LENGTH_LONG).show();
				}
				SendMessageWithParameters("ccNd_Notify", jobj);
			}
		});
		task.execute("");
	}
	
	/**
	 * get the out_trade_no for an order. 生成商户订单号，该值在商户端应保持唯一（可自定义格式规范）
	 * 
	 */
	public String getOutTradeNo(String userid) {
		SimpleDateFormat format = new SimpleDateFormat("MMddHHmmss");
		Date date = new Date();
//		String key = date.getTime()+"";
		String key = format.format(date);

		java.util.Random r = new java.util.Random();
		key += Math.abs(r.nextLong());
		key = key.substring(0, 15);
		Log.d(TAG, "outTradeNo: " + key);
		return key + "UID-" + userid;
	}
	
	public void CCNotify(JSONObject response){
		Logger.d("CCNotify");
		int mainType = -1;
		int subType = -1;
		try {
			mainType = response.getInt("mainType");
			subType = response.getInt("subType");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		switch (mainType) {
		case 3://用户服务
			OnSendMDMGPUserService(subType,response);
			break;
		case 5://银行命令
			OnSendGRBankInsure(subType,response);
			break;
			
		default:
			break;
		}
	}
	
	public void OnSendMDMGPUserService(int subType,JSONObject response){
		switch (subType) {
		case 524://                         查询购买商品
			getBalance();
			break;
		default:
			break;
		}
	}
	
	public void OnSendGRBankInsure(int subType,JSONObject response){
		switch (subType) {
		case 47:							 //钻石换金币
			int i = 0;
			if(i==0){
				payBalance(response);
			}else if(i==1){
				cancelPay(response);
			}else if(i==2){
				
			}
				
			break;

		default:
			break;
		}
	}
	
	public void onDestroy() {
		letUserLogout();
		WGPlatform.onDestory((Activity)_context);
        Logger.d("onDestroy");
        if(lbm != null) {
        	lbm.unregisterReceiver(mReceiver);
        }
	}
	
	public void onActivityResult(int requestCode, int resultCode, Intent data){
		WGPlatform.onActivityResult(requestCode, resultCode, data);
		Logger.d("onActivityResult");
	};
	
	public void onRestart() {
		WGPlatform.onRestart();
	};
	
	public void onResume() {
		WGPlatform.onResume();
		jpush.onResume((Activity) _context);
	};
	
	public void onPause() {
		 WGPlatform.onPause();
		 jpush.onPause((Activity) _context);
	};
	
	public void onStop() {
		WGPlatform.onStop();
	};
	
	public void onNewIntent(Intent intent) {
		 Logger.d("onNewIntent");
		 // TODO GAME 处理游戏被拉起的情况
        // launchActivity的onCreat()和onNewIntent()中必须调用
        // WGPlatform.handleCallback()。否则会造成微信登录无回调
        if (WGPlatform.wakeUpFromHall(intent)) {
            Logger.d("LoginPlatform is Hall");
            Logger.d(intent);
        } else {
            Logger.d("LoginPlatform is not Hall");
            Logger.d(intent);
            WGPlatform.handleCallback(intent);
        }
	};
	
}
