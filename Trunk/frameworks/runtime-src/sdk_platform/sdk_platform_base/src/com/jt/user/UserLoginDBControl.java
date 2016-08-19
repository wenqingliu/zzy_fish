package com.jt.user;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class UserLoginDBControl extends SQLiteOpenHelper  {
	public static final String DB_NAME = "userInfo.db";  
	public static final String TBL_NAME = "UserInfo";  
	public static final int DATABASE_VERSION = 8;  
    private static final String CREATE_TBL = " create table "  
            + " UserInfo(_acccount text primary key ,password text,faceID text,isAutoLogin INTEGER,AccountType INTEGER,bigFace text,gender INTEGER) ";  

    public  UserLoginDBControl(Context c) {  
        super(c, DB_NAME, null, DATABASE_VERSION);	  
    }  
    @Override  
    public void onCreate(SQLiteDatabase db) {  

        db.execSQL(CREATE_TBL);  
    }  
    @Override  
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {  
    	db.execSQL("DROP TABLE IF EXISTS "+TBL_NAME);
        onCreate(db);
    }
}
