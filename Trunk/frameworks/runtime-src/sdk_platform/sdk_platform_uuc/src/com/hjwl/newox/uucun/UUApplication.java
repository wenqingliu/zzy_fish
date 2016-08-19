package com.hjwl.newox.uucun;

import android.app.Application;

import com.uucun.android.passport.openApi.SdkOpenApi;

public class UUApplication extends Application {

	@Override
	public void onCreate() {
		super.onCreate();
		SdkOpenApi.initSdk(this);
	}

	@Override
	public void onTerminate() {
		super.onTerminate();
		SdkOpenApi.unInstall();
	}

}
