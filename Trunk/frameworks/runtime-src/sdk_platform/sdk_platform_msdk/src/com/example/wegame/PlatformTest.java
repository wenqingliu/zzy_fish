package com.example.wegame;

import java.util.ArrayList;
import java.util.HashMap;

import android.app.Activity;
import com.tencent.msdk.api.LoginRet;

public class PlatformTest {
	public static native void WGLogin(int Platform);

	public static native boolean WGSwitchUser(boolean switchToLaunchUser);

	public static native boolean WGLogout();

	public static native int WGGetLoginRecord(LoginRet ret);

	public static native void throwExp();

	public static native void setObserver(boolean flag);

	public static native void WGEnableCrashReport(boolean bRdmEnable,
			boolean bMtaEnable);

	public static native void WGReportEvent(String name, String body,
			boolean isRealTime);

	public static native void WGReportEvent(String name,
			HashMap<String, String> params, boolean isRealTime);

	public static native void WGTestSpeed(ArrayList<String> addrList);

	public static native String WGGetChannelId();

	public static native String WGGetVersion();

	public static native void WGSetPermission(int permissions);

	public static native boolean WGIsPlatformInstalled(int platform);

	public static native boolean WGIsPlatformSupportApi(int platform);

	public static native String WGGetRegisterChannelId();

	public static native void WGRefreshWXToken();

	public static native String WGGetPf(String gameCustomInfo);

	public static native String WGGetPfKey();

	public static native void WGLogPlatformSDKVersion();

	public static native boolean WGCheckApiSupport(int api);

	public static native void SetActivity(Activity activity);

	public static native void WGLoginWithLocalInfo();

	public static native String WGGetPlatformAPPVersion(int platform);

    public static native void WGQueryQQMyInfo();

    public native static void WGQueryWXMyInfo();
}
