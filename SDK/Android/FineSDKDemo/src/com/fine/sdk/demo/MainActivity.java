package com.fine.sdk.demo;

import java.util.HashMap;
import java.util.Map;

import org.json.JSONException;
import org.json.JSONObject;

import com.fine.sdk.demo.java.R;
import com.fine.ndk.NDKHelper;
import com.fine.sdk.FineSDK;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {

	private FineSDK fine = new FineSDK();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		fine.onCreate(this);
		initView();
	}

	private void initView() {
		Button button_init = (Button) findViewById(R.id.button_init);
		button_init.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View arg0) {
				Map<String, Object> map = new HashMap<String, Object>();
				map.put("appKey", "123");
				map.put("appSecret", "456");
				callNativeFunction("initSDK", map);
			}
		});

		Button button_login = (Button) findViewById(R.id.button_login);
		button_login.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View arg0) {
				callNativeFunction("login", null);
			}
		});

		Button button_pay = (Button) findViewById(R.id.button_pay);
		button_pay.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View arg0) {
				Map<String, Object> map = new HashMap<String, Object>();
				map.put("money", "1");
				callNativeFunction("pay", map);
			}
		});

		Button button_logout = (Button) findViewById(R.id.button_logout);
		button_logout.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View arg0) {
				callNativeFunction("logout", null);
			}
		});

		Button button_exit = (Button) findViewById(R.id.button_exit);
		button_exit.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View arg0) {
				callNativeFunction("exit", null);
			}
		});
	}

	private void callNativeFunction(String funcName, Map<String, Object> map) {
		JSONObject json = new JSONObject();
		try {
			if (map != null && map.size() > 0) {
				for (Map.Entry<String, Object> entry : map.entrySet()) {
					json.put(entry.getKey(), entry.getValue());
				}
			}
		} catch (JSONException e) {
			e.printStackTrace();
		}
		NDKHelper.sendToNative(funcName, json.toString());
	}

}
