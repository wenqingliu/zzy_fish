
package com.qp.game.control.alipay;

import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.Random;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.alipay.sdk.app.PayTask;

public class SDKAlipay {
	public static final String TAG = "SDKAlipay";
	// 支付宝-start
	// 商户PID
	public static final String PARTNER = "2088011663161722";
	// 商户收款账号
	public static final String SELLER = "2088011663161722";
	// 商户私钥，pkcs8格式
//	public static final String RSA_PRIVATE = "MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAJ0TS7gXqSZmWU2UcfrIFQnm3d35TTsrWt1mLIpmbJhWMxqjn5tU0FC+ra0rBnwZSUahkwk1YgDrg4N3fG0KmcHJ/yMhqT45Nu9t/0JENEy6ZE1TOUY6ZP589mklsW5Dw9O/sVPlqPpTXgt0By+Dv5VsQDdTbDhqIb+gqY+tTOC/AgMBAAECgYEAhwZ8U787MABRikguhucSdtWYKeXSBygozyOy7DJJ7dZDzgWUAYIyJQcU40SWKX3PKMFiVUsneST7g7rmIhI3wy7sPDhAY3X2sj2alXz7U6JETsntrRsDkVGIfVJYIiwHCyBBv7aLo7Wkn+pVBSLObef0ElNLJZQ0E/45KZF9IOkCQQDKUmfTkXOcn9r3QszdmJs14JZI3Kwa8QFR3KYt+Uu7YCMWdSj0mf3LVTPbDoM5XBJQheOHSKJqiX+HYN3Gkwh1AkEAxr/FTerhCP46zQZJMFkerEMJ7+ZAUc67lnNvaEKw01DZgH5MREAAl67OxxXEQuuTsUYR+9qx426bhjtw1za94wJAFZg0EsXclCQPyAJuQVyvfFGrWL2M9RcyL92gMxn/tlEtjZEVvP3Os+w1K7Vh1jZ4kfWocmETTNG+NeHl6fL5nQJBAI0THIMFQPz4MFbNqm/WIo6V+1y87FTlUIQnpiG0jP1CO1EY1Rvw7jq8y2vHSItT2n8PxL4n6vML1PtAAAXTho8CQA2hl528jc/ZE25owe3MY/o1YZievtoeTqFnDUX7aUMILkTf01MI8xp6bSeniO9TsTuoDuCc54OWtUwMW/cR4nI=";
	
	public static final String RSA_PRIVATE = "MIICdgIBADANBgkqhkiG9w0BAQEFAASCAmAwggJcAgEAAoGBAMaTB8PqxPQcSRkVGvIyJUTCsRPu0g1jg8rutA1gycEDPFzO2eP8uu/6i+fbcA9C4YHbq4kLoAmxiRkww22dpi49f5mkrPzQgd2oCejVv3lJdeMkEQeMjfttpTzpeHsLvRV/50RdCI7cdd7FbUrzEWhSrackI+XKzdcqwrN0GnYZAgMBAAECgYBNPujoZ61SIKa24SToTmV9CBeGX4LKvomIKa9U/O++65lRqQ3NyISX0ekWuqAu7591upRR7XnGC4//gp6jR45bAguprrKoRwTXfNjnK0sthZ1B1EvKrddrwuVFkeRg685WZsMGGeyrYyP9YB6wHjVqq07SY56EigpKByJYUsUGeQJBAPuknwe7eupx+oIXf6BYFL1tqvtXtYxc+xmGWBa4/rdPW/xci8yFzPvu85UPkeVN8RkIAiLqjDdwuFs+sDuk+acCQQDKAzAr1OYyfMDE3Gt0uPuBDxLEyz6qEuaPCMcRgiS+y+R7EpMo/pOwDXNaBJdnzQ6BG6f+JGbOCdW2tZAsS4o/AkAn3SZMRUjthuzWWv6e2hU/BPaHJpfeCoTEwGGIB/ph87JwwgBrf+6/IlV4EaVdHAHLo1cjTOC1j6fE3KNyb2oVAkEAk0ANrfWLMoQDE7xDy5pHIcT1/mLUM66BRwOz74w48qa2zgs1H62pw6uaSKSOJIixKOUa6EJqeYdrs7nW9KK/iwJAOAJcJuEfXcrE7BS9IufQsqTo4A0JH6v0z9wZ1yDMi2d3laVHII+PJtif8wwDW8EWgQRTRu/USTNFsYlGGlE87A==";
	
