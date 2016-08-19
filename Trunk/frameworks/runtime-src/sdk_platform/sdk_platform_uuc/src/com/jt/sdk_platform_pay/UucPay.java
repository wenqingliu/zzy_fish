package com.jt.sdk_platform_pay;

import java.text.SimpleDateFormat;
import java.util.Date;

import android.app.Activity;
import android.content.Context;
import android.content.pm.ActivityInfo;
import android.util.Log;
import android.widget.Toast;

import com.blocks.thirdpay.AppConnect;
import com.blocks.thirdpay.FeeCallBack;
import com.jt.sdk_platform_base.SDKControlOriginal;

public class UucPay {
	// 您需要修改ChannelId,例如"uucun-market"
	private static final String ChannelId = "uucun-market";

	// 订单号，相同的订单号可能会返回错�?
	// private String orderId = "1200";

	// 应用密钥
	private String appKey = "aUdNC8cE7ycqnC23Juk0KtjNGzeYObLD";//

	// 安全密钥
	private String encryptKey = "FFtHqk";//

	// 金额，以分为单位
	// private String money = "100";

	// 通知支付结果地址
	private String merUrl;

	// 为预留字段，填入null
	private String bgRetUrl = null;

	// 虚拟货币汇率(1元人民币对应的虚拟币�?)，例如： 100
	// private String virtualMoneyOneYuan = "100";

	// 虚拟货币名称,例如�? “元宝�??
	// private String virtualMoneyName = "元宝";

	// 物品名称，例如： “霜之哀伤�??
	// private String goodsName = "霜之�?�?";

	// 物品数量，例如： 2
	// private String goodsNum = "2";

	// 物品编号
	// private String goodsNo = "10002";

	// 交易时间：格式yyyymmddHHMMss
	// private String timeString = "20121026120312";


	// cp游戏自身userid
	// private String cpUserId;

	private Context _context;
	private int lastOrientation;

	public UucPay(Context context) {
		this._context = context;
		AppConnect.getInstance(_context).sendActivation(
				"aUdNC8cE7ycqnC23Juk0KtjNGzeYObLD");
	}

	public void finalize() {
		AppConnect.getInstance(this._context).finalize();
	}

	public void pay(String orderId, String money, String virtualMoneyName,
			String goodsName, String goodsNo, String goodsNum, String cpUserId,
			String ip,String uupayPassId) {

		merUrl = ip + "/uucnoticeurl.aspx";

		// 当前时间
		Date currentTime = new Date();
		SimpleDateFormat formatter = new SimpleDateFormat("yyyyMMddHHmmss");
		String dateString = formatter.format(currentTime);

		String moneyStr = (int)(Float.parseFloat(money) * 100)+"";
		lastOrientation = ((Activity) _context).getRequestedOrientation();
		if (lastOrientation != ActivityInfo.SCREEN_ORIENTATION_PORTRAIT) {
			((Activity) _context)
					.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
		}

		// 启动支付插件接口
		AppConnect.getInstance(_context).pay(orderId, appKey, encryptKey,
				moneyStr, merUrl, bgRetUrl, 10, virtualMoneyName, goodsName,
				Integer.valueOf(goodsNum), goodsNo, dateString, null,
				getBack(), uupayPassId, cpUserId, null, null);
	}

	/**
	 * 客户端�?�知回调方法
	 * 
	 * @return
	 */
	private FeeCallBack getBack() {
		return new FeeCallBack() {
			public void onStart() {
				Log.e("FeeCallBack", "支付开始");
//				Toast.makeText(_context, "callback:支付开始", Toast.LENGTH_SHORT);
			}

			public void onEnd() {
				if (((Activity) _context).getRequestedOrientation() != lastOrientation) {
					((Activity) _context)
							.setRequestedOrientation(lastOrientation);
				}
//				Log.e("FeeCallBack", "支付结束");
//				Toast.makeText(_context, "支付结束", Toast.LENGTH_SHORT).show();
			}

			public void onOrderSuccess() {
//				Log.e("FeeCallBack", "订单提交成功");
				Toast.makeText(_context, "订单提交成功,到账有延迟,钻石将在1-3分钟到账，清稍等", Toast.LENGTH_SHORT).show();
				if (((Activity) _context).getRequestedOrientation() != lastOrientation) {
					((Activity) _context)
							.setRequestedOrientation(lastOrientation);
				}
				SDKControlOriginal.getDelegate().onPayResult(5,1);
			}

			public void onOrderError(int errorType, String msg) {
//				Log.e("FeeCallBack", "支付错误  type = " + errorType + ", msg = "
//						+ msg);
//				Toast.makeText(_context, "支付错误:" + msg, Toast.LENGTH_SHORT).show();
				if (((Activity) _context).getRequestedOrientation() != lastOrientation) {
					((Activity) _context)
							.setRequestedOrientation(lastOrientation);
				}
				SDKControlOriginal.getDelegate().onPayResult(5,0);
			}
		};
	}
}
