package com.fine.sdk;

import com.fine.sdk.tools.FineLog;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.KeyEvent;

public class FineSDK implements InterfaceActivity {

	private static FineSDK instance = new FineSDK();

	public static FineSDK getInstance() {
		return instance;
	}

	private final String TAG = "FineSDK";
	private InterfaceActivity mInterfaceActivity = null;
	private final static String dispatcher_ClassName = "com.fine.sdk.dispatcher.FineDispatcher";
	private final static String dispatcher_ClassName_Test = "com.fine.sdk.dispatcher.FineDispatcherTest";

	public InterfaceActivity getInterfaceActivity() {
		if (mInterfaceActivity == null) {
			Class<?> c = null;
			try {
				c = Class.forName(dispatcher_ClassName);
				mInterfaceActivity = (InterfaceActivity) c.newInstance();
			} catch (Exception e) {
				FineLog.e(TAG, "InterfaceActivity " + dispatcher_ClassName + " is null");
			} finally {
				if (mInterfaceActivity == null) {
					try {
						c = Class.forName(dispatcher_ClassName_Test);
						mInterfaceActivity = (InterfaceActivity) c.newInstance();
					} catch (Exception e) {
						FineLog.e(TAG, "InterfaceActivity " + dispatcher_ClassName_Test + " is null");
					}
				}
			}
		}
		return mInterfaceActivity;
	}

	@Override
	public void onCreate(Activity activity) {
		// TODO Auto-generated method stub
		mInterfaceActivity = getInterfaceActivity();
		mInterfaceActivity.onCreate(activity);
	}

	@Override
	public void onStart() {
		// TODO Auto-generated method stub
		mInterfaceActivity.onStart();
	}

	@Override
	public void onRestart() {
		// TODO Auto-generated method stub
		mInterfaceActivity.onRestart();
	}

	@Override
	public void onStop() {
		// TODO Auto-generated method stub
		mInterfaceActivity.onStop();
	}

	@Override
	public void onPause() {
		// TODO Auto-generated method stub
		mInterfaceActivity.onPause();
	}

	@Override
	public void onResume() {
		// TODO Auto-generated method stub
		mInterfaceActivity.onResume();
	}

	@Override
	public void onLowMemory() {
		// TODO Auto-generated method stub
		mInterfaceActivity.onLowMemory();
	}

	@Override
	public void onDestroy() {
		// TODO Auto-generated method stub
		mInterfaceActivity.onDestroy();
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		// TODO Auto-generated method stub
		return mInterfaceActivity.onKeyDown(keyCode, event);
	}

	@Override
	public void onNewIntent(Intent intent) {
		// TODO Auto-generated method stub
		mInterfaceActivity.onNewIntent(intent);
	}

	@Override
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		// TODO Auto-generated method stub
		mInterfaceActivity.onActivityResult(requestCode, resultCode, data);
	}

	@Override
	public void onConfigurationChanged(Configuration newConfig) {
		// TODO Auto-generated method stub
		mInterfaceActivity.onConfigurationChanged(newConfig);
	}

	@Override
	public void onSaveInstanceState(Bundle outState) {
		// TODO Auto-generated method stub
		mInterfaceActivity.onSaveInstanceState(outState);
	}

	@Override
	public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
		// TODO Auto-generated method stub
		mInterfaceActivity.onRequestPermissionsResult(requestCode, permissions, grantResults);
	}

}
