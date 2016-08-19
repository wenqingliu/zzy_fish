package com.qp.lib.utility;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.util.HashMap;

import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.json.JSONObject;

import android.util.Log;

public class HttpManager {
	public static String httpgetStr(String url,String url_charset)
	{
  
			HttpClient client = new DefaultHttpClient();
			StringBuilder builder = new StringBuilder();
 
			HttpGet get = new HttpGet( url  );
			try {
				HttpResponse response = client.execute(get);
				BufferedReader reader = new BufferedReader(new InputStreamReader(response.getEntity().getContent(),url_charset));
				  
				for (String s = reader.readLine(); s != null; s = reader.readLine()) {
					builder.append(s);
				
				}
 
			} catch (Exception e) {
				e.printStackTrace();
				return "";
			}
  
			return  builder.toString();
	}
	public static String httpget(String url,String url_charset)
	{
  
			HttpClient client = new DefaultHttpClient();
			StringBuilder builder = new StringBuilder();
 
			HttpGet get = new HttpGet( url  );
			try {
				HttpResponse response = client.execute(get);
				BufferedReader reader = new BufferedReader(new InputStreamReader(response.getEntity().getContent(),url_charset));
				  
				for (String s = reader.readLine(); s != null; s = reader.readLine()) {
					builder.append(s);
					builder.append("\r\n");
				}
 
			} catch (Exception e) {
				e.printStackTrace();
				return "";
			}
  
			return  builder.toString();
	}
	
	public static String httpget(String url,String url_charset,String cookies)
	{
			Log.d("HttpManager", url);
			HttpClient client = new DefaultHttpClient();
			StringBuilder builder = new StringBuilder();
 
			HttpGet get = new HttpGet( url  );
			if(cookies!=null){
				get.addHeader("Cookie",cookies);
			}
			try {
				HttpResponse response = client.execute(get);
				BufferedReader reader = new BufferedReader(new InputStreamReader(response.getEntity().getContent(),url_charset));
				  
				for (String s = reader.readLine(); s != null; s = reader.readLine()) {
					builder.append(s);
					builder.append("\r\n");
				}
 
			} catch (Exception e) {
				e.printStackTrace();
				return "";
			}
  
			return  builder.toString();
	}
	
	public static String httpPost(String url,String url_charset,String cookies,JSONObject jsonParam)
	{
  
			HttpClient client = new DefaultHttpClient();
			StringBuilder builder = new StringBuilder();
			
			HttpPost post = new HttpPost( url);
			post.addHeader("Cookie",cookies);
			
			 // 接收参数json列表  
			StringEntity entity = null;
			try {
				entity = new StringEntity(jsonParam.toString(),"utf-8");
				entity.setContentEncoding("UTF-8");    
				entity.setContentType("application/json");    
				post.setEntity(entity);    
			} catch (UnsupportedEncodingException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
			try {
				HttpResponse response = client.execute(post);
				BufferedReader reader = new BufferedReader(new InputStreamReader(response.getEntity().getContent(),url_charset));
				  
				for (String s = reader.readLine(); s != null; s = reader.readLine()) {
					builder.append(s);
					builder.append("\r\n");
				}
 
			} catch (Exception e) {
				e.printStackTrace();
				return "";
			}
  
			return  builder.toString();
	}
}
