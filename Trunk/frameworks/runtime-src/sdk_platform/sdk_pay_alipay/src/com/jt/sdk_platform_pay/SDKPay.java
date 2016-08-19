package com.jt.sdk_platform_pay;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.json.JSONException;
import org.json.JSONObject;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.qp.game.control.alipay.SDKAlipay;
import com.qp.game.control.alipay.SDKAlipay.PayListener;

public class SDKPay extends com.jt.sdk_platform_base.SDKControlOriginal implements PayListener {

	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		String id = "";
		String notify_url = "";
		try {
			id = response.getString("gameID");
			notify_url = response.getString("NotifyURL");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		ProductInfoItem item = ProductInfoItem.parseObject(response);
		SDKAlipay.getInstance((Cocos2dxActivity.getContext())).pay(id,item.getProductName(),
				item.getProductId(),item.getMoney()+"",notify_url,this);
	}
	
	@Override
	public void onPayResult(int result) {
		SDKControlOriginal.getDelegate().onPayResult(1,result);
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
