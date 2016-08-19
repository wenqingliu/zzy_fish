package com.jt.sdk_platform_tencent;

import org.json.JSONObject;

import com.tencent.tauth.IUiListener;
import com.tencent.tauth.UiError;


import android.app.Activity;
import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class BaseUIListener implements IUiListener {
	private Context mContext;
	private String mScope;
	private Handler mHandler;
	private boolean mIsCaneled;
	public static final int ON_COMPLETE = 0;
	public static final int ON_ERROR = 1;
	public static final int ON_CANCEL = 2;
	protected static final String TAG = BaseUIListener.class.getName();
	
	public BaseUIListener(Context mContext,Handler handler) {
		super();
		this.mContext = mContext;
		this.mHandler = handler;
	}

	
	public BaseUIListener(Context mContext,Handler handler, String mScope) {
		super();
		this.mContext = mContext;
		this.mHandler = handler;
		this.mScope = mScope;
	}
	
	public void cancel() {
		mIsCaneled = true;
	}


	@Override
	public void onComplete(Object response) {
		if (mIsCaneled)
			return;
		if (null == response) {
			return;
		}
		JSONObject jsonResponse = (JSONObject) response;
		if (null != jsonResponse && jsonResponse.length() == 0) {
			return;
		}
		Message msg = mHandler.obtainMessage();
		msg.what = ON_COMPLETE;
		msg.obj = response;
		mHandler.sendMessage(msg);
	}

	@Override
	public void onError(UiError e) {
		if (mIsCaneled) return;
	    Message msg = mHandler.obtainMessage();
        msg.what = ON_ERROR;
        msg.obj = e;
        mHandler.sendMessage(msg);
	}

	@Override
	public void onCancel() {
		if (mIsCaneled) return;
	    Message msg = mHandler.obtainMessage();
        msg.what = ON_CANCEL;
        mHandler.sendMessage(msg);
	}

	public Context getmContext() {
		return mContext;
	}

	public void setmContext(Context mContext) {
		this.mContext = mContext;
	}

}
