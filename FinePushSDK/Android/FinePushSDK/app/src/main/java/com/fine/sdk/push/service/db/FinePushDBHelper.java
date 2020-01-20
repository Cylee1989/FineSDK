package com.fine.sdk.push.service.db;

import java.util.ArrayList;

import com.fine.sdk.push.service.tools.FinePushLog;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class FinePushDBHelper extends SQLiteOpenHelper {

    private static final String DB_NAME = "FinePush.db"; // 数据库名称
    private static final String TABLE_NAME = "FinePushTable"; // 表名称
    private static final int VERSION = 1; // 数据库版本

    private static final String COLUMN_KEY = "PushKey";
    private static final String COLUMN_TIME = "Time";
    private static final String COLUMN_MESSAGE = "Message";
    private static final String COLUMN_REPEAT_INTERVAL = "RepeatInterval";

    private static String LocalPushTable = "CREATE TABLE IF NOT EXISTS " + TABLE_NAME + "(Id INTEGER PRIMARY KEY AUTOINCREMENT, "
            + COLUMN_KEY + "             VARCHAR(64),"
            + COLUMN_TIME + "            BIGINT,"
            + COLUMN_MESSAGE + "         VARCHAR(64),"
            + COLUMN_REPEAT_INTERVAL + " INTEGER"
            + ")";

    public FinePushDBHelper(Context context) {
        super(context, context.getPackageName() + "." + DB_NAME, null, VERSION);
        getWriteDB().execSQL(LocalPushTable);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(LocalPushTable);
        FinePushLog.d("FinePushDBHelper Create Database:" + DB_NAME + "|" + VERSION);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
    }

    private SQLiteDatabase getWriteDB() {
        return this.getWritableDatabase();
    }

    private SQLiteDatabase getReadDB() {
        return this.getReadableDatabase();
    }

    public synchronized void insertData(FinePushLocalData data) {
        FinePushLocalData temp = queryDataByKey(data.getKey());
        if (temp != null) {
            updateData(data);
            return;
        }

        ContentValues values = new ContentValues();
        values.put(COLUMN_KEY, data.getKey());
        values.put(COLUMN_TIME, data.getTime());
        values.put(COLUMN_MESSAGE, data.getMessage());
        values.put(COLUMN_REPEAT_INTERVAL, data.getRepeatInterval());
        getWriteDB().insert(TABLE_NAME, null, values);
    }

    public synchronized void deleteData(String key) {
        FinePushLocalData temp = queryDataByKey(key);
        if (temp == null) {
            return;
        }

        String whereClause = COLUMN_KEY + "=?";
        String[] whereArgs = {String.valueOf(key)};
        getWriteDB().delete(TABLE_NAME, whereClause, whereArgs);
    }

    public synchronized void updateData(FinePushLocalData data) {
        String whereClause = COLUMN_KEY + "=?";
        String[] whereArgs = {String.valueOf(data.getKey())};
        ContentValues values = new ContentValues();
        values.put(COLUMN_KEY, data.getKey());
        values.put(COLUMN_TIME, data.getTime());
        values.put(COLUMN_MESSAGE, data.getMessage());
        values.put(COLUMN_REPEAT_INTERVAL, data.getRepeatInterval());
        getWriteDB().update(TABLE_NAME, values, whereClause, whereArgs);
    }

    public ArrayList<FinePushLocalData> queryAllData() {
        ArrayList<FinePushLocalData> list = new ArrayList<FinePushLocalData>();
        Cursor cursor = getReadDB().query(TABLE_NAME, null, null, null, null, null, null);
        // 判断游标是否为空
        if (cursor != null && cursor.moveToFirst()) {
            try {
                do {
                    FinePushLocalData data = new FinePushLocalData();
                    data.setKey(cursor.getString(1));
                    data.setTime(cursor.getLong(2));
                    data.setMessage(cursor.getString(3));
                    data.setRepeatInterval(cursor.getInt(4));
                    list.add(data);
                } while (cursor.moveToNext());
            } finally {
                cursor.close();
            }
        }
        return list;
    }

    private FinePushLocalData queryDataByKey(String key) {
        FinePushLocalData data = null;
        Cursor cursor = getReadDB().query(TABLE_NAME, null, COLUMN_KEY + "=\"" + key + "\"", null, null, null, null);
        try {
            if (cursor != null && cursor.moveToFirst()) {
                data = new FinePushLocalData();
                data.setKey(cursor.getString(1));
                data.setTime(cursor.getLong(2));
                data.setMessage(cursor.getString(3));
                data.setRepeatInterval(cursor.getInt(4));
            }
        } finally {
            cursor.close();
        }
        return data;
    }
}
