/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.lua;

import java.util.ArrayList;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;

import cn.jpush.android.api.JPushInterface;

import com.easyndk.classes.AndroidNDKHelper;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate;
import com.umeng.analytics.game.UMGameAgent;
import com.umeng.social.CCUMSocialController;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Bundle;
import android.provider.Settings;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.WindowManager;
import android.widget.Toast;


public class AppActivity extends Cocos2dxActivity{
	
    static String hostIPAdress = "0.0.0.0";
//    public Jpush jpush;
    
    @SuppressWarnings("deprecation")
	@Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // JNI设置
//        JniHelper jniHelper = new JniHelper();
        TelephonyManager tm = (TelephonyManager) this.getSystemService(TELEPHONY_SERVICE);
        JniHelper.m_Mac = tm.getDeviceId();
        JniHelper.m_cocosDebug = nativeIsDebug();
        
        // SDK代理
        SDKDelegate sdk = new SDKDelegate();
        AndroidNDKHelper.SetNDKReceiver(sdk);
        SDKControlOriginal.getDelegate().onCreate(savedInstanceState);
        
        //友盟
        CCUMSocialController.initSocialSDK(this, "com.umeng.social.share");
        UMGameAgent.init(this);
        
	     // 禁止锁屏
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON,
				WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        
		sendBroadcast(savedInstanceState);
		
	    if(nativeIsLandScape()) {
            setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
        } else {
            setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_PORTRAIT);
        }
	    
        //2.Set the format of window
        
        // Check the wifi is opened when the native is debug.
        if(nativeIsDebug())
        {
            getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON, WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
            if(!isNetworkConnected())
            {
                AlertDialog.Builder builder=new AlertDialog.Builder(this);
                builder.setTitle("Warning");
                builder.setMessage("Please open WIFI for debuging...");
                builder.setPositiveButton("OK",new DialogInterface.OnClickListener() {
                    
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        startActivity(new Intent(Settings.ACTION_WIFI_SETTINGS));
                        finish();
                        System.exit(0);
                    }
                });

                builder.setNegativeButton("Cancel", null);
                builder.setCancelable(true);
                builder.show();
            }
            hostIPAdress = getHostIpAddress();
        }
    }
    
    public void sendBroadcast(Bundle bundle){
    	if(bundle==null){
    		return;
    	}
	    //推送返回
        JSONObject jobj;
        String params = bundle.getString(JPushInterface.EXTRA_EXTRA);
        if(params!=null){
			try {
				jobj = new JSONObject(params);
				SDKControlOriginal.getDelegate().SendMessageWithParameters("ccNd_Broadcast",jobj);
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
    }

    @Override
 	protected void onDestroy() {
    	super.onDestroy();
    	SDKControlOriginal.getDelegate().onDestroy();
    }
	
	@Override
 	protected void onRestart() {
		super.onRestart();
		SDKControlOriginal.getDelegate().onRestart();
	};
	
	@Override
 	protected void onResume() {
		super.onResume();
		SDKControlOriginal.getDelegate().onResume();
//		if(jpush != null){
//			jpush.onResume(this);
//		}
	};
	
	@Override
 	protected void onPause() {
		super.onPause();
		SDKControlOriginal.getDelegate().onPause();
//		if(jpush != null){
//			jpush.onPause(this);
//		}
	};
	
	@Override
 	protected void onStop() {
		super.onStop();
		SDKControlOriginal.getDelegate().onStop();
	};
	
	@Override
 	protected void onNewIntent(Intent intent) {
		super.onNewIntent(intent);
		SDKControlOriginal.getDelegate().onNewIntent(intent);
	};
    
 	@Override
 	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
 		super.onActivityResult(requestCode, resultCode, data);
 		CCUMSocialController.onActivityResult(requestCode, resultCode, data); 
    	SDKControlOriginal.getDelegate().onActivityResult(requestCode, resultCode, data);
    }
    
    private boolean isNetworkConnected() {
            ConnectivityManager cm = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);  
            if (cm != null) {  
                NetworkInfo networkInfo = cm.getActiveNetworkInfo();  
            ArrayList networkTypes = new ArrayList();
            networkTypes.add(ConnectivityManager.TYPE_WIFI);
            try {
                networkTypes.add(ConnectivityManager.class.getDeclaredField("TYPE_ETHERNET").getInt(null));
            } catch (NoSuchFieldException nsfe) {
            }
            catch (IllegalAccessException iae) {
                throw new RuntimeException(iae);
            }
            if (networkInfo != null && networkTypes.contains(networkInfo.getType())) {
                    return true;  
                }  
            }  
            return false;  
        } 
     
    public String getHostIpAddress() {
        WifiManager wifiMgr = (WifiManager) getSystemService(WIFI_SERVICE);
        WifiInfo wifiInfo = wifiMgr.getConnectionInfo();
        int ip = wifiInfo.getIpAddress();
        return ((ip & 0xFF) + "." + ((ip >>>= 8) & 0xFF) + "." + ((ip >>>= 8) & 0xFF) + "." + ((ip >>>= 8) & 0xFF));
    }
    
    public static String getLocalIpAddress() {
        return hostIPAdress;
    }
    
    private static native boolean nativeIsLandScape();
    private static native boolean nativeIsDebug();
    
}
