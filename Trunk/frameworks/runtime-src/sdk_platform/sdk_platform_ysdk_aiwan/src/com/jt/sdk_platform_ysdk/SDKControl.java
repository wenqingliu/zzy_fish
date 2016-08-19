package com.jt.sdk_platform_ysdk;


import java.io.ByteArrayOutputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.Logger;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;


import YYProjectJni.JniHelper;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.BroadcastReceiver;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
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

import com.hjwl.newox.jpush.Jpush;
import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate;
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
import com.tencent.tmgp.niuox.aiwan.R;
import com.tencent.tmgp.yybtestsdk.PlatformTest;
import com.tencent.tmgp.yybtestsdk.YSDKCallback;
import com.tencent.unipay.plugsdk.IUnipayServiceCallBackPro;
import com.tencent.unipay.plugsdk.UnipayPlugAPI;
import com.tencent.unipay.plugsdk.UnipayResponse;
import com.tencent.unipay.request.UnipayGameRequest;
import com.tencent.unipay.request.UnipayUserInfo;
import com.tencent.ysdk.api.YSDKApi;
import com.tencent.ysdk.framework.common.eFlag;
import com.tencent.ysdk.framework.common.ePlatform;
import com.tencent.ysdk.module.pay.PayListener;
import com.tencent.ysdk.module.pay.PayRet;
import com.tencent.ysdk.module.user.PersonInfo;
import com.tencent.ysdk.module.user.UserLoginRet;


public class SDKControl extends SDKControlOriginal {
	public static final String TAG = "SDKControl";
	public static final String LOG_TAG = "SDKControl";
	
	private String LANG = "java";// 开发语言 java cpp
	
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
	
	private int nRecharge = -1;//是否点击充值
	private int currentBalance = 0;
	
