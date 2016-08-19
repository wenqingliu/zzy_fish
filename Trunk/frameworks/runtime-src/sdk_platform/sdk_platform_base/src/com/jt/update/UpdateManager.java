package com.jt.update;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.HashMap;

import org.json.JSONException;
import org.json.JSONObject;

import com.jt.sdk_platform_base.R;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_base.SDKDelegate;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager.NameNotFoundException;
import android.net.Uri;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.view.Gravity;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.view.View.OnClickListener;
import android.widget.RemoteViews;
import android.widget.TextView;
import android.widget.Toast;

/**
 * @author coolszy
 * @date 2012-4-26
 * @blog http://blog.92coding.com
 */

public class UpdateManager {
	
	/* 开始下载*/
	private static final int DOWNLOAD_START = 0;
	/* 下载中 */
	private static final int DOWNLOAD = 1;
	/* 下载结束 */
	private static final int DOWNLOAD_FINISH = 2;
	/* 下载出错 */
	private static final int DOWNLOAD_ERROR = 3;

	/* 下载保存路径 */
	private String mSavePath;
	/* 记录进度条数量 */
	private int progress;
	/* 是否取消更新 */
	private boolean cancelUpdate = false;

	private Context mContext;
	/* 更新进度条 */
	// 是否更新版本对话框
	private Dialog downDialog = null;
	private Dialog mDialog = null;
	
	private int mProgeress;
	
//	private HashMap<String, String> mHashMap;
	
	/*
	 private Notification mDownNotification;    
	 private NotificationManager mnotiManage;   
	 private RemoteViews mContentView; // 下载进度View    
	 private PendingIntent mDownPendingIntent;    
*/
	
	private String mFileName;
	private String mFileURL;
	
