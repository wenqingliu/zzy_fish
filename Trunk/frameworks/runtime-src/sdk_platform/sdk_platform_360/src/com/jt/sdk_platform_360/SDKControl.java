package com.jt.sdk_platform_360;


import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.text.TextUtils;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import com.jt.data.ProductInfoItem;
import com.jt.newox360.R;
import com.jt.sdk_platform_base.SDKDelegate.OrderListener;
import com.jt.user.UserLoginInfo;
import com.qihoo.gamecenter.sdk.activity.ContainerActivity;
import com.qihoo.gamecenter.sdk.common.IDispatcherCallback;
import com.qihoo.gamecenter.sdk.demosp.payment.Constants;
import com.qihoo.gamecenter.sdk.demosp.payment.QihooPayInfo;
import com.qihoo.gamecenter.sdk.demosp.utils.QihooUserInfo;
import com.qihoo.gamecenter.sdk.demosp.utils.QihooUserInfoListener;
import com.qihoo.gamecenter.sdk.demosp.utils.QihooUserInfoTask;
import com.qihoo.gamecenter.sdk.matrix.Matrix;
import com.qihoo.gamecenter.sdk.protocols.ProtocolConfigs;
import com.qihoo.gamecenter.sdk.protocols.ProtocolKeys;
public class SDKControl extends com.jt.sdk_platform_base.SDKControlOriginal {
	public static final String TAG = "SDKControl";
	protected String mAccessToken = null;
	protected QihooUserInfo mUserInfo;
	private boolean mIsInOffline = false;
	/**
	 * AccessToken是否有效
	 */
	protected static boolean isAccessTokenValid = true;
	/**
	 * QT是否有效
	 */
	protected static boolean isQTValid = true;
	
	public boolean isSwitch = false; //注销切换账号
	
	public SDKControl(){
		Matrix.init((Activity)_context);// 360初始化
	}

	@Override
	public byte AccountType() {
		return (byte) _360Account;
	};
	
	@Override
	public boolean isLogined() {
		if (AccountType != AccountType()) {
			return super.isLogined();
		} else {
			UserLoginInfo userLogoInfo = getUserLogoInfo();
			if(userLogoInfo.getFaceID() != null && userLogoInfo.getFaceID().length() > 2){
				return true;
			}else{
				return false;
			}
		}
	}
	
