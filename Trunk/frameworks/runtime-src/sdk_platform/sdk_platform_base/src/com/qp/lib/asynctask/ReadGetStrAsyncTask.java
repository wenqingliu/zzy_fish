package com.qp.lib.asynctask;

import com.qp.lib.utility.HttpManager;

import android.os.AsyncTask;

public class ReadGetStrAsyncTask extends AsyncTask<String, String, String> {
	public interface ReadPostExecute{
		public void onPostExecute(String str);
	}
	public String url;
	public String url_charset;
	public ReadPostExecute readPostExecute;
	public void addReadPostExecute(ReadPostExecute readPostExecute){
		this.readPostExecute = readPostExecute;
	}
	public ReadGetStrAsyncTask(String url){
		this.url = url;
		url_charset="UTF-8";
	}
	public ReadGetStrAsyncTask(String url,String url_charset){
		this.url = url;
		if(url_charset==null)
			url_charset="UTF-8";
		this.url_charset = url_charset;
	}
	@Override
	protected String doInBackground(String... arg0) {
		return 	HttpManager.httpgetStr(url, "UTF-8");
	}
	protected void onPostExecute(String s) {
		if(readPostExecute!=null)
			readPostExecute.onPostExecute(s);
		
	}
	 
}
