package com.example.module;

import java.util.ArrayList;

public class MsdkApi {
	 public String apiName; // 通常直接用Api接口名字
	 public String rawApiName = ""; // 调用的SDK的原始Api接口名字
     public String displayName = ""; // 用于显示的名字
     public String desc = ""; // 描述一下接口的用途
     public String resultDesc = ""; // 存储结果
     public String inputName = ""; // 需要输入的项的名称
     
     public ArrayList<MsdkApi> apiSet = null;

     public MsdkApi(String apiName,String displayName) {
         this.apiName = apiName;
         this.displayName = displayName;
     }
     
     public MsdkApi(String apiName,String rawApiName, String displayName, String desc) {
         this.apiName = apiName;
         this.rawApiName = rawApiName;
         this.displayName = displayName;
         this.desc = desc;
     }
     
     public MsdkApi(String apiName,String rawApiName, String displayName, String desc, String inputName) {
         this.apiName = apiName;
         this.rawApiName = rawApiName;
         this.displayName = displayName;
         this.desc = desc;
         this.inputName = inputName;
     }
     
     public MsdkApi(String displayName, ArrayList<MsdkApi> apiSet) {
    	 this.displayName = displayName;
    	 this.apiSet = apiSet;
     }
}
