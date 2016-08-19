package com.jt.sdk_platform_uc;

import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.util.Log;
import android.widget.Toast;
import cn.uc.gamesdk.UCCallbackListener;
import cn.uc.gamesdk.UCCallbackListenerNullException;
import cn.uc.gamesdk.UCFloatButtonCreateException;
import cn.uc.gamesdk.UCGameSDK;
import cn.uc.gamesdk.UCGameSDKStatusCode;
import cn.uc.gamesdk.UCLogLevel;
import cn.uc.gamesdk.UCLoginFaceType;
import cn.uc.gamesdk.UCOrientation;
import cn.uc.gamesdk.info.FeatureSwitch;
import cn.uc.gamesdk.info.GameParamInfo;
import cn.uc.gamesdk.info.OrderInfo;
import cn.uc.gamesdk.info.PaymentInfo;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.user.UserLoginInfo;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask;
import com.qp.lib.asynctask.ReadPostUrlAsyncTask;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask.ReadGetExecute;
import com.qp.lib.asynctask.ReadPostUrlAsyncTask.ReadPostExecute;

public class SDKControl extends SDKControlOriginal {
	public static final String TAG = "SDKControl";

	private final boolean IS_UC_SDK_DEBUG_MODE = false;
	private String UC_LOGIN_POST_URL = "http://sdk.g.uc.cn/cp/account.verifySession";
	private final String UC_API_KEY = "b4e96f1da2874e1cadf89de8b3eeee84";
	private final String UC_CP_ID = "50622";
	private final int UC_GAME_ID = 681562;
	private final String UC_SEVER_ID = "0";

	private Boolean isInit = false;
	
	public SDKControl(){
		
	}
	
	@Override
	public byte AccountType() {
		return (byte) _UCAccount;
	}

