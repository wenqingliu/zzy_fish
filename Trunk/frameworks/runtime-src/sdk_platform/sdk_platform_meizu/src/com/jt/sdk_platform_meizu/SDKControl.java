package com.jt.sdk_platform_meizu;


import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
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
import android.widget.Toast;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate.OrderListener;
import com.jt.user.UserLoginInfo;
import com.meizu.gamecenter.sdk.LoginResultCode;
import com.meizu.gamecenter.sdk.MzAccountInfo;
import com.meizu.gamecenter.sdk.MzBuyInfo;
import com.meizu.gamecenter.sdk.MzGameBarPlatform;
import com.meizu.gamecenter.sdk.MzGameCenterPlatform;
import com.meizu.gamecenter.sdk.MzLoginListener;
import com.meizu.gamecenter.sdk.MzPayListener;
import com.meizu.gamecenter.sdk.PayResultCode;

public class SDKControl extends com.jt.sdk_platform_base.SDKControlOriginal {
	private String TAG = "meizuSDK";
	private String appID = "3073184";
	private String appKey = "b85cab15933d421d8f960078f568e148";
	private String appSecret = "wpvbYqvkb9dmc28uyfMrJI4EpXdHCpSz";
	
    private String productName = "";
    private String productPrice = "";
    MzGameBarPlatform mzGameBarPlatform;
    private MessageDigest messageDigest ;
	public SDKControl(){
		/** SDK初始化 */
		MzGameCenterPlatform.init(_context, appID, appKey);
		try {
			messageDigest = MessageDigest.getInstance("MD5");
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		//初始化，可以指定gamebar第一次显示的位置，在游戏退出时会记住用户操作的最后一次位置，再次启动时使用上一次的位置
        //第一次显示的位置可以指定四个方向，左上，左下，右上，右下
        //    public static final int GRAVITY_LEFT_TOP = 1;
        //    public static final int GRAVITY_LEFT_BOTTOM = 2;
        //    public static final int GRAVITY_RIGHT_TOP = 3;
        //    public static final int GRAVITY_RIGHT_BOTTOM = 4;
		//　游戏登录后不能显示悬浮窗问题应检查下系统是否允许魅族游戏框架使用悬浮窗权限（在MIUI中可能会遇到）,具体可查看接入文档
		mzGameBarPlatform = new MzGameBarPlatform((Activity) _context, MzGameBarPlatform.GRAVITY_RIGHT_TOP);
		// TODO  创建悬浮窗
		mzGameBarPlatform.onActivityCreate();
	}
	
	@Override
	public byte AccountType() {
		return (byte) _MeizuAccount;
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
    	// TODO 调用登录接口。 注意，该方法必须在应用的主线程中调用。
    	MzGameCenterPlatform.login((Activity) _context, new MzLoginListener() {
	    	@Override
	    	public void onLoginResult(int code, MzAccountInfo accountInfo, String errorMsg) {
	    		// TODO 登录结果回调。 注意，该回调跑在应用主线程，不能在这里做耗时操作
		    	switch(code){
		    	case LoginResultCode.LOGIN_SUCCESS:
			    	// TODO 登录成功，拿到uid 和 session到自己的服务器去校验session合法性
			    	uuid = accountInfo.getUid();
			    	
		            UserLoginInfo userLogoInfo = getUserLogoInfo();
		            userLogoInfo.reset();
					userLogoInfo.setAcccount(accountInfo.getName());
					userLogoInfo.setAccountType((byte)SDKControl._MeizuAccount);
					userLogoInfo.setFaceID(uuid);
					userLogoInfo.setGender(0);
					getDelegate().onLoginResulet(1);
					
			    	Log.i(TAG,"锟斤拷录锟缴癸拷锟斤拷\r\n 锟矫伙拷锟斤拷锟斤拷" + accountInfo.getName() + "\r\n Uid锟斤拷" +
			    	accountInfo.getUid() + "\r\n session锟斤拷" + accountInfo.getSession());
		    	break;
		    	case LoginResultCode.LOGIN_ERROR_CANCEL:
		    		// TODO 用户取消登陆操作
		    		getDelegate().onLoginResulet(0);
			    	Log.i(TAG,"锟斤拷录失锟斤拷 : " + errorMsg + " , code = " + code);
		    	break;
		    	default:
		    		// TODO 登陆失败，包含错误码和错误消息。
		    		// TODO 注意，错误消息(errorMsg)需要由游戏展示给用户，提示失败原因
		    		Toast.makeText(_context, errorMsg, Toast.LENGTH_LONG).show();
		    		getDelegate().onLoginResulet(0);
			    	Log.i(TAG,"锟斤拷录失锟斤拷 : " + errorMsg + " , code = " + code);
			    break;
	    	}
    	}
    	});
    }
	

	@Override
	public void CCGameLogout(JSONObject response){
		MzGameCenterPlatform.logout(_context);
	}
	
	//字节转字符串
	public String bytesToHex(byte[] bytes) {		
		StringBuffer md5str = new StringBuffer();		//		
		int digital;		
		for (int i = 0; i < bytes.length; i++) {			 
			digital = bytes[i];			
			if(digital < 0) {
				digital += 256;			
				}			
			if(digital < 16){
				md5str.append("0");
				}			
			md5str.append(Integer.toHexString(digital));
			}		
		return md5str.toString();	
	}
	
	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		ProductInfoItem item = ProductInfoItem.parseObject(response);
		final String product_id = item.getProductId();
		
		productName = item.getProductName();
		productPrice = item.getMoney()+"";
		if (JniHelper.getAppDebug()!= 0) {
			productPrice = "0.01";
		}
		getDelegate().getOrderInfo(response, new OrderListener() {
			
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub
				// TODO  以下信息需要客户端通过网络访问自己的服务器获取，客户端不需要也不能在本地生成。
				String orderId = order; // cp_order_id (不能为空)
				String sign = appSecret; // sign (不能为空)
				String signType = "md5"; // sign_type (不能为空)
				int buyCount = 1; // buy_amount
				String cpUserInfo = ""; // user_info
				String amount = productPrice; // total_price
				String productId = product_id; // product_id
				String productSubject = productName; // product_subject
				String productBody = ""; // product_body
				String productUnit = ""; // product_unit
				String appid = appID; // app_id (不能为空)
				String uid = uuid; // uid (不能为空)
				String perPrice = productPrice; // product_per_price
				long createTime = System.currentTimeMillis()/1000; // create_time
				int payType = 0; // pay_type
				
				String buff = "app_id="+appid
						+"&buy_amount=" + buyCount
						+"&cp_order_id="+orderId
						+"&create_time=" + createTime
						+"&pay_type=" + payType
						+"&product_body=" + productBody
						+ "&product_id=" +productId
						+"&product_per_price=" + perPrice
						+"&product_subject=" + productSubject
						+"&product_unit=" + productUnit
						+"&total_price=" + amount
						+"&uid=" + uid
						+"&user_info=" + cpUserInfo
						+":"+appSecret;
				byte[] buff_byte = messageDigest.digest(buff.getBytes());
				sign = bytesToHex(buff_byte);
		            
				MzBuyInfo buyInfo = new MzBuyInfo().setBuyCount(buyCount).setCpUserInfo(cpUserInfo)
				.setOrderAmount(amount).setOrderId(orderId).setPerPrice(perPrice)
				.setProductBody(productBody).setProductId(productId).setProductSubject(productSubject)
				.setProductUnit(productUnit).setSign(sign).setSignType(signType).setCreateTime(createTime)
				.setAppid(appid).setUserUid(uid).setPayType(payType);
				
				MzGameCenterPlatform.payOnline((Activity) _context, buyInfo, new MzPayListener() {
					@Override
					public void onPayResult(int code, MzBuyInfo info, String errorMsg) {
						switch(code){
						case PayResultCode.PAY_SUCCESS:
							getDelegate().onPayResult(AccountType(),1);
						break;
						case PayResultCode.PAY_ERROR_CANCEL:
							getDelegate().onPayResult(AccountType(),0);
							
						break;
						default:
							getDelegate().onPayResult(AccountType(),0);
						break;
						}
					}
				});

			}
		});
	}
	
	@Override
	public void onDestroy() {
		super.onDestroy();
		// TODO  onActivityDestroy
		Log.i(TAG, "===onDestroy is called===");
		mzGameBarPlatform.onActivityDestroy();
	}
	
	@Override
	public void onResume(){
		super.onResume();
		mzGameBarPlatform.onActivityResume();
		Log.i(TAG, "===onResume is called===");
	}
	
	@Override
	public void onPause() {
		super.onPause();
		mzGameBarPlatform.onActivityPause();
		Log.i(TAG, "===onPause is called===");
	}
	
}
