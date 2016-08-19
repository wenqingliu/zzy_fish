package YYProjectJni;

import org.cocos2dx.lib.Cocos2dxActivity;

import com.jt.sdk_platform_base.R;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.graphics.Bitmap;
import android.net.Uri;
import android.net.wifi.WifiManager;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.Toast;

public class JniHelper 
{
	public static String m_Mac;
	public static boolean m_cocosDebug;
	
	public static final int ID_WHAT_EXIT = 1;
	public static final int ID_WHAT_COPYID = 2;
	public static final int ID_WHAT_OPENBROWER = 3;
	
	public static String GetMac(int a)
	{
		Log.e("mac", m_Mac);
		return m_Mac; 
	}
	
	/**
	 * 获取版本号
	 * @return 当前应用的版本号
	 */
	public static String getAppVersionName() {
	    String versionName = "";  
	    try {  
	        PackageManager pm = Cocos2dxActivity.getContext().getPackageManager();  
	        PackageInfo pi = pm.getPackageInfo(Cocos2dxActivity.getContext().getPackageName(), 0);  
	        versionName = pi.versionName;  
	        if (versionName == null || versionName.length() <= 0) {  
	            return "";  
	        }  
	    } catch (Exception e) {  
	        Log.e("getAppVersionName", "Exception", e);  
	    }  
	    return versionName;  
	}
	
	/**
	 * 获取版本code
	 * @return 当前应用的版本号
	 */
	public static int getAppVersionCode() {
	    int versioncode = 0;  
	    try {  
	        PackageManager pm = Cocos2dxActivity.getContext().getPackageManager();  
	        PackageInfo pi = pm.getPackageInfo(Cocos2dxActivity.getContext().getPackageName(), 0);  
	        versioncode = pi.versionCode;
	    } catch (Exception e) {  
	        Log.e("getAppVersionCode", "Exception", e);  
	    }  
	    return versioncode;  
	}
	
	/**
	 * 获取是否cocos2d-x-debug界面版本
	 * @return 0 否,1是
	 */
	public static int getCocosDebug()
	{
		return m_cocosDebug ? 1 : 0;
	}
	
	/**
	 * 获取是否App-debug版本
	 * @return  0 否,1是
	 */
	public static int getAppDebug()
	{
		try {  
            ApplicationInfo info= Cocos2dxActivity.getContext().getApplicationInfo();
            boolean bool = (info.flags&ApplicationInfo.FLAG_DEBUGGABLE)!=0; 
            return  bool ? 1 : 0;
        } catch (Exception e) {  
              
        }  
        return 0;
	}
	
	public static int getWifiState()
	{
		WifiManager wifiManager = (WifiManager)Cocos2dxActivity.getContext().getSystemService(Context.WIFI_SERVICE);
	    if(wifiManager != null){
	    	int wifiState = wifiManager.getWifiState();
	    	return wifiState;
	    }
	    return WifiManager.WIFI_STATE_UNKNOWN;
	}
	
	public static int getSDKPlatform()
	{
		ApplicationInfo appInfo = null;
		try {
			appInfo = Cocos2dxActivity.getContext().getPackageManager()  
			         .getApplicationInfo(Cocos2dxActivity.getContext().getPackageName(),   
			 PackageManager.GET_META_DATA);
		} catch (NameNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}  
		int v = appInfo.metaData.getInt("sdk_platform");  
		return v;
	}
	
	public static String getAppName()
	{
		PackageInfo pkg = null;
		try {
			pkg = Cocos2dxActivity.getContext().getPackageManager().getPackageInfo(((Activity)Cocos2dxActivity.getContext()).getApplication().getPackageName(), 0);
		} catch (NameNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return Cocos2dxActivity.getContext().getString(R.string.app_name);
		}  
		String appName = pkg.applicationInfo.loadLabel(Cocos2dxActivity.getContext().getPackageManager()).toString();
		return appName;
	}
	
	public static String getPackageName()
	{
		return Cocos2dxActivity.getContext().getPackageName();
	}
	
}
