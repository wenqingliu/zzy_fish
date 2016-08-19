package com.jt.data;

import org.json.JSONException;
import org.json.JSONObject;

public class ProductInfoItem {
	private String ProductId;
	private String Desc;
	private String ProductName;
	private float money;
	private int gameId;
	private int userID;
	private String domainURL;
	private String Remark;

	public int getGameId() {
		return gameId;
	}
	public void setGameId(int gameId) {
		this.gameId = gameId;
	}
	public int getUserID() {
		return userID;
	}
	public void setUserID(int userID) {
		this.userID = userID;
	}

	public String getProductId() {
		return ProductId;
	}
	public void setProductId(String productId) {
		ProductId = productId;
	}
	public String getDesc() {
		return Desc;
	}
	public void setDesc(String desc) {
		Desc = desc;
	}
	public String getProductName() {
		return ProductName;
	}
	public void setProductName(String productName) {
		ProductName = productName;
	}
	public float getMoney() {
		return money;
	}
	public void setMoney(float money) {
		this.money = money;
	}
	
	public String getDomainURL() {
		return domainURL;
	}
	public void setDomainURL(String domainURL) {
		this.domainURL = domainURL;
	}

	public static ProductInfoItem parseObject(JSONObject josn){
		ProductInfoItem item = new ProductInfoItem();
		try {
			item.setProductName(josn.getString("ProductName"));
			item.setProductId(josn.getString("ProductID"));
			item.setDesc(josn.getString("Description"));
			item.setMoney(Float.valueOf(josn.getString("Price")));
			item.setGameId(Integer.valueOf(josn.getString("gameID")));
			item.setUserID(Integer.valueOf(josn.getString("userID")));
			item.setDomainURL(josn.getString("domainURL"));
			item.setRemark(josn.getString("Remark"));
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return item;
	}
	public String getRemark() {
		return Remark;
	}
	public void setRemark(String remark) {
		Remark = remark;
	}

}
