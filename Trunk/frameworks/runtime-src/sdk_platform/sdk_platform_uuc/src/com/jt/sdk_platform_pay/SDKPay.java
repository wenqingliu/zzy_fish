package com.jt.sdk_platform_pay;

import org.json.JSONObject;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKDelegate.OrderListener;

public class SDKPay extends com.jt.sdk_platform_base.SDKControlOriginal {
	private UucPay uucPay = null;
	
	@Override
	public void CCPay(JSONObject response) {
		// TODO Auto-generated method stub
		/*final ProductInfoItem item = ProductInfoItem.parseObject(response);
		if (uucPay == null) {
			initUucPay();
		}
		getDelegate().getOrderInfo(response, new OrderListener() {
			@Override
			public void onOrderResult(String order) {
				// TODO Auto-generated method stub
				uucPay.pay(order, item.getMoney()+"", item.getProductName(), item.getProductName(),
						item.getProductId(), "1", item.getUserID()+"",item.getDomainURL());
			}
		});*/
	}

	private void initUucPay() {
		// TODO Auto-generated method stub
		uucPay = new UucPay(_context);
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
	
