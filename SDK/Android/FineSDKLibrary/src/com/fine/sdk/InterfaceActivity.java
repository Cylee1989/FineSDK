package com.fine.sdk;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.KeyEvent;

public interface InterfaceActivity {

	public abstract void onCreate(Activity activity);

	public abstract void onStart();

	public abstract void onRestart();

	public abstract void onStop();

	public abstract void onPause();

	public abstract void onResume();

	public abstract void onLowMemory();

	public abstract void onDestroy();

	public abstract boolean onKeyDown(int keyCode, KeyEvent event);

	public abstract void onNewIntent(Intent intent);

	public abstract void onActivityResult(int requestCode, int resultCode, Intent data);

	public abstract void onConfigurationChanged(Configuration newConfig);

	public abstract void onSaveInstanceState(Bundle outState);

	public abstract void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults);

}
