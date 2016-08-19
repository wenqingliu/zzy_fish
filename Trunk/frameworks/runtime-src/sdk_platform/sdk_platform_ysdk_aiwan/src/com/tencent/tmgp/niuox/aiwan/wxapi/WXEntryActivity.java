package com.tencent.tmgp.niuox.aiwan.wxapi;

import org.json.JSONException;
import org.json.JSONObject;

import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate;
import com.tencent.mm.sdk.constants.ConstantsAPI;
import com.tencent.mm.sdk.modelbase.BaseReq;
import com.tencent.mm.sdk.modelbase.BaseResp;
import com.tencent.mm.sdk.modelmsg.SendAuth;
import com.tencent.ysdk.module.user.impl.wx.YSDKWXEntryActivity;
import com.umeng.socialize.weixin.view.WXCallbackActivity;

//自定义修改: YSDKWXEntryActivity 改成  WXCallbackActivity
public class WXEntryActivity extends YSDKWXEntryActivity {
	
	public WXCallbackActivity wxcall;
	/*
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
	}*/
	
	
	 @Override  
    public void onResp(BaseResp resp) {  
        // TODO Auto-generated method stub  
//        Toast.makeText(this,"resp.errCode:" + resp.errCode + ",resp.errStr:" + resp.errStr + ",tr"+resp.transaction,Toast.LENGTH_LONG).show(); 
		super.onResp(resp);
        if (resp.getType() == 2 && resp.errCode == BaseResp.ErrCode.ERR_OK) {  
//        	 Toast.makeText(this, "分享成功："+resp.transaction, Toast.LENGTH_LONG).show();
        	 JSONObject jobj = new JSONObject();
        	 try {
				jobj.put("platform", 2);
				jobj.put("stCode", 200);
				jobj.put("errorMsg", "");
				SDKControlOriginal.getDelegate().SendMessageWithParameters("share", jobj);
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        	
        }  
    }  
}
