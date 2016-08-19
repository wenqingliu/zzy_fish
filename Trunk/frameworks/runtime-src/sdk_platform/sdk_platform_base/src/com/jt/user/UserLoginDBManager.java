package com.jt.user;

import java.util.ArrayList;
import java.util.List;

import com.jt.user.UserLoginInfo;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class UserLoginDBManager {
	private UserLoginDBControl helper;
	private SQLiteDatabase db;
	private static UserLoginDBManager instance;

	public static UserLoginDBManager getInstance(Context context) {
		if (instance == null) {
			instance = new UserLoginDBManager(context);
		}
		return instance;
	}

	private UserLoginDBManager(Context context) {
		helper = new UserLoginDBControl(context);

		db = helper.getWritableDatabase();
	}

	public long updateAllNoAutoLogin() {
		ContentValues cv = new ContentValues();
		cv.put("isAutoLogin", 0);
		return db.update(UserLoginDBControl.TBL_NAME, cv, "isAutoLogin = ?",
				new String[] { "1" });
	}

	public long insertAutoLogin(String acccount, String password,
			String FaceID,int AccountType,String bigFace,int gender) {
		updateAllNoAutoLogin();
		return insert(acccount, password, FaceID,true, AccountType,bigFace,gender);
	}

	public long insert(String acccount, String password,String FaceID,String bigFace,
			int AccountType,int gender) {
		return insert(acccount, password, FaceID,false, AccountType,bigFace,gender);
	}

	public long insert(String acccount, String password, String FaceID,
			boolean isAutoLogin, int AccountType,String bigFace,int gender) {
		ContentValues values = new ContentValues();
		values.put("_acccount", acccount);
		values.put("password", password);
		values.put("faceID", FaceID);
		values.put("isAutoLogin", isAutoLogin ? 1 : 0);
		values.put("AccountType", AccountType);
		values.put("bigFace", bigFace);
		values.put("gender",gender);
		return insert(values);
	}

	public long insert(ContentValues values) {
		del(values.getAsString("_acccount"));
		long res = db.insert(UserLoginDBControl.TBL_NAME, null, values);
		return res;
	}

	public long updatePassword(String acccount, String password) {
		ContentValues cv = new ContentValues();
		cv.put("password", password);
		long res = db.update(UserLoginDBControl.TBL_NAME, cv, "_acccount = ?",
				new String[] { acccount });
		return res;
	}

	public UserLoginInfo queryFinallyLogin() {
		UserLoginInfo info = null;
		Cursor c = db.query(UserLoginDBControl.TBL_NAME, null, null, null,
				null, null, null);
		while (c.moveToNext()) {
			info = new UserLoginInfo();
			info.acccount = c.getString(c.getColumnIndex("_acccount"));
			info.password = c.getString(c.getColumnIndex("password"));
			info.faceID = c.getString(c.getColumnIndex("faceID"));
			info.isAutoLogin = c.getInt(c.getColumnIndex("isAutoLogin")) == 1;
			info.AccountType = c.getInt(c.getColumnIndex("AccountType"));
			info.bigFace = c.getString(c.getColumnIndex("bigFace"));
			info.gender = c.getInt(c.getColumnIndex("gender"));
		}
		c.close();
		return info;
	}

	public UserLoginInfo queryFinallyLogin(int AccountType) {
		UserLoginInfo info = null;
		// Cursor c =
		// db.rawQuery("SELECT  *FROM "+UserLoginDBControl.TBL_NAME+" where AccountType=?   limit 0,1 ",
		// new String[]{String.valueOf(AccountType)});

		Cursor c = db.rawQuery("SELECT  *FROM " + UserLoginDBControl.TBL_NAME
				+ " where AccountType=?   ",
				new String[] { String.valueOf(AccountType) });
		while (c.moveToNext()) {
			info = new UserLoginInfo();
			info.acccount = c.getString(c.getColumnIndex("_acccount"));
			info.password = c.getString(c.getColumnIndex("password"));
			info.faceID = c.getString(c.getColumnIndex("faceID"));
			info.isAutoLogin = c.getInt(c.getColumnIndex("isAutoLogin")) == 1;
			info.AccountType = c.getInt(c.getColumnIndex("AccountType"));
			info.bigFace = c.getString(c.getColumnIndex("bigFace"));
			info.gender = c.getInt(c.getColumnIndex("gender"));
		}
		c.close();
		return info;
	}

	public UserLoginInfo queryisAccount(String _acccount, int AccountType) {
		UserLoginInfo info = null;
		Cursor c = db.rawQuery("SELECT  *FROM " + UserLoginDBControl.TBL_NAME
				+ " where _acccount=? and AccountType=? limit 0,1",
				new String[] { _acccount, String.valueOf(AccountType) });
		while (c.moveToNext()) {
			info = new UserLoginInfo();
			info.acccount = c.getString(c.getColumnIndex("_acccount"));
			info.password = c.getString(c.getColumnIndex("password"));
			info.faceID = c.getString(c.getColumnIndex("faceID"));
			info.isAutoLogin = c.getInt(c.getColumnIndex("isAutoLogin")) == 1;
			info.AccountType = c.getInt(c.getColumnIndex("AccountType"));
			info.bigFace = c.getString(c.getColumnIndex("bigFace"));
			info.gender = c.getInt(c.getColumnIndex("gender"));
		}
		c.close();
		return info;
	}

	public UserLoginInfo queryisAccount(String _acccount) {
		UserLoginInfo info = null;
		Cursor c = db.rawQuery("SELECT  *FROM " + UserLoginDBControl.TBL_NAME
				+ " where _acccount=?  limit 0,1", new String[] { _acccount });
		while (c.moveToNext()) {
			info = new UserLoginInfo();
			info.acccount = c.getString(c.getColumnIndex("_acccount"));
			info.password = c.getString(c.getColumnIndex("password"));
			info.faceID = c.getString(c.getColumnIndex("faceID"));
			info.isAutoLogin = c.getInt(c.getColumnIndex("isAutoLogin")) == 1;
			info.AccountType = c.getInt(c.getColumnIndex("AccountType"));
			info.bigFace = c.getString(c.getColumnIndex("bigFace"));
			info.gender = c.getInt(c.getColumnIndex("gender"));
		}
		c.close();
		return info;
	}

	public UserLoginInfo queryisAutoLogin(int AccountType) {
		UserLoginInfo info = null;
		Cursor c = db.rawQuery("SELECT  *FROM " + UserLoginDBControl.TBL_NAME
				+ " where isAutoLogin=?  and AccountType=? limit 0,1",
				new String[] { "1", String.valueOf(AccountType) });
		while (c.moveToNext()) {
			info = new UserLoginInfo();
			info.acccount = c.getString(c.getColumnIndex("_acccount"));
			info.password = c.getString(c.getColumnIndex("password"));
			info.faceID = c.getString(c.getColumnIndex("faceID"));
			info.isAutoLogin = c.getInt(c.getColumnIndex("isAutoLogin")) == 1;
			info.AccountType = c.getInt(c.getColumnIndex("AccountType"));
			info.bigFace = c.getString(c.getColumnIndex("bigFace"));
			info.gender = c.getInt(c.getColumnIndex("gender"));
		}
		c.close();
		return info;
	}

	public UserLoginInfo queryisAutoLogin() {
		UserLoginInfo info = null;
		Cursor c = db.rawQuery("SELECT  *FROM " + UserLoginDBControl.TBL_NAME
				+ " where isAutoLogin=?  limit 0,1", new String[] { "1" });
		while (c.moveToNext()) {
			info = new UserLoginInfo();
			info.acccount = c.getString(c.getColumnIndex("_acccount"));
			info.password = c.getString(c.getColumnIndex("password"));
			info.faceID = c.getString(c.getColumnIndex("faceID"));
			info.isAutoLogin = c.getInt(c.getColumnIndex("isAutoLogin")) == 1;
			info.AccountType = c.getInt(c.getColumnIndex("AccountType"));
			info.bigFace = c.getString(c.getColumnIndex("bigFace"));
			info.gender = c.getInt(c.getColumnIndex("gender"));
		}
		c.close();
		return info;
	}

	public List<UserLoginInfo> queryIsType(int AccountType) {
		ArrayList<UserLoginInfo> persons = new ArrayList<UserLoginInfo>();
		Cursor c = null;
		try {
			c = db.rawQuery(
					"SELECT  *FROM " + UserLoginDBControl.TBL_NAME + "", null);
		} catch (Exception e) {

		}
		while (c.moveToNext()) {
			UserLoginInfo person = new UserLoginInfo();
			person.acccount = c.getString(c.getColumnIndex("_acccount"));
			person.password = c.getString(c.getColumnIndex("password"));
			person.faceID = c.getString(c.getColumnIndex("faceID"));
			person.isAutoLogin = c.getInt(c.getColumnIndex("isAutoLogin")) == 1;
			person.AccountType = c.getInt(c.getColumnIndex("AccountType"));
			person.bigFace = c.getString(c.getColumnIndex("bigFace"));
			person.gender = c.getInt(c.getColumnIndex("gender"));
			persons.add(person);
		}
		c.close();
		return persons;
	}

	public List<UserLoginInfo> query() {
		ArrayList<UserLoginInfo> persons = new ArrayList<UserLoginInfo>();
		Cursor c = queryTheCursor();
		while (c.moveToNext()) {
			UserLoginInfo person = new UserLoginInfo();
			person.acccount = c.getString(c.getColumnIndex("_acccount"));
			person.password = c.getString(c.getColumnIndex("password"));
			person.faceID = c.getString(c.getColumnIndex("faceID"));
			person.isAutoLogin = c.getInt(c.getColumnIndex("isAutoLogin")) == 1;
			person.AccountType = c.getInt(c.getColumnIndex("AccountType"));
			person.bigFace = c.getString(c.getColumnIndex("bigFace"));
			person.gender = c.getInt(c.getColumnIndex("gender"));
			persons.add(person);
		}
		c.close();
		return persons;
	}

	public Cursor queryTheCursor() {
		Cursor c = db.query(UserLoginDBControl.TBL_NAME, null, null, null,
				null, null, null);

		return c;
	}

	public void del(String acccount) {
		db.delete(UserLoginDBControl.TBL_NAME, "_acccount=?",
				new String[] { (acccount) });

	}

	public void close() {
		if (db != null)
			db.close();
	}
}
