package com.jt.sdk_platform_ysdk;

import YYProjectJni.JniHelper;

public class Constants {
	//URL
	public static String APP_URL = "https://ysdk.qq.com";
//	public static String APP_URL = "https://ysdktest.qq.com";

	public static String APP_ID = "";
	public static String APP_KEY = "";
	public static String APP_KEY_PAY = "";
//	public static String wxAppId = "";
//	public static String msdkKey = "";
	public static String offerId = "";
	public static String discountid = "UM16063011292444";
	public static String giftID = "65682073PID20160630112924545";
	
	public static final String LOCAL_ACTION = "com.tencent.tmgp.hjwl.fish";
	
	static{
			//发行版
			APP_ID = "1105357064";
			APP_KEY = "amXif5kjIWIVxAga";
			APP_KEY_PAY = "zUp3up7Ck1e41uU9f8qj3T60SBfaGTHe";//现网：zUp3up7Ck1e41uU9f8qj3T60SBfaGTHe;
//			wxAppId = "wxb1a9690e88554feb";
//			msdkKey = "d76a46308933b358f335a001ddbc9094";
			offerId = "1105357064";
		if(JniHelper.getAppDebug()==0){
			APP_URL = "https://ysdk.qq.com";
		}else{
//			//MSDK
//			APP_ID = "100703379";
//			APP_KEY = "4578e54fb3a1bd18e0681bc1c734514e";
			APP_KEY_PAY = "Uwl51IErvKPgVVVhnwB7y3jbmt0bMvyh";
//			wxAppId = "wxcde873f99466f74a";
//			msdkKey = "5d1467a4d2866771c3b289965db335f4";
//			offerId = "100703379";
			APP_URL = "https://ysdktest.qq.com";
		}
	}
	
}
