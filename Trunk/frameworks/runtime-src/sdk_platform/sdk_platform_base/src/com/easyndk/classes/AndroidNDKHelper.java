package com.easyndk.classes;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import org.json.JSONException;
import org.json.JSONObject;

import android.os.Handler;
import android.os.Message;

public class AndroidNDKHelper {

	private static Object callHandler = null;
	private static Handler NDKHelperHandler = null;

	private static native void CPPNativeCallHandler(String methodNameStr, String paramsJsonStr);
	private final static int __MSG_FROM_CPP__ = 5;

	public static void SetNDKReceiver(Object callReceiver)
	{
		callHandler = callReceiver;
		NDKHelperHandler = new Handler()
		{
			public void handleMessage(Message msg)
			{
				switch(msg.what)
				{
				case __MSG_FROM_CPP__:
					try
					{
						NDKMessage message = (NDKMessage)msg.obj;
						message.methodToCall.invoke(AndroidNDKHelper.callHandler, message.methodParams);
					}
					catch (IllegalArgumentException e)
					{
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					catch (IllegalAccessException e)
					{
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					catch (InvocationTargetException e)
					{
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					break;
				}
			}
		};
	}

	public static void SendMessageWithParameters(String methodToCall, JSONObject paramList)
	{
		CPPNativeCallHandler(methodToCall,paramList.toString());
	}

	public static void ReceiveCppMessage(String methodToCall, String paramsJsonStr)
	{
		if (methodToCall != null)
		{
			try
			{
				JSONObject methodParams = new JSONObject(paramsJsonStr);
				try
				{
					Method m = AndroidNDKHelper.callHandler.getClass().getMethod(methodToCall, new Class[] { JSONObject.class });

					NDKMessage message = new NDKMessage();
					message.methodToCall = m;
					message.methodParams = methodParams;

					Message msg = new Message();
					msg.what = __MSG_FROM_CPP__;
					msg.obj = message;

					AndroidNDKHelper.NDKHelperHandler.sendMessage(msg);
				}
				catch (NoSuchMethodException e)
				{
					e.printStackTrace();
				}
				catch (IllegalArgumentException e)
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			catch (JSONException e)
			{
				e.printStackTrace();
			}
		}
	}
}