	// 支付宝公钥
	public static final String RSA_PUBLIC = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCnxj/9qwVfgoUh/y2W89L6BkRAFljhNhgPdyPuBV64bfQNN1PjbCzkIM6qRdKBoLPXmKKMiFYnkd6rAoprih3/PrQEB/VsW8OoM8fxn67UDYuyBTqA23MML9q1+ilIZwBC2AQ2UBVOrFXfFl75p6/B5KsiNG9zpgmLCUYuLkxpLQIDAQAB";

	// 支付宝-end
//	public static String UrlLogin = "http://www.hj663.com";
	private static final int SDK_PAY_FLAG = 1;

	private static final int SDK_CHECK_FLAG = 2;

	private Context context;
	private static SDKAlipay instance;
	private PayListener pl;
	
	public interface PayListener {
		/**
		 * 
		 * @param status 状态1(成功),其他为失败
		 */
		void onPayResult(int result);
	}

	public SDKAlipay(Context context) {
		// TODO Auto-generated constructor stub
		this.context = context;
	}

	private Handler mHandler = new Handler() {
		public void handleMessage(Message msg) {
			switch (msg.what) {
			case SDK_PAY_FLAG: {
				PayResult payResult = new PayResult((String) msg.obj);

				// 支付宝返回此次支付结果及加签，建议对支付宝签名信息拿签约时支付宝提供的公钥做验签
				String resultInfo = payResult.getResult();

				String resultStatus = payResult.getResultStatus();

				// 判断resultStatus 为“9000”则代表支付成功，具体状态码代表含义可参考接口文档
				if (TextUtils.equals(resultStatus, "9000")) {
					SDKAlipay.this.pl.onPayResult(1);
//					Toast.makeText(context, "购买成功", Toast.LENGTH_SHORT).show();
				} else {
					// 判断resultStatus 为非“9000”则代表可能支付失败
					// “8000”代表支付结果因为支付渠道原因或者系统原因还在等待支付结果确认，最终交易是否成功以服务端异步通知为准（小概率状态）
					if (TextUtils.equals(resultStatus, "8000")) {
						SDKAlipay.this.pl.onPayResult(0);
//						Toast.makeText(context, "支付结果确认中", Toast.LENGTH_SHORT)
//								.show();

					} else {
						SDKAlipay.this.pl.onPayResult(-1);
						// 其他值就可以判断为支付失败，包括用户主动取消支付，或者系统返回的错误
//						Toast.makeText(context, "支付失败", Toast.LENGTH_SHORT)
//								.show();

					}
				}
				break;
			}
			case SDK_CHECK_FLAG: {
				Toast.makeText(context, "检查结果为：" + msg.obj, Toast.LENGTH_SHORT)
						.show();
				break;
			}
			default:
				break;
			}
		};
	};

	/**
	 * call alipay sdk pay. 调用SDK支付
	 * @param Gid 玩家ID
	 * @param subject	产品标题
	 * @param productId 产品ID(自定义)，支付宝文档中为产品描叙
	 * @param price	价格
	 * @param listener 结果响应 
	 */
	public void pay(String Gid,String subject, String productId, String price,String notify_url,PayListener listener) {
//		this.currentProduct = item;
		this.pl = listener;

		// 订单
		String orderInfo = getOrderInfo(Gid,subject, productId, price,notify_url);

		// 对订单做RSA 签名
		String sign = sign(orderInfo);
		try {
			// 仅需对sign 做URL编码
			sign = URLEncoder.encode(sign, "UTF-8");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}

		// 完整的符合支付宝参数规范的订单信息
		final String payInfo = orderInfo + "&sign=\"" + sign + "\"&"
				+ getSignType();

		Runnable payRunnable = new Runnable() {

			@Override
			public void run() {
				// 构造PayTask 对象
				PayTask alipay = new PayTask((Activity) context);
				// 调用支付接口，获取支付结果
				String result = alipay.pay(payInfo);

				Message msg = new Message();
				msg.what = SDK_PAY_FLAG;
				msg.obj = result;
				mHandler.sendMessage(msg);
			}
		};

		// 必须异步调用
		Thread payThread = new Thread(payRunnable);
		payThread.start();
	}

