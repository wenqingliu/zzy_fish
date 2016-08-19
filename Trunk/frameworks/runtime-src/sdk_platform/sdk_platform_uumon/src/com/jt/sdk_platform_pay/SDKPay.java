package com.jt.sdk_platform_pay;


import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.webkit.WebView.FindListener;
import android.widget.Toast;

import com.jiangnane.paysdk.JNEPay;
import com.jiangnane.paysdk.JNEPayListener;
import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKDelegate.OrderListener;

//uu盟
public class SDKPay extends com.jt.sdk_platform_base.SDKControlOriginal{
	private String TAG = "uumonSDK";
    
    public SDKPay() {
    	JNEPay.init((Activity)_context);
	}
    
	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		final ProductInfoItem item = ProductInfoItem.parseObject(response);
		Log.i(TAG, "===CCPay is called===");
		
		getDelegate().getOrderInfo(response, new OrderListener() {
			
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub
		        HashMap<String, String> payParams = new HashMap<String, String>();
		        payParams.put(JNEPay.PayParams.KEY_TOOLS_NAME, item.getProductName()); // 道具名称
		        long productPrice = (long) ((item.getMoney())*100); //转化分为单位
		        payParams.put(JNEPay.PayParams.KEY_TOOLS_PRICE, productPrice + "");// 道具价格   单位: 分
		        payParams.put(JNEPay.PayParams.KEY_CP_ORDERID,order); // CP订单号
		        
		        JNEPay.pay((Activity) _context, payParams, new JNEPayListener() {
		        	@Override
		            public void paySuccess(Map<String, String> payParams) {
		                // TODO Auto-generated method stub
		        		getDelegate().onPayResult(AccountType(),1);
		        		Log.e(TAG, "支付成功");
		            }
		        	@Override
		            public void payFailed(Map<String, String> payParams, int reasonCode) {
		                // TODO Auto-generated method stub
		        		getDelegate().onPayResult(AccountType(),0);
		        		Log.e(TAG, "支付错误："+reasonCode);
		            }
		        	@Override
		            public void payCancel(Map<String, String> payParams) {
		                // TODO Auto-generated method stub
		        		getDelegate().onPayResult(AccountType(),0);
		        		Log.e(TAG, "支付取消");
		            }
		        });
			}
		});
	}

	@Override
	public byte AccountType() {
		// TODO Auto-generated method stub
		return _UUMonAccount;
	}

	@Override
	public void CCGameLogin(JSONObject response) {
		// TODO Auto-generated method stub
		
	}
}
