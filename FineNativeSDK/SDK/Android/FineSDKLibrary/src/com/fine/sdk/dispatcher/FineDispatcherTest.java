package com.fine.sdk.dispatcher;

import java.util.HashMap;
import java.util.Map;
import org.json.JSONException;
import org.json.JSONObject;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.widget.Toast;
import com.fine.ndk.NDKHelper;
import com.fine.sdk.BaseSDK;

public class FineDispatcherTest extends BaseSDK {

	public void initSDK(String str) {
		Toast.makeText(gameActivity, "初始化", Toast.LENGTH_SHORT).show();
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("ActionType", "1");
		map.put("ErrorCode", "1");
		map.put("ErrorMessage", "初始化成功");
		sendToNative(map);
	}

	public void login(String str) {
		Toast.makeText(gameActivity, "登录", Toast.LENGTH_SHORT).show();
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("ActionType", "2");
		map.put("ErrorCode", "1");
		map.put("ErrorMessage", "登录成功");
		map.put("Token", "I am token");
		sendToNative(map);
	}

	public void pay(String str) {
		Toast.makeText(gameActivity, "充值", Toast.LENGTH_SHORT).show();
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("ActionType", "3");
		map.put("ErrorCode", "1");
		map.put("ErrorMessage", "充值成功");
		map.put("Money", "10.00");
		sendToNative(map);
	}

	public void logout(String str) {
		Toast.makeText(gameActivity, "注销", Toast.LENGTH_SHORT).show();
		Map<String, Object> map = new HashMap<String, Object>();
		map.put("ActionType", "4");
		map.put("ErrorCode", "1");
		map.put("ErrorMessage", "注销成功");
		sendToNative(map);
	}

	public void exit(String str) {
		new AlertDialog.Builder(gameActivity).setTitle("Tip").setMessage("Do you want exit?")
				.setPositiveButton("Yes", new DialogInterface.OnClickListener() {

					public void onClick(DialogInterface dialog, int which) {
						gameActivity.finish();
						System.exit(0);
					}
				}).setNegativeButton("No", null).show();
	}

	private void sendToNative(Map<String, Object> map) {
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
		NDKHelper.sendToNative("receiveCallBack", json.toString());
	}

}