	private Handler mHandler = new Handler() {
		public void handleMessage(Message msg) {
			switch (msg.what) {
			case DOWNLOAD_START://开始下载
				JSONObject j1 = new JSONObject();
				try {
					j1.put("progress",0);
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				SDKControlOriginal.getDelegate().SendMessageWithParameters("ccNd_Progress",j1);
				break;
			case DOWNLOAD:// 正在下载
				int pro = (Integer) msg.obj;
				if(mProgeress!=pro){
					JSONObject j2 = new JSONObject();
					try {
						j2.put("progress", ((float)pro)/100);
					} catch (JSONException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					SDKControlOriginal.getDelegate().SendMessageWithParameters("ccNd_Progress",j2);
					mProgeress = pro;
				}
				break;
			case DOWNLOAD_FINISH://下载完成
				JSONObject j3 = new JSONObject();
				try {
					j3.put("progress", 1);
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				SDKControlOriginal.getDelegate().SendMessageWithParameters("ccNd_Progress",j3);
				// 安装文件
				installApk();
				break;
			case DOWNLOAD_ERROR://下载出错
				Toast.makeText(mContext,msg.obj.toString(), Toast.LENGTH_LONG).show();
				JSONObject j4 = new JSONObject();
				try {
					j4.put("progress", -1);
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				SDKControlOriginal.getDelegate().SendMessageWithParameters("ccNd_Progress",j4);
			default:
				break;
			}
		};
	};

	public UpdateManager(Context context) {
		this.mContext = context;
	}

	/**
	 * 检测软件更新
	 */
	public boolean checkUpdate() {
		if (isUpdate()) {
			// 显示提示对话框
//			showNoticeDialog();
//			startDownloadApk();
			return true;
		} else {
//			ToastManager.show((Activity) mContext, "已经是最新版本");
			Toast.makeText(this.mContext,"已经是最新版本",Toast.LENGTH_LONG).show();
			return false;
		}
	}

	/**
	 * 检查软件是否有更新版本
	 * 
	 * @return
	 */
	private boolean isUpdate() {
		// 获取当前软件版本
		/*int versionCode = getVersionCode(mContext);
		// 把version.xml放到网络上，然后获取文件信息
		InputStream inStream = ParseXmlService.class.getClassLoader()
				.getResourceAsStream("version.xml");
		// 解析XML文件。 由于XML文件比较小，因此使用DOM方式进行解析
		ParseXmlService service = new ParseXmlService();
		try {
			mHashMap = service.parseXml(inStream);
		} catch (Exception e) {
			e.printStackTrace();
		}
		if (null != mHashMap) {
			int serviceCode = Integer.valueOf(mHashMap.get("version"));
			// 版本判断
			if (serviceCode > versionCode) {
				return true;
			}
		}*/
//		mHashMap = new HashMap<String, String>();
//		mHashMap.put("url","http://gdown.baidu.com/data/wisegame/b50cdd3d72d80935/QQ_336.apk");
//		mHashMap.put("name","NiuOxCC");
		
		return true;
	}

	/**
	 * 获取软件版本号
	 * 
	 * @param context
	 * @return
	 */
	private int getVersionCode(Context context) {
		int versionCode = 0;
		try {
			// 获取软件版本号，对应AndroidManifest.xml下android:versionCode
			versionCode = context.getPackageManager().getPackageInfo(
					"com.sp2p", 0).versionCode;
		} catch (NameNotFoundException e) {
			e.printStackTrace();
		}
		return versionCode;
	}

	/**
	 * 下载apk文件
	 */
	public void startDownloadApk(String url) {
		// 启动新线程下载软件
		
		mFileURL = url;
//		mFileName = url.substring(url.lastIndexOf("/")+1,url.length());
		mFileName = "niuox_" + JniHelper.getSDKPlatform() + ".apk";
		
		new downloadApkThread().start();
	}

	/**
	 * 下载文件线程
	 * 
	 * @author coolszy
	 * @date 2012-4-26
	 * @blog http://blog.92coding.com
	 */
	private class downloadApkThread extends Thread {
		@Override
		public void run() {
			try {
				// 判断SD卡是否存在，并且是否具有读写权限
				if (Environment.getExternalStorageState().equals(
						Environment.MEDIA_MOUNTED)) {
					// 获得存储卡的路径
					String sdpath = Environment.getExternalStorageDirectory()
							+ "/";
					mSavePath = sdpath + "download";
					URL url = new URL(mFileURL);
					// 创建连接
					HttpURLConnection conn = (HttpURLConnection) url
							.openConnection();
					conn.connect();
					// 获取文件大小
					int length = conn.getContentLength();
					// 创建输入流
					InputStream is = conn.getInputStream();

					File file = new File(mSavePath);
					// 判断文件目录是否存在
					if (!file.exists()) {
						file.mkdir();
					}
					File apkFile = new File(mSavePath, mFileName);
					FileOutputStream fos = new FileOutputStream(apkFile);
					
					Message msg = mHandler.obtainMessage();
					msg.obj = progress;
					msg.what = DOWNLOAD_START;
					// 更新进度
					mHandler.sendMessage(msg);
					
					int count = 0;
					// 缓存
					byte buf[] = new byte[1024];
					// 写入到文件中
					do {
						int numread = is.read(buf);
						count += numread;
						// 计算进度条位置
						progress = (int) (((float) count / length) * 100);
						msg = mHandler.obtainMessage();
						msg.obj = progress;
						msg.what = DOWNLOAD;
						// 更新进度
						mHandler.sendMessage(msg);
						if (numread <= 0) {
							// 下载完成
							mHandler.sendEmptyMessage(DOWNLOAD_FINISH);
							break;
						}
						// 写入文件
						fos.write(buf, 0, numread);
					} while (!cancelUpdate);// 点击取消就停止下载.
					fos.close();
					is.close();
				}
			} catch (MalformedURLException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
			//非正常下载完毕
			if(progress!=100){
				Message msg = mHandler.obtainMessage();
				msg.obj = "网络错误，下载失败，请重新点击下载更新";
				msg.what = DOWNLOAD_ERROR;
				// 更新进度
				mHandler.sendMessage(msg);
			}
		}
	};
	
	/**
	 * 下载文件线程
	 * 
	 * @author coolszy
	 * @date 2012-4-26
	 * @blog http://blog.92coding.com
	 */
	public void getFileSize(final Handler handler,final String urlStr) {
		Thread thread = new Thread() {
			@Override
			public void run() {
				try {
					URL url = new URL(urlStr);
					// 创建连接
					HttpURLConnection conn = (HttpURLConnection) url
							.openConnection();
					conn.connect();
					// 获取文件大小
					int length = conn.getContentLength();
					InputStream is = conn.getInputStream();
					is.close();
					Message msg = handler.obtainMessage();
					msg.what = 1;
					msg.obj = length;
					handler.sendMessage(msg);
				} catch (Exception e) {
					e.printStackTrace();
					Message msg = handler.obtainMessage();
					msg.what = DOWNLOAD_ERROR;
					msg.obj = "下载地址已失效，更新失败";
					mHandler.sendMessage(msg);
				}
			}
		};
		thread.start();
	}

	/**
	 * 安装APK文件
	 */
	private void installApk() {
		File apkfile = new File(mSavePath, mFileName);
		if (!apkfile.exists()) {
			return;
		}
		// 通过Intent安装APK文件
		Intent i = new Intent(Intent.ACTION_VIEW);
		i.setDataAndType(Uri.parse("file://" + apkfile.toString()),
				"application/vnd.android.package-archive");
		mContext.startActivity(i);
	}
	
}
