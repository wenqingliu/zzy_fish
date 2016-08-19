package com.jt.sdk_platform_base;


import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import YYProjectJni.UpUserInfo;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.net.Uri;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.InputFilter.LengthFilter;
import android.util.Log;
import android.widget.Toast;

import com.hjwl.newox.jpush.Jpush;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.update.UpdateManager;
import com.jt.user.UserLoginInfo;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask.ReadGetExecute;
import com.umeng.analytics.MobclickAgent;


public class SDKDelegate extends SDKControlOriginal {
	public static final String TAG = "SDKDelegate";
	public SDKControlOriginal sdk;
	public int nlogonType = _GameAccount;
	public Map<Integer,SDKControlOriginal> sdkMap = new HashMap<Integer,SDKControlOriginal>();
	private Object objectParams;
	public UpUserInfo upUserInfo;
	public Jpush jpush;
	
	public SDKDelegate(){
		SDKControlOriginal.setDelegate(this);
		initSDK();
	}
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		if(sdk != null){
			sdk.onCreate(savedInstanceState);
		}
	}
	
	public void onDestroy() {
		if(sdk != null){
			sdk.onDestroy();
		}
	}
	
	public void onActivityResult(int requestCode, int resultCode, Intent data){
		if(sdk != null){
			sdk.onActivityResult(requestCode,resultCode,data);
		}
		if(upUserInfo != null){
			upUserInfo.onActivityResult(requestCode,resultCode,data);
		}
	};
	
	public void onRestart() {
		if(sdk != null){
			sdk.onRestart();
		}
	};
	
	public void onResume() {
		if(sdk != null){
			sdk.onResume();
		}
		if(jpush != null){
			jpush.onResume((Activity)_context);
		}
		MobclickAgent.onResume(_context);
	};
	
	public void onPause() {
		if(sdk != null){
			sdk.onPause();
		}
		if(jpush != null){
			jpush.onPause((Activity)_context);
		}
		MobclickAgent.onPause(_context);
	};
	
	public void onStop() {
		if(sdk != null){
			sdk.onStop();
		}
	};
	
	public void onNewIntent(Intent intent) {
		if(sdk != null){
			sdk.onNewIntent(intent);
		}
	};
	
	private void initSDK(){
		//动态生成SDK
		//新增SDK时请在此处写入相关SDKControl路径,注意与包名路径完全匹配
//		sdkMap.put(_GameAccount,this);
		int platform = Math.abs(JniHelper.getSDKPlatform());
		switch (platform) {
		case _QQAccount:
			sdkMap.put(_QQAccount,createSDKControl("com.jt.sdk_platform_tencent.SDKControl"));//QQ
			sdkMap.put(_WeChatAccount,createSDKControl("com.jt.sdk_platform_wechat.SDKControl"));//微信
			break;
//		case _WeChatAccount:
//			break;
		case _360Account:
			sdkMap.put(platform,createSDKControl("com.jt.sdk_platform_360.SDKControl"));//360
			break;
		case _XiaoMiAccount:
			sdkMap.put(platform,createSDKControl("com.jt.sdk_platform_mi.SDKControl"));//小米
			break;
		case _UCAccount:
			sdkMap.put(platform,createSDKControl("com.jt.sdk_platform_uc.SDKControl"));//UC
			break;
		case _LetvAccount:
			sdkMap.put(platform,createSDKControl("com.jt.sdk_platform_Letv.SDKControl"));//乐视
			break;
		case _MeizuAccount:
			sdkMap.put(platform,createSDKControl("com.jt.sdk_platform_meizu.SDKControl"));//魅族
			break;
		case _WandoujiaAccount:
			sdkMap.put(platform,createSDKControl("com.jt.sdk_platform_wandoujia.SDKControl"));//豌豆荚
			break;
		case _UUCAccount:
			sdkMap.put(platform,createSDKControl("com.jt.sdk_platform_uuc.SDKControl"));//uuc
			break;
		case _SamsungAccount:
			platform = _QQAccount; //转换用QQ渠道
			sdkMap.put(_QQAccount,createSDKControl("com.jt.sdk_platform_tencent.SDKControl"));//QQ
			sdkMap.put(_WeChatAccount,createSDKControl("com.jt.sdk_platform_wechat.SDKControl"));//微信
			break;
		default:
			break;
		}
		
		if (sdkMap.get(platform) == null
				&& (platform == _QQAccount || platform == _UUCAccount || platform == _UUMonAccount)) {
			// 使用YSDK登录
			SDKControlOriginal msdk = createSDKControl("com.jt.sdk_platform_ysdk.SDKControl");
			sdkMap.put(_QQAccount, msdk);
			sdkMap.put(_WeChatAccount, msdk);
			this.sdk = msdk;
		} else {
			this.sdk = sdkMap.get(platform);
		}
		
		if(this.sdk == null){
			Toast.makeText(_context,"未成功生成sdk，请检查AndroidManifest.xml配置或库引用是否正确", Toast.LENGTH_LONG).show();
		}
		
		//推送
		jpush = new Jpush((Activity)_context);
		jpush.regiestJPush(JniHelper.GetMac(0));
	}
	
	//动态生成SDK路径
	public SDKControlOriginal createSDKControl(String className){
		SDKControlOriginal sdk = null;
		try {
			Class cls = Class.forName(className);//动态创建实例
			sdk = (SDKControlOriginal) cls.newInstance();
		} catch (ClassNotFoundException e) {
			Log.e(TAG, e.getMessage());
		} catch (InstantiationException e) {
			Log.e(TAG, e.getMessage());
		} catch (IllegalAccessException e) {
			Log.e(TAG, e.getMessage());
		}
		return sdk;
	}

	@Override
	public byte AccountType() {
		if(nlogonType == _GuestAccount){
			return _GuestAccount;
		}
		return this.sdk.AccountType();
	};
	
	@Override
	public boolean isLogined() {
		if(nlogonType == _GuestAccount){
			return true;
		}
		return this.sdk.isLogined();
	}
	
	@Override
	public void CCLoginType(JSONObject response) {
		for (Map.Entry<Integer,SDKControlOriginal> entry : sdkMap.entrySet()) {
			SDKControlOriginal sdk = entry.getValue();
			if(sdk != null){
				sdk.CCLoginType(response);
			}
		}
//		this.sdk.CCLoginType(response);
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
		nlogonType = loginType;
		//游客登录
		if(loginType == _GuestAccount){
			UserLoginInfo info = getUserLogoInfo();
			info.setAcccount(new Build().MODEL);
			info.setAccountType(_GuestAccount);
			uuid = JniHelper.m_Mac;
			this.onLoginResulet(1);
			return;
		}
		
		//sdk登录
		sdk = sdkMap.get(loginType);
		if(sdk != null){
			sdk.CCGameLogin(response);
		}else{
			Toast.makeText(_context, "该SDK未接入，请选用其它方式进行登录",Toast.LENGTH_LONG).show();
		}
    }
	

	@Override
	public void CCGameLogout(JSONObject response){
		super.CCGameLogout(response);
		if(nlogonType == _GuestAccount){
			return;
		}
		this.sdk.CCGameLogout(response);
	}
	
	public void onLoginResulet(int result)
	{
		if(uuid.length() <= 2)
		{
			result = 0;
		}
		JSONObject jUser = new JSONObject();
        UserLoginInfo userLogoInfo = getUserLogoInfo();
		try {
			jUser.put("result",result);
			jUser.put("acccount",userLogoInfo.getAcccount());
			jUser.put("uuid",uuid);
			jUser.put("accountType",userLogoInfo.getAccountType());
			jUser.put("szMachineID",JniHelper.m_Mac);
			jUser.put("bigFace",userLogoInfo.getBigFace());
			jUser.put("gender",userLogoInfo.getGender());
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Log.i(TAG, userLogoInfo.toString());
		Log.i(TAG,"onLoginResulet:"+result);
		SendMessageWithParameters("ccNd_Platform_LogonResult", jUser);
	}
	
	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		if(nlogonType == _GuestAccount){
			sdk = sdkMap.get(_QQAccount);
		}
		if(sdk != null){
			sdk.CCPay(response);
		}
		//统计
		HashMap<String,String> map = new HashMap<String,String>();
		try {
			map.put("ProductID",response.getString("ProductID"));
			map.put("Price",response.getString("Price"));
			map.put("gameID",response.getString("gameID"));
			map.put("Remark",response.getString("Remark"));
			map.put("Date",new Date().toString());
			map.put("time",System.currentTimeMillis()+"");
			objectParams = map;
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		MobclickAgent.onEvent(_context,"CCPay",map);
	}

	@Override
	public void onPayResult(int type,int result){
		JSONObject params = new JSONObject();
		try {
			params.put("type",type);
			params.put("result",result);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_Shop_AppStore_Buy_Info_Result", params);
		HashMap<String,String> map = (HashMap<String,String>)objectParams;
		map.put("Date",new Date().toString());
		int time = (int)(System.currentTimeMillis() - Long.valueOf(map.get("time")) / 1000);
		map.put("time",time + "");
		map.put("type",type+"");
		map.put("result",result+"");
		//统计
		MobclickAgent.onEvent(_context,"onPayResult",map);
	}
	
	@Override
	public void CCNotify(JSONObject response){
		if(sdk != null){
			sdk.CCNotify(response);
		}
	}
	
	//自定义事件-------------------------------------------------
	public void CCShowTips(JSONObject response){
		String content = "";
		try {
			content = response.getString("content");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Toast.makeText(_context,content, Toast.LENGTH_SHORT).show();
	}
	
	public void CCSetRequestedOrientation(JSONObject response){
		int requestedOrientation = 0;
		try {
			requestedOrientation = response.getInt("requestedOrientation");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		((Activity)_context).setRequestedOrientation(requestedOrientation);
	}
	
	public void CCSaveLogin(JSONObject response) {
		Log.i(TAG, getUserLogoInfo().toString());
		saveLogin();
	}
	
	public void CCSetJPushTag(JSONObject response){
		if(jpush == null){
			return;
		}
		JSONArray jarr = null;
		try {
			jarr = response.getJSONArray("tags");
			Set<String> tagSet = new LinkedHashSet<String>();
			for(int i=0;i<jarr.length();i++){
				tagSet.add(jarr.get(i).toString());
			}
			jpush.setTags(tagSet);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Override
	@SuppressWarnings("deprecation")
	public Boolean CCQueryExitGame(JSONObject response) {
		if(this.sdk != null && this.sdk.CCQueryExitGame(response)){
			return true;
		}
		
		AlertDialog dialog = new AlertDialog.Builder(_context).create();
		dialog.setButton(((Activity)_context).getString(R.string.tv_ok),
				new AlertDialog.OnClickListener() { 
			@Override
			public void onClick(DialogInterface arg0, int arg1) {
				// TODO Auto-generated method stub
				((Activity)_context).finish();
				MobclickAgent.onKillProcess(_context);
				System.exit(0);
			} 
		}); 
	    dialog.setButton2(((Activity)_context).getString(R.string.tv_cancel),
				new AlertDialog.OnClickListener() { 
			@Override public void onClick(DialogInterface dialog, int which) { 
				dialog.dismiss();
			}
		}); 
	    dialog.setTitle(((Activity)_context).getString(R.string.tv_tips));
	    dialog.setMessage(((Activity)_context).getString(R.string.exit_game_que));
	    dialog.show();
	    return true;
	}
	
	
	public void CCVerision(JSONObject response){
		JSONObject params = new JSONObject();
		try {
			params.put("version", JniHelper.getAppVersionName());
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_Version", params);
	}
	
	public void CCBundleVerision(JSONObject response){
		JSONObject params = new JSONObject();
		try {
			params.put("version", JniHelper.getAppVersionCode()+"");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_Bundle_Verision", params);
	}
	
	public void CCOpenApp(JSONObject response){
		
	}
	
	public void CCOpenBrowser(JSONObject response){
		String url = "";
		try {
			url = response.getString("url");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Uri uri = Uri.parse(url);
		Intent intent = new  Intent(Intent.ACTION_VIEW, uri);
		Cocos2dxActivity.getContext().startActivity(intent);
	}
	
	public void CCUpdate(JSONObject response){

		if(JniHelper.getWifiState()!=WifiManager.WIFI_STATE_ENABLED){
			Toast.makeText(_context, "检测到当前网络非wifi状态，继续下载将消耗流量，敬请注意", Toast.LENGTH_LONG).show();
		}
		
		final UpdateManager update = new UpdateManager(_context);
		String url = "";
		try {
			url = response.getString("url");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
//		url = "http://shouji.360tpcdn.com/160330/008aac4eb374ccb422987c122ee820c5/com.jt.newox360_20160329.apk";
		if(url==""){
			Toast.makeText(_context,"URL下载地址无效", Toast.LENGTH_LONG).show();
			return;
		}
		
		final String urlStr = url;
		
		Handler handler = new Handler(){
			@Override
			public void handleMessage(Message msg) {
				// TODO Auto-generated method stub
				super.handleMessage(msg);
				int len = (Integer)msg.obj;
				if(len==0){
					Toast.makeText(_context, "获取下载文件失败", Toast.LENGTH_LONG).show();
					return;
				}
				String size = String.format("%.2f",(float)len/(1024*1000)) +"MB";
				final AlertDialog dialog = new AlertDialog.Builder(_context).create();
				dialog.setButton(((Activity)_context).getString(R.string.tv_cancel),
						new AlertDialog.OnClickListener() { 
					@Override
					public void onClick(DialogInterface arg0, int arg1) {
						// TODO Auto-generated method stub
						dialog.dismiss();
					} 
				}); 
			    dialog.setButton2(((Activity)_context).getString(R.string.tv_ok),
						new AlertDialog.OnClickListener() { 
					@Override public void onClick(DialogInterface dialog, int which) { 
						//开始更新
						update.startDownloadApk(urlStr);
					}
				}); 
			    dialog.setTitle("游戏下载");
			    dialog.setMessage("本次游戏安装包文件约"+size+"，点击立即下载？");
			    dialog.show();
				
				update.checkUpdate();
				
			}
		};
		Toast.makeText(_context, "正在为你获取最新版apk文件...", Toast.LENGTH_LONG).show();
		update.getFileSize(handler, urlStr);
		
	}
	
	public void CCUploadHead(JSONObject response){
		if(upUserInfo == null){
			upUserInfo = new UpUserInfo((Activity) _context);
		}
		upUserInfo.CCUploadHead(response);
	}

	//-----------------------------------------------------------
	
	
	//订单号
	public interface OrderListener {
		void onOrderResult(String orderid);
	}
	public void getOrderInfo(JSONObject response,final OrderListener listener){

		//获取订单编号
		String OrderURL = "";
		try {
			OrderURL = response.getString("OrderURL");
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
					String orderid = jobj.getString("result");
					listener.onOrderResult(orderid);
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					Toast.makeText(_context, "获取订单号失败，请稍候再试", Toast.LENGTH_LONG).show();
				}
			}
		});
		task.execute("");
	}
	
}