	/**
	 * check whether the device has authentication alipay account.
	 * 查询终端设备是否存在支付宝认证账户
	 * 
	 */
	public void check(View v) {
		Runnable checkRunnable = new Runnable() {

			@Override
			public void run() {
				// 构造PayTask 对象
				PayTask payTask = new PayTask((Activity) context);
				// 调用查询接口，获取查询结果
				boolean isExist = payTask.checkAccountIfExist();

				Message msg = new Message();
				msg.what = SDK_CHECK_FLAG;
				msg.obj = isExist;
				mHandler.sendMessage(msg);
			}
		};

		Thread checkThread = new Thread(checkRunnable);
		checkThread.start();

	}

	/**
	 * get the sdk version. 获取SDK版本号
	 * 
	 */
	public void getSDKVersion() {
		PayTask payTask = new PayTask((Activity) context);
		String version = payTask.getVersion();
		Toast.makeText((Activity) context, version, Toast.LENGTH_SHORT).show();
	}

	/**
	 * create the order info. 创建订单信息
	 * 
	 */
	private String getOrderInfo(String Gid,String subject, String body, String price,String notify_url) {
		// 签约合作者身份ID
		String orderInfo = "partner=" + "\"" + PARTNER + "\"";

		// 签约卖家支付宝账号
		orderInfo += "&seller_id=" + "\"" + SELLER + "\"";

		// 商户网站唯一订单号
		orderInfo += "&out_trade_no=" + "\"" + getOutTradeNo(Gid) + "\"";

		// 商品名称
		orderInfo += "&subject=" + "\"" + subject + "\"";

		// 商品详情
		orderInfo += "&body=" + "\"" + body + "\"";

		// 商品金额
		orderInfo += "&total_fee=" + "\"" + price + "\"";

		// 服务器异步通知页面路径
		orderInfo += "&notify_url=" + "\"" + notify_url + "\"";

		// 服务接口名称， 固定值
		orderInfo += "&service=\"mobile.securitypay.pay\"";

		// 支付类型， 固定值
		orderInfo += "&payment_type=\"1\"";

		// 参数编码， 固定值
		orderInfo += "&_input_charset=\"utf-8\"";

		// 设置未付款交易的超时时间
		// 默认30分钟，一旦超时，该笔交易就会自动被关闭。
		// 取值范围：1m～15d。
		// m-分钟，h-小时，d-天，1c-当天（无论交易何时创建，都在0点关闭）。
		// 该参数数值不接受小数点，如1.5h，可转换为90m。
		orderInfo += "&it_b_pay=\"30m\"";

		// extern_token为经过快登授权获取到的alipay_open_id,带上此参数用户将使用授权的账户进行支付
		// orderInfo += "&extern_token=" + "\"" + extern_token + "\"";

		// 支付宝处理完请求后，当前页面跳转到商户指定页面的路径，可空
		orderInfo += "&return_url=\"m.alipay.com\"";

		// 调用银行卡支付，需配置此参数，参与签名， 固定值 （需要签约《无线银行卡快捷支付》才能使用）
		// orderInfo += "&paymethod=\"expressGateway\"";

		return orderInfo;
	}

	/**
	 * get the out_trade_no for an order. 生成商户订单号，该值在商户端应保持唯一（可自定义格式规范）
	 * 
	 */
	public String getOutTradeNo(String GameId) {
		SimpleDateFormat format = new SimpleDateFormat("MMddHHmmss");
		Date date = new Date();
//		String key = date.getTime()+"";
		String key = format.format(date);

		java.util.Random r = new java.util.Random();
		key += Math.abs(r.nextLong());
		key = key.substring(0, 15);
		Log.d(TAG, "outTradeNo: " + key);
		return key + "UID-" + GameId;
	}

	/**
	 * sign the order info. 对订单信息进行签名
	 * 
	 * @param content
	 *            待签名订单信息
	 */
	public String sign(String content) {
		return SignUtils.sign(content, RSA_PRIVATE);
	}

	/**
	 * get the sign type we use. 获取签名方式
	 * 
	 */
	public String getSignType() {
		return "sign_type=\"RSA\"";
	}

	public static SDKAlipay getInstance(Context context) {
		if (instance == null) {
			instance = new SDKAlipay(context);
		}
		return instance;
	}

}