	@Override
	public void CCLoginType(JSONObject response) {
		JSONObject j1 = new JSONObject();
		try {
			j1.put("loginType", _UCAccount);
			j1.put("visible", true);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_PlatForm_LogonType", j1);
	}

	@Override
	public void CCGameLogin(JSONObject response) {
		// TODO Auto-generated method stub
		if(isInit){
			ucSdkLogin();
		}else{
			ucSdkInit();
		}
	}

	public void ucSdkInit() {

		if (IS_UC_SDK_DEBUG_MODE) {
			// 测试环境：
			UC_LOGIN_POST_URL = "http://sdk.test4.g.uc.cn/cp/account.verifySession";
		} else {
			// 正式环境：
			UC_LOGIN_POST_URL = "http://sdk.g.uc.cn/cp/account.verifySession";
		}
		
		UCCallbackListener<String> logoutListener = new UCCallbackListener<String>() {
			@Override
			public void callback(int statuscode, String data) {
				switch (statuscode) {
				case UCGameSDKStatusCode.NO_INIT:
					break;
				case UCGameSDKStatusCode.NO_LOGIN:
					break;
				case UCGameSDKStatusCode.SUCCESS:
					break;
				case UCGameSDKStatusCode.FAIL:
					break;
				default:
					break;
				}

			}
		};

		GameParamInfo gpi = new GameParamInfo();
		// gpi.setCpId(0); // 此参数已废弃,默认传入0即可
		gpi.setGameId(UC_GAME_ID); // 从UC九游开放平台获取自己游戏的参数信息
		 gpi.setServerId(0); // 此参数已废弃,默认传入0即可
		// gpi.setChannelId(2); // 渠道号统一处理，已不需设置，此参数已废弃
		// 设置是否支持查询充值历史和显示切换账号功能，如果不设置，默认具有查询充值历史记录，不具有切换账户功能
		gpi.setFeatureSwitch(new FeatureSwitch(true, false));
		try {
			// 设置SDK登录界面为竖屏或横屏（“UCOrientation.LANDSCAPE”时为横屏）
			UCGameSDK.defaultSDK().setOrientation(UCOrientation.LANDSCAPE);
			// 对于需要支持账户切换/退出账号的游戏，必须在此设置退出侦听器
			UCGameSDK.defaultSDK().setLogoutNotifyListener(logoutListener);
			// 设置登录界面：
			// USE_WIDGET - 简版登录界面
			// USE_STANDARD - 标准版登录界面
			UCGameSDK.defaultSDK().setLoginUISwitch(UCLoginFaceType.USE_WIDGET);
			UCGameSDK.defaultSDK().initSDK((Activity) _context,
					UCLogLevel.WARN, IS_UC_SDK_DEBUG_MODE, gpi,
					new UCCallbackListener<String>() {
						@Override
						public void callback(int code, String msg) {
							isInit = true;
							switch (code) {
							case UCGameSDKStatusCode.SUCCESS:
								// 初始化成功,可以执行后续的登录充值操作
								ucSdkLogin();
								break;
							case UCGameSDKStatusCode.INIT_FAIL:
								// 初始化失败,不能进行后续操作
								break;
							default:
								break;
							}
						}
					});
		} catch (UCCallbackListenerNullException e) {
			// TODO 捕获listener为null的异常
		}
	}

	public void ucSdkLogin() {
		try {
			UCGameSDK.defaultSDK().login((Activity) _context,
					new UCCallbackListener<String>() {
						@Override
						public void callback(int code, String msg) {
							if (code == UCGameSDKStatusCode.SUCCESS) {
								// 登录成功，可以执行后续操作
								String sid = UCGameSDK.defaultSDK().getSid();
								getUserInfoFromUc(sid);
							}
							if (code == UCGameSDKStatusCode.LOGIN_EXIT) {
								// 登录界面关闭，游戏需判断此时是否已登录成功进行相应操作
							}
							if (code == UCGameSDKStatusCode.NO_INIT) {
								// 没有初始化就进行登录调用，需要游戏调用SDK初始化方法
							}
						}
					});
		} catch (UCCallbackListenerNullException e) {
			// 异常处理
			Log.e("ucSdkLogin exception ****", "e.message = " + e.getMessage());
		}

	}

	public void getUserInfoFromUc(String sid) {

		// "id":1330395827,
		// "data":{"sid":"abcdefg123456"},
		// "game":{"gameId":12345},
		// "sign":"6e9c3c1e7d99293dfc0c81442f9a9984"

		// MD5签名
		String toMD5 = "sid=" + sid + UC_API_KEY;
		String sign = MD5.md5(toMD5);

		JSONObject jParam = new JSONObject();
		try {
			JSONObject jDataParam = new JSONObject();
			jDataParam.put("sid", sid);
			JSONObject jGameParam = new JSONObject();
			jGameParam.put("gameId", UC_GAME_ID);

			jParam.put("id", System.currentTimeMillis());
			jParam.put("data", jDataParam);
			jParam.put("game", jGameParam);
			jParam.put("sign", sign);
		} catch (JSONException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}

		// 获取用户资料
		ReadPostUrlAsyncTask post = new ReadPostUrlAsyncTask(UC_LOGIN_POST_URL,
				"", jParam);
		post.addReadPostExecute(new ReadPostExecute() {

			@Override
			public void onPostExecute(String str) {
				try {
					JSONObject response = new JSONObject(str);

					JSONObject stateJobj = response.getJSONObject("state");
					int code = stateJobj.getInt("code");
					String msg = stateJobj.getString("msg");

					if (code == 1) {
						// 获取成功
						UserLoginInfo userLogoInfo = getUserLogoInfo();
						userLogoInfo.reset();

						JSONObject dataJobj = response.getJSONObject("data");
						String accountId = dataJobj.getString("accountId");
						uuid = accountId;
						String nickName = dataJobj.getString("nickName");

						userLogoInfo.setAcccount(nickName);
						userLogoInfo.setAccountType(_UCAccount);
						userLogoInfo.setFaceID(uuid);

						userLogoInfo.setBigFace("");
						userLogoInfo.setGender(0);
						onLoginResulet(1);
					} else {
						Toast.makeText(_context,
								"code:" + code + ",msg:" + msg,
								Toast.LENGTH_LONG).show();
						onLoginResulet(0);
					}
				} catch (JSONException e) {
					e.printStackTrace();
				}
			}
		});
		post.execute("");
	}

	public void onLoginResulet(int result) {
		if (uuid.length() <= 2) {
			result = 0;
		}

		if (uuid.length() != 0) {
			try {
				// 创建悬浮按钮
				UCGameSDK.defaultSDK().createFloatButton((Activity) _context,
						new UCCallbackListener<String>() {
							@Override
							public void callback(int statuscode, String data) {
								if (statuscode == UCGameSDKStatusCode.SDK_OPEN) {
									// 将要打开SDK界面
								} else if (statuscode == UCGameSDKStatusCode.SDK_CLOSE) {
									// 将要关闭SDK界面，返回游戏画面

								}
							}
						});
				// 显示悬浮图标
				UCGameSDK.defaultSDK().showFloatButton((Activity) _context,
						100, 50, true);
			} catch (UCCallbackListenerNullException e) {
				// SDK界面消息侦听器为空
			} catch (UCFloatButtonCreateException e) {
				// 创建悬浮按钮异常
			}
		}

		JSONObject jUser = new JSONObject();
		UserLoginInfo userLogoInfo = getUserLogoInfo();
		try {
			jUser.put("result", result);
			jUser.put("acccount", userLogoInfo.getAcccount());
			jUser.put("uuid", uuid);
			jUser.put("accountType", userLogoInfo.getAccountType());
			jUser.put("szMachineID", JniHelper.m_Mac);
			jUser.put("bigFace", userLogoInfo.getBigFace());
			jUser.put("gender", userLogoInfo.getGender());
		} catch (JSONException e) {
			e.printStackTrace();
		}
		Log.i(TAG, userLogoInfo.toString());
		Log.i(TAG, "onLoginResulet:" + result);
		SendMessageWithParameters("ccNd_Platform_LogonResult", jUser);
	}

	@Override
	public void CCGameLogout(JSONObject response) {
		super.CCGameLogout(response);
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
	}

	@Override
	public void CCPay(JSONObject response) {
		String type = null;
		String gameID = null;
		String userID = null;
		String ProductName = null;
		String Description = null;
		String Price = null;
		int appid = 0;
		String ProductID = null;
		String NotifyURL = null;
		String domainURL = null;
		try {
			type = response.getString("type");
			gameID = response.getString("gameID");
			userID = response.getString("userID");
			ProductName = response.getString("ProductName");
			Description = response.getString("Description");
			Price = response.getString("Price");
			appid = response.getInt("appid");
			ProductID = response.getString("ProductID");
			NotifyURL = response.getString("NotifyURL");
			domainURL = response.getString("domainURL");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		final String ip = domainURL;

		String url = ip + "/getorderno.aspx?" + "gameid=" + gameID
				+ "&productid=" + ProductID;
		
		final String notifyUrl = ip + "/ucnoticeurl.aspx";//支付成功回调地址
		final float amount = Integer.parseInt(Price);//设定支付金额，0为任意充值金额
		
		ReadGetUrlAsyncTask task = new ReadGetUrlAsyncTask(url, null, null);
		task.addReadGetExecute(new ReadGetExecute() {

			@Override
			public void onGetExecute(String str) {

				JSONObject response;
				try {
					response = new JSONObject(str);
					String orderId = response.getString("result");
					try {

						// 创建Payment对象，用于传递充值信息
						PaymentInfo pInfo = new PaymentInfo();
						pInfo.setServerId(0); // 此参数已废弃,默认传入0即可 
						// pInfo.setAllowContinuousPay(true); //此参数已废弃,默认为false。
						// pInfo.setCustomInfo("custOrderId=PX299392#ip=139.91.192.29#...");
						// //设置充值自定义参数，此参数不作任何处理，在充值完成后通知游戏服务器充值结果时原封不动传给游戏服务器。此参数为可选参数，默认为空。对于需要使用此参数的游戏，充值前建议先判断下此参数传递的值是否正常不为空再调充值接口，注意长度不能超过250
		
						pInfo.setAmount(amount); // 单位：元
						// 设置允许充值的金额，此为可选参数，默认为0。
						// 如果设置了此金额不为0，则表示只允许用户按指定金额充值；如果不指定金额或指定为0，则表示用户在充值时可以自由选择或输入希望充入的金额。设置定额充值的游戏服务端收到回调信息必须校验amount
						// 值与客户端下单时传递的是否一致
						
						if(JniHelper.getAppDebug() != 0){
							pInfo.setAmount(0.01f);
						}
						
						pInfo.setNotifyUrl(notifyUrl);// 回调地址，非必填参数，此处设置或开放平台录入，优先取客户端设置的地址，设置后游戏在支付完成后SDK回调充值信息到此地址，必须为带有http头的URL形式。
						pInfo.setTransactionNumCP(orderId);// 设置CP自有的订单号，此为可选参数，对于需要使用此参数的游戏，充值前建议先判断下此参数传递的值是否正常不为空再调充值接口，注意长度不能超过30
						
						UCGameSDK.defaultSDK().pay((Activity) _context, pInfo,
								payResultListener);
					} catch (UCCallbackListenerNullException e) {
						// 异常处理
					}

				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}

		});
		task.execute("");
	}

	private UCCallbackListener<OrderInfo> payResultListener = new UCCallbackListener<OrderInfo>() {
		@Override
		public void callback(int statudcode, OrderInfo orderInfo) {
			if (statudcode == UCGameSDKStatusCode.NO_INIT) {
				// 没有初始化就进行登录调用，需要游戏调用SDK初始化方法
			}
			if (statudcode == UCGameSDKStatusCode.SUCCESS) {

				onPayResult(1);
				// 成功充值
				if (orderInfo != null) {
					String ordereId = orderInfo.getOrderId();// 获取订单号
					float orderAmount = orderInfo.getOrderAmount();// 获取订单金额
					int payWay = orderInfo.getPayWay();
					String payWayName = orderInfo.getPayWayName();
					Log.i(TAG, ordereId + "," + orderAmount + "," + payWay + "," + payWayName);
				}
			}
			if (statudcode == UCGameSDKStatusCode.PAY_USER_EXIT) {
				// 用户退出充值界面。
			}
			
			if (statudcode == UCGameSDKStatusCode.FAIL) {
				// 充值失败
				onPayResult(0);
			}
		}

	};
	
	public void onPayResult(int result) {
		SDKControlOriginal.getDelegate().onPayResult(1, result);
	}
	
	@Override
	public Boolean CCQueryExitGame(JSONObject response) {
		// TODO Auto-generated method stub
		super.CCQueryExitGame(response);
		
		if(!isInit){
			return false;
		}
		
		try {
			UCGameSDK.defaultSDK().logout();
		} catch (UCCallbackListenerNullException e) {
			// 未设置退出侦听器
		}
		UCGameSDK.defaultSDK().exitSDK((Activity) _context,
				new UCCallbackListener<String>() {
					@Override
					public void callback(final int statuscode, final String data) {
						if (UCGameSDKStatusCode.SDK_EXIT_CONTINUE == statuscode) {
							// 此加入继续游戏的代码
//							Toast.makeText((Activity) _context, data,
//									Toast.LENGTH_LONG).show();
						} else if (UCGameSDKStatusCode.SDK_EXIT == statuscode) {
							// 在此加入退出游戏的代码
//							Toast.makeText((Activity) _context, data,
//									Toast.LENGTH_LONG).show();
							((Activity)_context).finish();
							System.exit(0);
						}
					}
				});
		UCGameSDK.defaultSDK().destoryFloatButton((Activity) _context);
		
		return true;
	}
	
}
