package com.jt.sdk_platform_uumon;


import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

import org.json.JSONException;
import org.json.JSONObject;

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
public class uumonPay extends com.jt.sdk_platform_base.SDKControlOriginal{
	private String TAG = "uumonSDK";
    private String productName = "";
    private long productPrice = 0;
    static private uumonPay instance = null;
    
	static public uumonPay getInstance(Activity activity){
		/** SDK��ʼ�� */
		if (instance == null) {
			instance = new uumonPay();
			JNEPay.init(activity);
		}
		return instance;
	}
	
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		ProductInfoItem item = ProductInfoItem.parseObject(response);
		Log.i(TAG, "===CCPay is called===");
		String id = "";
		String notify_url = "";
		String product_price = "";
		String product_id= "";
		String product_name = "";
		String product_dec = "";
		try {
			id = response.getString("gameID");
			notify_url = response.getString("domainURL")+"/lenoticeurl.aspx";
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		product_price = String.valueOf(item.getMoney());
		product_name = item.getProductName();
		product_dec = item.getDesc();
		product_id = item.getProductId();
		productName = product_name;
		productPrice = (long) (Float.parseFloat(product_price)*100); //转化分为单位
		
		productPrice = 1;
//		productPrice = 1;
		getDelegate().getOrderInfo(response, new OrderListener() {
			
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub
		        HashMap<String, String> payParams = new HashMap<String, String>();
		        payParams.put(JNEPay.PayParams.KEY_TOOLS_NAME, productName); // 道具名称
		        payParams.put(JNEPay.PayParams.KEY_TOOLS_PRICE, productPrice + "");// 道具价格   单位: 分
		        payParams.put(JNEPay.PayParams.KEY_CP_ORDERID,order); // CP订单号
		        
		        JNEPay.pay((Activity) _context, payParams, new JNEPayListener() {
		        	@Override
		            public void paySuccess(Map<String, String> payParams) {
		                // TODO Auto-generated method stub
		        		getDelegate().onPayResult(13,1);
		        		Log.e(TAG, "支付成功");
		            }
		        	@Override
		            public void payFailed(Map<String, String> payParams, int reasonCode) {
		                // TODO Auto-generated method stub
		        		getDelegate().onPayResult(13,0);
		        		Log.e(TAG, "支付错误："+reasonCode);
		            }
		        	@Override
		            public void payCancel(Map<String, String> payParams) {
		                // TODO Auto-generated method stub
		        		getDelegate().onPayResult(13,0);
		        		Log.e(TAG, "支付取消");
		            }
		        });
			}
		});
	}

	@Override
	public byte AccountType() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public void CCGameLogin(JSONObject response) {
		// TODO Auto-generated method stub
		
	}
}
