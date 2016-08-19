package com.qp.lib.asynctask;

import com.qp.lib.utility.HttpManager;

import android.os.AsyncTask;

public class ReadGetUrlAsyncTask extends AsyncTask<String, String, String> {
	public interface ReadGetExecute{
		public void onGetExecute(String str);
	}
	public String url;
	public String url_charset;
	public ReadGetExecute execute;
	public String cookies = null;
	
	public void addReadGetExecute(ReadGetExecute readGetExecute){
		this.execute = readGetExecute;
	}
	public ReadGetUrlAsyncTask(String url){
		this.url = url;
		url_charset="UTF-8";
	}
	public ReadGetUrlAsyncTask(String url,String url_charset){
		this.url = url;
		if(url_charset==null)
			url_charset="UTF-8";
		this.url_charset = url_charset;
	}
	
	public ReadGetUrlAsyncTask(String url,String url_charset,String cookie){
		this.url = url;
		if(url_charset==null)
			url_charset="UTF-8";
		this.url_charset = url_charset;
		this.cookies = cookie;
	}
	
	@Override
	protected String doInBackground(String... arg0) {
		return 	HttpManager.httpget(url, "UTF-8",this.cookies);
	}
	protected void onPostExecute(String s) {
		if(execute!=null)
			execute.onGetExecute(s);
	}
}
