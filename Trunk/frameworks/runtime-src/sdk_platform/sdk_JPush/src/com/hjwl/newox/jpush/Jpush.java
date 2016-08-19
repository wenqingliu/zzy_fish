package com.hjwl.newox.jpush;

import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.LinkedHashSet;
import java.util.Set;

import cn.jpush.android.api.InstrumentedActivity;
import cn.jpush.android.api.JPushInterface;
import cn.jpush.android.api.TagAliasCallback;
import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Handler;
import android.text.TextUtils;
import android.util.Log;
import android.widget.Toast;

//JPush
public class Jpush extends InstrumentedActivity {
	private static final int MSG_SET_TAGS = 1002;
	protected static final String TAG = "Jpush";
	protected static final String ISREGISTER = "ISREGISTER_";
	private Runnable runnable;
	private Activity activity;
	
	public Jpush(Activity activity){
		JPushInterface.setDebugMode(true);
		this.activity = activity;
		JPushInterface.init(activity);
	}
	
	public void regiestJPush(final String id){
		SharedPreferences pre = activity.getSharedPreferences(TAG,activity.MODE_PRIVATE);
		boolean isRegister = pre.getBoolean(ISREGISTER+id,false);
		if(!isRegister){
			runnable = new Runnable() {
				@Override
				public void run() {
					// TODO Auto-generated method stub
//					setTag(Jpush.this.toMd5(id).toUpperCase());
				}
			};
			mHandler.postDelayed(runnable,500);
		}
//		setTag(Jpush.this.toMd5(id).toUpperCase());
	}
	
	public void onResume(Activity activity){
		JPushInterface.onResume(activity);
	}
	public void onPause(Activity activity){
		JPushInterface.onPause(activity);
	}
	
	public void onDestroy(){
		if(runnable != null){
			mHandler.removeCallbacks(runnable);
			runnable = null;
		}
	}
	
	public void setTags(Set<String> tagSet){
		
		// ","隔开的多个 转换成 Set
//		String[] sArray = tag.split(",");
//		Set<String> tagSet = new LinkedHashSet<String>();
//		tagSet.add(tag);
		
		//调用JPush API设置Tag
		mHandler.sendMessage(mHandler.obtainMessage(MSG_SET_TAGS, tagSet));
	}
	
	private final Handler mHandler = new Handler() {
        @Override
        public void handleMessage(android.os.Message msg) {
            super.handleMessage(msg);
            switch (msg.what) {
//            case MSG_SET_ALIAS:
//                Log.d(TAG, "Set alias in handler.");
//                JPushInterface.setAliasAndTags(getApplicationContext(), (String) msg.obj, null, mAliasCallback);
//                break;
            case MSG_SET_TAGS:
                Log.d(TAG, "Set tags in handler.");
                Set<String> tagSet = (Set<String>) msg.obj;
//                if(tagSet.size() == 0){
//                	tagSet = null;
//                }
                JPushInterface.setAliasAndTags(Jpush.this.activity.getApplicationContext(), null,tagSet, mTagsCallback);
                break;
                
            default:
                Log.i(TAG, "Unhandled msg - " + msg.what);
            }
        }
    };
    
    private final TagAliasCallback mTagsCallback = new TagAliasCallback() {

        @Override
        public void gotResult(int code, String alias, Set<String> tags) {
        	String logs;
            Context context = Jpush.this.activity;
			switch (code) {
            case 0:
//            	SharedPreferences pre = context.getSharedPreferences(TAG,context.MODE_PRIVATE);
//            	Editor editor= pre.edit();
//            	editor.putBoolean(ISREGISTER,true);
//            	editor.commit();
                logs = "Set tag and alias success";
                Log.i(TAG, logs);
                break;
                
            case 6002:
                logs = "Failed to set alias and tags due to timeout. Try again after 60s.";
                Log.i(TAG, logs);
//                if (ExampleUtil.isConnected(getApplicationContext())) {
//                	mHandler.sendMessageDelayed(mHandler.obtainMessage(MSG_SET_TAGS, tags), 1000 * 60);
//                } else {
//                	Log.i(TAG, "No network");
//                }
                break;
            
            default:
                logs = "Failed with errorCode = " + code;
                Log.e(TAG, logs);
            }
            
//            ExampleUtil.showToast(logs, getApplicationContext());
        }
        
    };
    

    public static String toMd5(String string) {
		byte[] hash;
		try {
			hash = MessageDigest.getInstance("MD5").digest(
					string.getBytes("UTF-8"));
		} catch (NoSuchAlgorithmException e) {
			throw new RuntimeException("Huh, MD5 should be supported?", e);
		} catch (UnsupportedEncodingException e) {
			throw new RuntimeException("Huh, UTF-8 should be supported?", e);
		}

		StringBuilder hex = new StringBuilder(hash.length * 2);
		for (byte b : hash) {
			if ((b & 0xFF) < 0x10)
				hex.append("0");
			hex.append(Integer.toHexString(b & 0xFF));
		}
		return hex.toString();
	}

    
	
}
