import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

public class Main {
	private static String versionCode = "";
	private static String versionName = "";
	private static int platform = Integer.MAX_VALUE;//渠道
	private static String compiledMode;//编译模式

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		if(args.length==2){
			platform = Integer.parseInt(args[1]);
		}else if(args.length==0){
			System.out.println("参数错误,args.length："+args.length);
			return;
		}
		compiledMode = args[0];

		readConfig();

	}

	public static void readConfig() {
		// 获取配置文件
		String root = "";
		StringBuilder content = new StringBuilder();
		try {
			File directory = new File( "");// 参数为空
			root = directory.getCanonicalPath();
			
			if(!new File(root + "/sdk_platform_config.json").exists()){
				//java工程运行模式下
				//获取上级目录配置
				root = root.substring(0, root.lastIndexOf("\\"));
			}
			String courseFile = root + "/sdk_platform_config.json";

			FileInputStream fis = new FileInputStream(courseFile);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}
			System.out.println("读取配置成功："+courseFile);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		if(content.length()==0){
			return;
		}
		
		// 修改配置
		JSONObject jsdk = null;
		JSONObject jobj = null;
		JSONObject sdk = null;
		String apkName = null;
		try {

			jobj = JSONObject.fromObject(content.toString());
			jsdk = jobj.getJSONObject("sdk_platform");
			versionCode = jobj.getString("versionCode");
			versionName = jobj.getString("versionName");
			System.out.println("目标版本号:"+versionCode);
			System.out.println("目标版本名称:"+versionName);

		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
			return;
		}
		
		int targetCount = 0;
		int totalCount = platform == Integer.MAX_VALUE ? jsdk.size() : 1;
		
		do{
			try{
				if(platform!=Integer.MAX_VALUE){
					//打包单个渠道包
					sdk = jsdk.getJSONObject("sdk_platform_"+platform);
				}else{
					Iterator it = jsdk.keys(); 
					int currentCount = 0;
		            while (it.hasNext()) {
		            	String key = (String) it.next();
		            	if(currentCount==targetCount){
		            		sdk = jsdk.getJSONObject(key);
		            		break;
		            	}
	            		currentCount++;
		            }
				}
				targetCount++;
	            if(sdk.isNullObject()){
	            	System.out.println("当前渠道参数无效, platform："+platform);
	            	continue;
	            }
	            
	            //修改版本号,版本名称
	            String path = root + sdk.getString("path") + "\\AndroidManifest.xml";
	            changeVersion(path, versionCode, versionName,false);
		        
				// 修改项目引用
				JSONArray jarrRef = JSONArray
						.fromObject(sdk.getString("reference"));
				changeReference(root + "/proj.android/project.properties", jarrRef);
				
				//修改项目签名文件
				String keystore = sdk.getString("keystore");
				changeKeystore(root + "/proj.android/ant.properties",keystore);
				
				//修改导出的APK名
				apkName = sdk.getString("apkname");
				changeApkName(root+"/proj.android/build.xml",apkName);
			} catch (Exception e) {
				// TODO: handle exception
				e.printStackTrace();
				break;
			}
			
			System.out.println("开始复制项目文件");
			String cmd = null;
			// 替换AndroidManifest.xml文件
			String input = root + (sdk.getString("path")) + "\\AndroidManifest.xml";
			String out = (root + "\\proj.android");
			cmd = "cmd.exe /C copy " + input + " " + out;
			runCmd(cmd,null);
			
			//开启推送
			boolean isPush = sdk.getBoolean("isPush");
			changePush(out+"\\AndroidManifest.xml",isPush);
			
			if(compiledMode.equals("change")){
				System.out.println("修改项目配置完毕");
			}else if(compiledMode.equals("debug") || compiledMode.equals("release")){
				System.out.println("开始渠道打包，本次打包apk渠道：" + apkName);
				//使用前需先clean
				cmd = "cmd.exe /C " + "ant clean";
				runCmd(cmd,root+"\\proj.android");
				
				//导出发行版
//				cmd = "cmd.exe /C " + "cocos compile -p android -m release";
				cmd = "cmd.exe /C " + "ant " + compiledMode;
				runCmd(cmd,root+"\\proj.android");
				
				if(compiledMode.equals("release")){
//					String FileStr = root+ "\\..\\..\\publish\\android\\" + apkName + "-release-signed.apk";
					String FileStr = root+ "\\proj.android\\bin\\" + apkName + "-release.apk";
					File apkFlie = new File(FileStr);
					if(apkFlie.exists()){
						//将导出的APK重命名
						cmd = "cmd.exe /C " + "rename " + FileStr + " "  + apkName + ".apk";
						runCmd(cmd,null);
						System.out.println("apk文件重命名：" + apkName + ".apk");
						System.out.println("移动apk至publish目录");
						cmd = "cmd.exe /C move " + root + "\\proj.android\\bin\\" + apkName + ".apk" + " " + root+ "\\..\\..\\publish\\android\\";
						runCmd(cmd,null);
						System.out.println("渠道打包完毕 ，本次打包APK渠道："+apkName);
					}else{
						System.out.println("渠道打包失败，未生成apk文件："+apkName);
					}
				}else{
					
				}
			}
		}while(targetCount<totalCount);
		
	}
		
	public static void changeVersion(String path, String versionCode,
			String versionName,boolean isOpenPush) {
		// long startT = System.currentTimeMillis();
		// System.out.println("start time:" + startT);
		try {
			// 读取文件
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}

			// 替换版本号
			String regex = "android:versionCode=\"\\d+\"";
			Pattern pattern = Pattern.compile(regex);
			Matcher matcher = pattern.matcher(content);
			if (matcher.find()) {
				content = content.replace(matcher.start(), matcher.end(),
						"android:versionCode=\"" + versionCode + "\"");
			}

			// 替换版本名称
			regex = "android:versionName=\".*\"";
			pattern = Pattern.compile(regex);
			matcher = pattern.matcher(content);
			if (matcher.find()) {
				content = content.replace(matcher.start(), matcher.end(),
						"android:versionName=\"" + versionName + "\"");
			}

			br.close();
			isr.close();
			// 写入文件
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();

		} catch (IOException e) {
			e.printStackTrace();

		}
	}
	
	public static void changePush(String path,boolean isOpenPush) {
		// long startT = System.currentTimeMillis();
		// System.out.println("start time:" + startT);
		try {
			// 读取文件
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}
			
			if(isOpenPush){
				String regex = "<!--JPush-permission-start";
				Pattern pattern = Pattern.compile(regex);
				Matcher matcher = pattern.matcher(content);
				if (matcher.find()) {
					content = content.replace(matcher.start(), matcher.end(),"");
				}
				
				regex = "JPush-permission-end-->";
				pattern = Pattern.compile(regex);
				matcher = pattern.matcher(content);
				if (matcher.find()) {
					content = content.replace(matcher.start(), matcher.end(),"");
				}
			}

			br.close();
			isr.close();
			// 写入文件
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();

		} catch (IOException e) {
			e.printStackTrace();

		}
	}
	
	// 修改签名
	public static void changeKeystore(String path,String store) {
		try {
			// 读取文件
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}

			// 替换签名
			String regex = "key.store=.*?\\r\\n";
			Pattern pattern = Pattern.compile(regex);
			Matcher matcher = pattern.matcher(content);
			if (matcher.find()) {
				content = content.replace(matcher.start(), matcher.end(),
						"key.store=" + store + "\r\n");
			}

			br.close();
			isr.close();
			// 写入文件
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
			System.out.println("修改签名成功：key.store="+store);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// 修改引用
	public static void changeReference(String path, JSONArray jarr) {
		try {
			// 读取文件
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}

			// 替换库引用
			String regex = "android.library.reference.";
			int index = content.indexOf(regex);
			if (index != -1) {
				content = content.delete(index, content.length());
			}

			for (int i = 0; i < jarr.size(); i++) {
				String ref = regex + "" + (i + 1) + "="
						+ jarr.get(i).toString();
				System.out.println("引用库：" + ref);
				content.append(ref);
				content.append("\r\n");
			}

			br.close();
			isr.close();
			// 写入文件
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
			System.out.println("修改引用库成功");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();

		}
	}
	
	//修改导出包名
	public static void changeApkName(String path,String name){
		try {
			// 读取文件
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}

			// 替换签名
			String regex = "<project name=\".*?\"";
			Pattern pattern = Pattern.compile(regex);
			Matcher matcher = pattern.matcher(content);
			if (matcher.find()) {
				content = content.replace(matcher.start(), matcher.end(),
						"<project name=\"" + name + "\"");
			}

			br.close();
			isr.close();
			// 写入文件
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
			System.out.println("修改APK导出名字："+name);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * 执行指令
	 * 
	 * @param cmd
	 */
	public static void runCmd(String cmd,String path) {
		Runtime rt = Runtime.getRuntime();
		BufferedReader br = null;
		InputStreamReader isr = null;
		try {
			
			Process p = null;
			if(path!=null){
				p = rt.exec(cmd,null,new File(path));
			}else
			{
				p = rt.exec(cmd);
			}
			
			//获取控制台输出
			isr = new InputStreamReader(p.getInputStream());
			br = new BufferedReader(isr);
			String msg = null;
			while ((msg = br.readLine()) != null) {
				System.out.println(msg);
			}
			
			//获取错误信息
			if(p.getErrorStream().available() != 0){
				isr = new InputStreamReader(p.getErrorStream());
				br = new BufferedReader(isr);
				msg = null;
				while ((msg = br.readLine()) != null) {
					System.out.println(msg);
				}
			}
			
		} catch (Exception e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		} finally {
			try {
				if (isr != null) {
					isr.close();
				}
				if (br != null) {
					br.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