	@Override
	public void CCLoginType(JSONObject response) {
		// TODO Auto-generated method stub
		
		JSONObject j1 = new JSONObject();
		try {
			//开启360登录
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

    	doSdkLogin(true);
    }
	
	/**
	 * 使用360SDK的登录接口, 生成intent参数
	 * 
	 * @param isLandScape
	 *            是否横屏显示登录界面
	 */
	private Intent getLoginIntent(boolean isLandScape) {
		Intent intent = new Intent(_context, ContainerActivity.class);
		// 必需参数，使用360SDK的登录模块
		intent.putExtra(ProtocolKeys.FUNCTION_CODE,
				ProtocolConfigs.FUNC_CODE_LOGIN);
		// 可选参数，360SDK界面是否以横屏显示，默认为true，横屏
		intent.putExtra(ProtocolKeys.IS_SCREEN_ORIENTATION_LANDSCAPE,
				isLandScape);
		//是否显示关闭按钮
        intent.putExtra(ProtocolKeys.IS_LOGIN_SHOW_CLOSE_ICON, true);
        		
		// 可选参数，是否隐藏欢迎界面
        intent.putExtra(ProtocolKeys.IS_HIDE_WELLCOME,true);
        
        // 可选参数，自动登录过程中是否不展示任何UI，默认展示。
//        intent.putExtra(ProtocolKeys.IS_AUTOLOGIN_NOUI,true);

        // 可选参数，静默自动登录失败后是否显示登录窗口，默认不显示
        intent.putExtra(ProtocolKeys.IS_SHOW_LOGINDLG_ONFAILED_AUTOLOGIN,true);
		
		return intent;
	}

	// 调用接口
	protected void doSdkLogin(boolean isLandScape) {
		mIsInOffline = false;
		Intent intent = null;
		if(isSwitch){
			intent = getSwitchAccountIntent(isLandScape);
			Matrix.invokeActivity(_context, intent, mLoginCallback);
		}else{
			intent = getLoginIntent(isLandScape);
			Matrix.execute(_context, intent, mLoginCallback);
		}
	}
	
	// ---------------------------------360SDK接口的回调-----------------------------------

	// 登录、注册的回调
	private IDispatcherCallback mLoginCallback = new IDispatcherCallback() {

		@Override
		public void onFinished(String data) {
			// press back
			isSwitch = false;
			if (isCancelLogin(data)) {
				return;
			}
			// 显示一下登录结果
			// Toast.makeText(_context, data, Toast.LENGTH_LONG).show();
			mIsInOffline = false;
			// Log.d(TAG, "mLoginCallback, data is " + data);
			// 解析access_token
			mAccessToken = parseAccessTokenFromLoginResult(data);

			if (!TextUtils.isEmpty(mAccessToken)) {
				// 需要去应用的服务器获取用access_token获取一下带qid的用户信息
				getUserInfo();
			} else {
				// Toast.makeText(_context, "get access_token failed!",
				// Toast.LENGTH_LONG).show();
				Toast.makeText(_context, "获取用户信息失败", Toast.LENGTH_LONG).show();
			}
		}
	};
	
	private boolean isCancelLogin(String data) {
		try {
			JSONObject joData = new JSONObject(data);
			int errno = joData.optInt("errno", -1);
			if (-1 == errno) {
//				Toast.makeText(_context, data, Toast.LENGTH_LONG).show();
				return true;
			}
		} catch (Exception e) {
		}
		return false;
	}
	
	private String parseAccessTokenFromLoginResult(String loginRes) {
		try {

			JSONObject joRes = new JSONObject(loginRes);
			JSONObject joData = joRes.getJSONObject("data");
			return joData.getString("access_token");
		} catch (Exception e) {
			e.printStackTrace();
		}
		return null;
	}

	@Override
	public void CCGameLogout(JSONObject response){
		super.CCGameLogout(response);
		isSwitch = true;
	}
	
	/***
	 * 生成调用360SDK切换账号接口的Intent
	 * 
	 * @param isLandScape
	 *            是否横屏
	 * @return Intent
	 */
	private Intent getSwitchAccountIntent(boolean isLandScape) {

		Intent intent = new Intent(_context, ContainerActivity.class);

		// 必须参数，360SDK界面是否以横屏显示。
		intent.putExtra(ProtocolKeys.IS_SCREEN_ORIENTATION_LANDSCAPE,
				isLandScape);

		// 必需参数，使用360SDK的切换账号模块。
		intent.putExtra(ProtocolKeys.FUNCTION_CODE,
				ProtocolConfigs.FUNC_CODE_SWITCH_ACCOUNT);

		// 是否显示关闭按钮
		intent.putExtra(ProtocolKeys.IS_LOGIN_SHOW_CLOSE_ICON, true);

		// 可选参数，是否隐藏欢迎界面
		intent.putExtra(ProtocolKeys.IS_HIDE_WELLCOME, true);

		return intent;
	}

 	
 	private void getUserInfo() {

		isAccessTokenValid = true;
		isQTValid = true;
		final QihooUserInfoTask mUserInfoTask = QihooUserInfoTask.newInstance();
		
		JSONObject params = new JSONObject();
		try {
			params.put("result",1);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//加载用户资料进度条
        SendMessageWithParameters("ccNd_Platform_LogonLoading", params);

        // 请求应用服务器，用AccessToken换取UserInfo
		mUserInfoTask.doRequest(_context, mAccessToken,
				Matrix.getAppKey(_context), new QihooUserInfoListener() {

					@Override
					public void onGotUserInfo(QihooUserInfo userInfo) {
//						progress.dismiss();
						if (null == userInfo || !userInfo.isValid()) {
							Toast.makeText(_context, "获取用户信息失败",
									Toast.LENGTH_LONG).show();
							getDelegate().onLoginResulet(0);
						} else {
							mUserInfo = userInfo;
				            UserLoginInfo userLogoInfo = getUserLogoInfo();
							userLogoInfo.reset();
							if(userInfo.getNick()==null){
								userLogoInfo.setAcccount(userInfo.getName());
							}else{
								userLogoInfo.setAcccount(userInfo.getNick());
							}
							userLogoInfo.setAccountType(AccountType());
							userLogoInfo.setFaceID(userInfo.getId());
							userLogoInfo.setBigFace(userInfo.getAvatar());
							int gender = userInfo.getSex().equals("男") ? 1 : 0;
							userLogoInfo.setGender(gender);
							uuid = userInfo.getId();
							getDelegate().onLoginResulet(1);
						}
					}
				});
	}

	@Override
	public void CCPay(final JSONObject response) {
		// TODO Auto-generated method stub

        if (!checkLoginInfo(mUserInfo)) {
            return;
        }

        if(!isAccessTokenValid) {
            Toast.makeText(_context, R.string.access_token_invalid, Toast.LENGTH_SHORT).show();
            return;
        }
        if(!isQTValid) {
            Toast.makeText(_context, R.string.qt_invalid, Toast.LENGTH_SHORT).show();
            return;
        }
        
        
        getDelegate().getOrderInfo(response, new OrderListener() {
			
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub

		        ProductInfoItem item = ProductInfoItem.parseObject(response);

		        boolean isFixed = true;
		        QihooPayInfo payInfo = getQihooPay(item,order);
		        Intent intent = getPayIntent(isFixed, payInfo);

		        // 必需参数，使用360SDK的支付模块。
		        intent.putExtra(ProtocolKeys.FUNCTION_CODE, ProtocolConfigs.FUNC_CODE_PAY);

		        // 启动接口
		        Matrix.invokeActivity(_context, intent, mPayCallback);
				
			}
		});
        
	}
	

	 private boolean checkLoginInfo(QihooUserInfo info){
       if (mIsInOffline) {
           return true;
       }
       if(null == info || !info.isValid()){
           Toast.makeText(_context, "需要登录才能执行此操作", Toast.LENGTH_SHORT).show();
           return false;
       }
       return true;
   }
	 
	// payment begin
   /***
    * @param moneyAmount 金额数，使用者可以自由设定数额。金额数为100的整数倍，360SDK运行定额支付流程；
    *            金额数为0，360SDK运行不定额支付流程。
    * @return QihooPay
    */
   private QihooPayInfo getQihooPay(ProductInfoItem item,String orderId) {

       String qihooUserId = (mUserInfo != null) ? mUserInfo.getId() : null;

       // 创建QihooPay
       QihooPayInfo qihooPay = new QihooPayInfo();
       qihooPay.setQihooUserId(qihooUserId);
       int money = (int)(item.getMoney()*100);
       qihooPay.setMoneyAmount(money+"");
       qihooPay.setExchangeRate(Constants.DEMO_PAY_EXCHANGE_RATE);

       qihooPay.setProductName(item.getProductName());
       qihooPay.setProductId(item.getProductId());

       qihooPay.setNotifyUri(item.getDomainURL() + "/360noticeurl.aspx");//支付通知地址

       qihooPay.setAppName(_context.getString(R.string.app_name));
       qihooPay.setAppUserName(getUserLogoInfo().getAcccount());
       qihooPay.setAppUserId(mUserInfo.getId());

       // 可选参数
       qihooPay.setAppExt1(_context.getString(R.string.demo_pay_app_ext1));
       qihooPay.setAppExt2(_context.getString(R.string.demo_pay_app_ext2));
       qihooPay.setAppOrderId(orderId);

       return qihooPay;
   }
   
   /***
    * 生成调用360SDK支付接口的Intent
    *
    * @param isLandScape
    * @param pay
    * @return Intent
    */
   protected Intent getPayIntent(boolean isLandScape, QihooPayInfo pay) {
       Bundle bundle = new Bundle();

       // 界面相关参数，360SDK界面是否以横屏显示。
       bundle.putBoolean(ProtocolKeys.IS_SCREEN_ORIENTATION_LANDSCAPE, isLandScape);

       // *** 以下非界面相关参数 ***

       // 设置QihooPay中的参数。

       // 必需参数，360账号id，整数。
       bundle.putString(ProtocolKeys.QIHOO_USER_ID, pay.getQihooUserId());

       // 必需参数，所购买商品金额, 以分为单位。金额大于等于100分，360SDK运行定额支付流程； 金额数为0，360SDK运行不定额支付流程。
       bundle.putString(ProtocolKeys.AMOUNT, pay.getMoneyAmount());

       // 必需参数，所购买商品名称，应用指定，建议中文，最大10个中文字。
       bundle.putString(ProtocolKeys.PRODUCT_NAME, pay.getProductName());

       // 必需参数，购买商品的商品id，应用指定，最大16字符。
       bundle.putString(ProtocolKeys.PRODUCT_ID, pay.getProductId());

       // 必需参数，应用方提供的支付结果通知uri，最大255字符。360服务器将把支付接口回调给该uri，具体协议请查看文档中，支付结果通知接口–应用服务器提供接口。
       bundle.putString(ProtocolKeys.NOTIFY_URI, pay.getNotifyUri());

       // 必需参数，游戏或应用名称，最大16中文字。
       bundle.putString(ProtocolKeys.APP_NAME, pay.getAppName());

       // 必需参数，应用内的用户名，如游戏角色名。 若应用内绑定360账号和应用账号，则可用360用户名，最大16中文字。（充值不分区服，
       // 充到统一的用户账户，各区服角色均可使用）。
       bundle.putString(ProtocolKeys.APP_USER_NAME, pay.getAppUserName());

       // 必需参数，应用内的用户id。
       // 若应用内绑定360账号和应用账号，充值不分区服，充到统一的用户账户，各区服角色均可使用，则可用360用户ID最大32字符。
       bundle.putString(ProtocolKeys.APP_USER_ID, pay.getAppUserId());

       // 可选参数，应用扩展信息1，原样返回，最大255字符。
       bundle.putString(ProtocolKeys.APP_EXT_1, pay.getAppExt1());

       // 可选参数，应用扩展信息2，原样返回，最大255字符。
       bundle.putString(ProtocolKeys.APP_EXT_2, pay.getAppExt2());

       // 可选参数，应用订单号，应用内必须唯一，最大32字符。
       bundle.putString(ProtocolKeys.APP_ORDER_ID, pay.getAppOrderId());

       // 必需参数，使用360SDK的支付模块。
       bundle.putInt(ProtocolKeys.FUNCTION_CODE, ProtocolConfigs.FUNC_CODE_PAY);

       Intent intent = new Intent(_context, ContainerActivity.class);
       intent.putExtras(bundle);

       return intent;
   }

    // 支付的回调
    protected IDispatcherCallback mPayCallback = new IDispatcherCallback() {

        @Override
        public void onFinished(String data) {
//            Log.d(TAG, "mPayCallback, data is " + data);
            if(TextUtils.isEmpty(data)) {
                return;
            }

            boolean isCallbackParseOk = false;
            JSONObject jsonRes;
            try {
                jsonRes = new JSONObject(data);
                // error_code 状态码： 0 支付成功， -1 支付取消， 1 支付失败， -2 支付进行中, 4010201和4009911 登录状态已失效，引导用户重新登录
                // error_msg 状态描述
                int errorCode = jsonRes.optInt("error_code");
                isCallbackParseOk = true;
                switch (errorCode) {
                    case 0:
                    	getDelegate().onPayResult(-1,1);
                    	break;
                    case 1:
                    	getDelegate().onPayResult(-1,0);
                    	break;
                    case -1:
                    	break;
                    case -2: {
                        isAccessTokenValid = true;
                        isQTValid = true;
                        String errorMsg = jsonRes.optString("error_msg");
                        String text = _context.getString(R.string.pay_callback_toast, errorCode, errorMsg);
                        Toast.makeText(_context, text, Toast.LENGTH_SHORT).show();

                    }
                        break;
                    case 4010201:
                        //acess_token失效
                        isAccessTokenValid = false;
                        Toast.makeText(_context, R.string.access_token_invalid, Toast.LENGTH_SHORT).show();
                        break;
                    case 4009911:
                        //QT失效
                        isQTValid = false;
                        Toast.makeText(_context, R.string.qt_invalid, Toast.LENGTH_SHORT).show();
                        break;
                    default:
                        break;
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }

            // 用于测试数据格式是否异常。
            if (!isCallbackParseOk) {
                Toast.makeText(_context, _context.getString(R.string.data_format_error),
                        Toast.LENGTH_LONG).show();
            }
        }
    };

    // payment end
	
}
