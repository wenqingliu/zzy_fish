package com.tencent.tmgp.yybtestsdk;

import android.app.Activity;

import com.tencent.ysdk.module.user.UserLoginRet;

import java.util.HashMap;

public class PlatformTest {

    public static native void setActivity(Activity activity);

    public static native String getVersion();

    public static native String getChannelId();

    public static native String getRegisterChannelId();

    public static native boolean isPlatformInstalled(int platform);

    public static native String getPlatformAppVersion(int platform);

    public static native void login(int platform);

    public static native void logout();

    public static native int getLoginRecord(UserLoginRet userLoginRet);

    public static native String getPf();

    public static native String getPfKey();

    public static native boolean switchUser(boolean switchToLaunchUser);

    public static native void queryUserInfo(int platform);

    public static native void reportEvent(String eventName, HashMap<String, String> params, boolean isRealTime);

    public static native void recharge(String zoneId, String saveValue, boolean isCanChange,byte[] resData, int dataLength,String ysdkInfo);

    public static native void testNativeCrash();
}
