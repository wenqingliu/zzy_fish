package com.jt.user;

public class UserLoginInfo {
	public String acccount;
	public String password;
	public String faceID;
	public boolean isAutoLogin;
	public int AccountType;
	public String bigFace;
	public int gender;
	
	public UserLoginInfo()
	{
		reset();
	}
	
	public void reset()
	{
		acccount = password = faceID = bigFace = "";
		isAutoLogin = false;
		AccountType = 0;
		gender = 0;
	}
	
	public String getAcccount() {
		return acccount;
	}
	public void setAcccount(String acccount) {
		this.acccount = acccount;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public boolean isAutoLogin() {
		return isAutoLogin;
	}
	public void setAutoLogin(boolean isAutoLogin) {
		this.isAutoLogin = isAutoLogin;
	}
	
	public String getFaceID() {
		return faceID;
	}

	public void setFaceID(String faceID) {
		this.faceID = faceID;
	}

	public int getAccountType() {
		return AccountType;
	}
	public void setAccountType(int accountType) {
		AccountType = accountType;
	}
	
	public String getBigFace()
	{
		return this.bigFace;
	}
	
	public void setBigFace(String bigFace) {
		this.bigFace = bigFace;
	}
	
	public int getGender() {
		return gender;
	}

	public void setGender(int gender) {
		this.gender = gender;
	}

	@Override
	public String toString() {
		return "UserLoginInfo [acccount=" + acccount + ", password=" + password
				+ ", faceID=" + faceID + ", isAutoLogin=" + isAutoLogin
				+ ", AccountType=" + AccountType + ", bigFace=" + bigFace
				+ ", gender=" + gender + "]";
	}
	
}