	public SDKControl(){

		YSDKApi.onCreate((Activity)_context);
		 // TODO GAME 游戏需自行检测自身是否重复, 检测到吃重复的Activity则要把自己finish掉
        // 注意：游戏需要加上去重判断finish重复的实例，否则可能发生重复拉起游戏的问题。游戏可自行决定重复的判定。
        if (YSDKApi.isDifferentActivity((Activity)_context)) {
            Log.d(TAG,"Warning!Reduplicate game activity was detected.Activity will finish immediately.");
            ((Activity)_context).finish();
            return;
        }

        YSDKApi.onCreate((Activity)_context);

        // 设置java层或c++层回调,如果两层都设置了则会只回调到java层
        if (LANG.equals("java")) {
            // 全局回调类，游戏自行实现
            YSDKApi.setUserListener(new YSDKCallback(this));
            YSDKApi.setBuglyListener(new YSDKCallback(this));
        } else {
            com.tencent.tmgp.yybtestsdk.PlatformTest.setActivity((Activity)_context);
        }

        // YSDKDemo 界面实现

        // TODO GAME 处理游戏被拉起的情况
        // launchActivity的onCreat()和onNewIntent()中必须调用
        Log.d(LOG_TAG,"LoginPlatform is not Hall");
        YSDKApi.handleIntent(((Activity)_context).getIntent());
		
		//自定义,引用支付包
		if(JniHelper.getSDKPlatform() != _QQAccount && this.sdkPay == null){
			this.sdkPay = getDelegate().createSDKControl("com.jt.sdk_platform_pay.SDKPay");
		}
	}
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
	}
	
	public void initUnipayAPI(){
		
		//支付
		unipayAPI = new UnipayPlugAPI(_context);
		setParams();
		UnipayUserInfo userInfo = new UnipayUserInfo();
		
		UserLoginRet lr = new UserLoginRet();
        YSDKApi.getLoginRecord(lr);
        userInfo.userId = lr.open_id;
        
        userInfo.userKey =  userKey;
        userInfo.sessionId = sessionId;
        userInfo.sessionType = sessionType;
        
        userInfo.pf = pf;
        userInfo.pfKey =  pfKey;
        userInfo.offerid = Constants.APP_ID;
//        //调用初始化接口
        if(JniHelper.getAppDebug()==0){
        	 unipayAPI.init(userInfo, "release");
        }else{
        	unipayAPI.init(userInfo, "test");
        }
        unipayAPI.setLogEnable(true);
        
        //默认产品值
        proItem = new ProductInfoItem();
        orderid = "0";
        proItem.setProductId("0");
        proItem.setRemark("");
        proItem.setDesc("");
        proItem.setDomainURL(Constants.APP_URL);
        proItem.setProductName("");
	}
	
	//设置支付参数
    private void setParams()
    {
    	UserLoginRet lr = new UserLoginRet();
        YSDKApi.getLoginRecord(lr);
        
    	//用户ID,demo中调用即通登录模块获取，应用根据不同平台传递相应的登录id
    	userId		= lr.open_id;

    	//用户登录态,demo中从即通登录模块获取，应用根据不同平台传递相应的登录票据
    	 if (lr.platform == ePlatform.PLATFORM_ID_WX) {
             userKey =  lr.getPayToken();//待编辑?
             sessionType = "wc_actoken";
             sessionId = "hy_gameid";
         } else if (lr.platform == ePlatform.PLATFORM_ID_QQ) {
        	 userKey =  lr.getPayToken();//待编辑?
             sessionType = "kp_actoken";
             sessionId =  "openid";
         }
    	
    	//游戏分区id（若无分区， 默认传1）
    	zoneId      = "1";	
    	
    	pf			=  lr.pf;
    	
		//由平台下发，游戏传递给支付sdk,自研应用不校验，可以设置为pfKey
//		pfKey       = "877047063A36265C24233774959A0D34";
		pfKey		=   lr.pf_key;
		
		acctType	= UnipayPlugAPI.ACCOUNT_TYPE_COMMON;
		//货币类型   ACCOUNT_TYPE_COMMON:基础货币； ACCOUNT_TYPE_SECURITY:安全货币
	
		//用户的充值数额（可选，调用相应充值接口即可）
//	    saveValue   = "1";	
    } 
	
	@Override
	public byte AccountType() {
		
		if(getPlatform() == ePlatform.QQ){
			return _QQAccount;
		}else if(getPlatform() == ePlatform.WX){
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
		
		int loginType = 0;
		try {
			loginType = response.getInt("loginType");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		setAccountType(loginType);
		
		ePlatform ep = ePlatform.None;
		if(loginType == _QQAccount){
			ep = ePlatform.QQ;
		}else if(loginType == _WeChatAccount){
			ep = ePlatform.WX;
		}
		if(getPlatform() != ep){
			//调用不同登录,注销原记录
			letUserLogout();
		}
		
		if (getPlatform() == ePlatform.QQ && loginType == _QQAccount) {
			UserLoginRet ret = new UserLoginRet();
			YSDKApi.getLoginRecord(ret);
			getUserInfo(ret);
		}else if (getPlatform() == ePlatform.WX
				&& loginType == _WeChatAccount) {
			UserLoginRet ret = new UserLoginRet();
			YSDKApi.getLoginRecord(ret);
			getUserInfo(ret);
		} else if (getPlatform() == ePlatform.None) {
			// 调用登录
			if(loginType == _QQAccount){
				YSDKApi.login(ePlatform.QQ);
			}else if(loginType == _WeChatAccount){
				if(JniHelper.getAppDebug() != 0){
					Toast.makeText(_context,"当前版本非线上发行版，请选用其它登录方式", Toast.LENGTH_SHORT).show();
					return;
				}
				YSDKApi.login(ePlatform.WX);
			}
		}
    }
	
	public void letUserLogin()
	{
		UserLoginRet ret = new UserLoginRet();
		YSDKApi.getLoginRecord(ret);
        Log.d(TAG,"flag: " + ret.flag);
        Log.d(TAG,"platform: " + ret.platform);
        if(ret.flag != eFlag.Succ){
    		Toast.makeText(_context, "UserLogin error!!!",
                    Toast.LENGTH_LONG).show();
    		Log.d(TAG,"UserLogin error!!!");
            letUserLogout();
            return; 
    	}
		getUserInfo(ret);
	}
	
	public void letUserLogout() {
		YSDKApi.logout();
		unipayAPI = null;
//		endModule();
	}
	
	// TODO GAME 在异账号时，模拟游戏弹框提示用户选择登陆账号
    public void showDiffLogin() {
        ((Activity)_context).runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AlertDialog.Builder builder = new AlertDialog.Builder(_context);
                builder.setTitle("异账号提示");
                builder.setMessage("你当前拉起的账号与你本地的账号不一致，请选择使用哪个账号登陆：");
                builder.setPositiveButton("本地账号",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog,
                                                int whichButton) {
                                Toast.makeText(_context, "选择使用本地账号", Toast.LENGTH_LONG).show();
                                if (LANG.equals("java")) {
                                    if (!YSDKApi.switchUser(false)) {
                                        letUserLogout();
                                    }
                                } else {
                                    if(!PlatformTest.switchUser(false)){
                                        letUserLogout();
                                    }
                                }
                            }
                        });
                builder.setNeutralButton("拉起账号",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog,
                                                int whichButton) {
                                Toast.makeText(_context, "选择使用拉起账号", Toast.LENGTH_LONG).show();
                                if (LANG.equals("java")) {
                                    if (!YSDKApi.switchUser(true)) {
                                        letUserLogout();
                                    }
                                } else {
                                    if(!PlatformTest.switchUser(true)){
                                        letUserLogout();
                                    }
                                }
                            }
                        });
                builder.show();
            }
        });

    }
    
    public void sendResult(String result) {
    	sendResult(result,true);
    }
    
    public void sendResult(String result,boolean isToast) {
        if(lbm != null) {
            Intent sendResult = new Intent(Constants.LOCAL_ACTION);
            sendResult.putExtra("Result", result);
            Log.d(LOG_TAG,"send: "+ result);
            lbm.sendBroadcast(sendResult);
        }
        if(isToast){
        	Toast.makeText(_context,result,Toast.LENGTH_LONG).show();
        }
    }
	
	 // 获取当前登录平台
    public ePlatform getPlatform() {
        UserLoginRet ret = new UserLoginRet();
        YSDKApi.getLoginRecord(ret);
        if (ret.flag == eFlag.Succ) {
            return ePlatform.getEnum(ret.platform);
        } 
        return ePlatform.None;
    }
    
    // 展示相应的功能模块
 	public void startModule() {
 		
 	}
    
	//获取用户信息
	public void getUserInfo(final UserLoginRet ret){
		
		if(getPlatform() == ePlatform.WX){
			YSDKApi.queryUserInfo(ePlatform.WX);
		}else{
			YSDKApi.queryUserInfo(ePlatform.QQ);
		}
		
		/*
		//获取微信资料
		if(getPlatform() == ePlatform.WX){
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
		*/
	}
	
	public void onLoginCallBack(PersonInfo personInfo)
	{
		//获取成功
		UserLoginInfo userLogoInfo = getUserLogoInfo();
        userLogoInfo.reset();
        uuid = personInfo.openId;
		userLogoInfo.setAcccount(personInfo.nickName);
		userLogoInfo.setAccountType(_QQAccount);
		userLogoInfo.setFaceID(uuid);
		String pic = personInfo.pictureLarge;
		if(pic.equals("")){
			pic = personInfo.pictureMiddle;
		}
		userLogoInfo.setBigFace(pic);
		int gender = personInfo.gender.equals( "男" ) ? 1 : 0; 
		userLogoInfo.setGender(gender);
		onLoginResulet(1);
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
		YSDKApi.logout();
	}

	@Override
	public void CCPay(final JSONObject response) {

		if(this.sdkPay != null){
			sdkPay.CCPay(response);
			return;
		}
		
		proItem = ProductInfoItem.parseObject(response);
		orderid = getOutTradeNo(proItem.getUserID()+"");
		
		//获取订单编号
		String OrderURL = "";
		try {
			OrderURL = response.getString("OrderURL");
			domainURL = response.getString("domainURL");
		} catch (JSONException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		nRecharge = 0;
		getBalance();//获取当前钻石，打开充值
		
		/*ReadGetUrlAsyncTask task = new ReadGetUrlAsyncTask(OrderURL,null,null);
		task.addReadGetExecute(new ReadGetExecute() {
			
			@Override
			public void onGetExecute(String str) {
				Log.i(TAG, str);
				JSONObject jobj;
				try {
					jobj = new JSONObject(str);
					orderid = jobj.getString("result");
					LaunchPay();
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					Toast.makeText(_context,"支付失败:"+e.getMessage(), Toast.LENGTH_LONG).show();
				}
			}
		});
		task.execute("");*/
	}
	
	public void LaunchPay(){
		
		int ratio = 10/1;//兑换比例
		int saveValue = 1;
		String Remark = "1";
		saveValue = ((int)proItem.getMoney()*ratio);
		Remark = proItem.getRemark();
		
		presenttimes = (int)(Integer.parseInt(Remark) - saveValue);//获取赠送数量
		if(presenttimes>=1){
			int debug = 1;
			if(debug==0){//断点测试
				presentPay();
				return;
			}
		}
		String zoneId = "1";
		boolean isCanChange = false;
		Bitmap bmp = BitmapFactory.decodeResource(_context.getResources(), R.drawable.icon_diamond);
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		bmp.compress(Bitmap.CompressFormat.PNG, 100, baos);
		byte[] appResData = baos.toByteArray();
		String ysdkExt = "ysdkExt";
//		String ysdkExt = "niuExt";
//		nRecharge = 0;
		YSDKApi.recharge(zoneId, saveValue+"",isCanChange,appResData,ysdkExt,new PayListener() {
		    @Override
		    public void OnPayNotify(PayRet ret) {
		        if(PayRet.RET_SUCC == ret.ret){
		            //支付流程成功
		            switch (ret.payState){
		                //支付成功
		                case PayRet.PAYSTATE_PAYSUCC:
//		                    SDKControl.this.sendResult(
//		                            "用户支付成功，支付金额"+ret.realSaveNum+";" +
//		                            "使用渠道："+ret.payChannel+";" +
//		                            "发货状态："+ret.provideState+";" +
//		                            "业务类型："+ret.extendInfo+";建议查询余额："+ret.toString()
//		                            );
//		                	SDKControl.this.onPayResult(3,1);
//		                	presentPay();
		                    break;
		                //取消支付
		                case PayRet.PAYSTATE_PAYCANCEL:
		                	SDKControl.this.sendResult("用户取消支付："+ret.toString());
		                    break;
		                //支付结果未知
		                case PayRet.PAYSTATE_PAYUNKOWN:
		                	SDKControl.this.sendResult("用户支付结果未知，建议查询余额："+ret.toString());
		                    break;
		                //支付失败
		                case PayRet.PAYSTATE_PAYERROR:
		                	SDKControl.this.sendResult("支付异常"+ret.toString());
		                    break;
		            }
		        }else{
		            switch (ret.flag){
		                case eFlag.User_LocalTokenInvalid:
		                    //用户取消支付
		                	SDKControl.this.sendResult("登陆态过期，请重新登陆："+ret.toString());
		                	SDKControl.this.letUserLogout();
		                    break;
		                case eFlag.Pay_User_Cancle:
		                    //用户取消支付
		                	SDKControl.this.sendResult("用户取消支付："+ret.toString());
		                    break;
		                case eFlag.Pay_Param_Error:
		                	SDKControl.this.sendResult("支付失败，参数错误"+ret.toString());
		                    break;
		                case eFlag.Error:
		                default:
		                	SDKControl.this.sendResult("支付异常"+ret.toString());
		                    break;
		            }
		        }
		    }
		});
	}
	
	//回调接口
	IUnipayServiceCallBackPro.Stub unipayStubCallBack = new IUnipayServiceCallBackPro.Stub() {

		@Override
		public void UnipayCallBack(UnipayResponse response) {
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

		@Override
		public void UnipayNeedLogin() {
			// TODO Auto-generated method stub
			Log.i("UnipayPlugAPI", "UnipayNeedLogin");
			Message msg = handler.obtainMessage();
			msg.what = -1;
			msg.obj = "登录过期，请重新登录再进行购买支付";
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
//				presentPay();
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
//		String url = domainURL + "/v3/r/mpay/get_balance_m";
		String url = "";
		
		String org_loc = "/v3/r/mpay/get_balance_m";
		String cookie = String.format("session_id=%1$s;session_type=%2$s;org_loc=%3$s",sessionId,sessionType,org_loc);
		String ts = System.currentTimeMillis()/1000+"";
		HashMap<String,String> jParam = new HashMap<String, String>();
		jParam.put("openid",userId);
		jParam.put("openkey",userKey);
		jParam.put("pay_token",pay_token);
		jParam.put("appid",Constants.APP_ID);
		jParam.put("ts",ts);
		jParam.put("pf",pf);
		jParam.put("pfkey",pfKey);
		jParam.put("zoneid",zoneId);
		
		//自定义参数
//		if(nRecharge>=0){
			if(JniHelper.getAppDebug()==0){
				url = domainURL + "/getcftbalance.aspx"; //发行版
			}else{
				url = domainURL + "/getcftbalancetest.aspx";//调试版
			}
			
			jParam.put("sessionid",sessionId);
			jParam.put("sessiontype",sessionType);
			jParam.put("billno",orderid);
			jParam.put("productid",proItem.getProductId()+"");
			jParam.put("gameid",proItem.getGameId()+"");
			if(nRecharge==0){
				jParam.put("ispay",0+"");
				nRecharge = 1;
			}else{
				jParam.put("ispay",1+"");
			}
//		}else{
//			//直接获取
//			url = Constants.APP_URL + "/v3/r/mpay/get_balance_m"; 
//		}
		
		// 签名密钥
        HashMap<String, String> params = jParam;
        
//		String secret = APP_KEY + "&";
		String secret = Constants.APP_KEY_PAY + "&";
		// 计算签名
		String sig = "";
		try {
			sig = SnsSigCheck.makeSig("GET", "/v3/r/mpay/get_balance_m", params,
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
				Log.i(TAG,str);
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
						int nBalance = Integer.valueOf(balance);
						if(nRecharge==1){
							nRecharge = 2;
							//充值
							LaunchPay();
						}else if(nRecharge >= 3){//充值结果查询
							nRecharge++;
							if(currentBalance != nBalance){
								//金币增加了
								nRecharge = -1;
								currentBalance = nBalance;
								SDKControlOriginal.getDelegate().onPayResult(3, 1);//支付成功
//								presentPay();
							}
							if(nRecharge <= 15){
								handler.postDelayed(new Runnable() {
									
									@Override
									public void run() {
										// TODO Auto-generated method stub
										getBalance();
									}
								},5000);
							}
						}else{
							currentBalance = nBalance;
						}
							
					}else{
						Toast.makeText(_context, "获取余额失败，请重新登录:"+response.getString("msg"), Toast.LENGTH_LONG).show();
						SDKControl.this.letUserLogout();
					}
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					Toast.makeText(_context, "数据异常，请稍候再试："+e.getMessage(), Toast.LENGTH_LONG).show();
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
		String url = domainURL+"/newcfttoscore.aspx";
		String org_loc = "/v3/r/mpay/pay_m";
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
		jParam.put("appid", Constants.APP_ID);
		jParam.put("ts", ts);
		jParam.put("pf", pf);
		jParam.put("zoneid", zoneId);
		jParam.put("amt", amt);
		jParam.put("pfkey", pfKey);
		jParam.put("billno", getOutTradeNo(userid));
		
		// 签名密钥
		HashMap<String, String> params = jParam;

//		String secret = APP_KEY + "&";
		String secret = Constants.APP_KEY_PAY + "&";
		
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
				Log.i(TAG,str);
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

		String url = Constants.APP_URL + "/mpay/cancel_pay_m";
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
		jParam.put("appid", Constants.APP_ID);
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
		String secret = Constants.APP_KEY_PAY + "&";
		
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
	
	//送礼
	public void presentPay(){
		/*
//		String url = APP_URL + "/mpay/present_m";
		String url = domainURL+"/newcftgift.aspx";
		String org_loc = "/v3/r/mpay/present_m";
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
		task.execute("");*/
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
//		Logger.d("CCNotify");
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
			try {
				proItem.setGameId(response.getInt("gameID"));
				proItem.setDomainURL(response.getString("domainURL"));
				domainURL = response.getString("domainURL");
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
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
		YSDKApi.onDestroy(((Activity)_context));
        if(lbm != null) {
        	lbm.unregisterReceiver(mReceiver);
        }
	}
	
	public void onActivityResult(int requestCode, int resultCode, Intent data){
		YSDKApi.onActivityResult(requestCode, resultCode, data);
	};
	
	public void onResume() {
		YSDKApi.onResume((Activity) _context);
		if(nRecharge == 2){
			//手动刷新查询
			nRecharge = 3;
//			Toast.makeText(_context, "正在为你获取最新钻石余额...", Toast.LENGTH_LONG).show();
			getBalance();
		}
	};
	
	public void onPause() {
		YSDKApi.onPause((Activity) _context);
	};
	
	public void onStop() {
		YSDKApi.onStop((Activity) _context);
	};
	
	public void onNewIntent(Intent intent) {
		Log.d(LOG_TAG,"onNewIntent");
        super.onNewIntent(intent);

        // TODO GAME 处理游戏被拉起的情况
        Log.d(LOG_TAG,"LoginPlatform is not Hall");
        YSDKApi.handleIntent(intent);
	};
	
}
