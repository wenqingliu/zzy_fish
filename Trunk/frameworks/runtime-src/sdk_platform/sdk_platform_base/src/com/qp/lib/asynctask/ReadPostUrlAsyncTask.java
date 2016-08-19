package com.qp.lib.asynctask;

import org.json.JSONObject;

import com.qp.lib.utility.HttpManager;

import android.os.AsyncTask;

public class ReadPostUrlAsyncTask extends AsyncTask<String, String, String> {
	public interface ReadPostExecute{
		public void onPostExecute(String str);
	}
	public String url;
	public String url_charset = "UTF-8";
	public String cookies = "";
	public JSONObject params;
	public ReadPostExecute readPostExecute;
	
	public void addReadPostExecute(ReadPostExecute readPostExecute){
		this.readPostExecute = readPostExecute;
	}
	
	public ReadPostUrlAsyncTask(String url,String cookies,JSONObject params){
		this.url = url;
		this.cookies = cookies;
		this.params = params;
	}
	
	@Override
	protected String doInBackground(String... arg0) {
		return 	HttpManager.httpPost(url,url_charset,cookies,this.params);
	}
	
	protected void onPostExecute(String s) {
		if(readPostExecute!=null)
			readPostExecute.onPostExecute(s);
	}
	 
}
