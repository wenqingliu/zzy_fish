package com.hjwl.newox.jpush;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import org.cocos2dx.lua.AppActivity;
import org.json.JSONException;
import org.json.JSONObject;

import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate;

import java.util.Iterator;

import cn.jpush.android.api.JPushInterface;

/**
 * 自定义接收器
 * 
 * 如果不定义这个 Receiver，则：
 * 1) 默认用户会打开主界面
 * 2) 接收不到自定义消息
 */
public class MyReceiver extends BroadcastReceiver {
	private static final String TAG = "JPush";

	@Override
	public void onReceive(Context context, Intent intent) {
        Bundle bundle = intent.getExtras();
//		Log.d(TAG, "[MyReceiver] onReceive - " + intent.getAction() + ", extras: " + printBundle(bundle));
		
        if (JPushInterface.ACTION_NOTIFICATION_OPENED.equals(intent.getAction())) {
            Log.d(TAG, "[MyReceiver] 用户点击打开了通知");
            
            String params = bundle.getString(JPushInterface.EXTRA_EXTRA);
            Log.i(TAG, params);
            //打开自定义的Activity
            Intent i = new Intent(context, AppActivity.class);
            i.putExtras(bundle);
            i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_SINGLE_TOP );
            context.startActivity(i);
            
            /*if (AppActivity.isInit()) {
            	JSONObject jobj;
                if(params!=null){
        			try {
        				jobj = new JSONObject(params);
        				SDKControlOriginal.getDelegate().SendMessageWithParameters("ccNd_Broadcast",jobj);
        			} catch (JSONException e) {
        				// TODO Auto-generated catch block
        				e.printStackTrace();
        			}
                }
                return;
			}*/
            
        }
	}


}
