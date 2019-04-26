package com.fine.ndk;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Map;

import org.json.JSONException;
import org.json.JSONObject;

import com.fine.sdk.tools.FineLog;

import android.app.Activity;
import android.os.Handler;
import android.os.Message;

public class NDKHelper {

	private static String TAG = "NDKHelper";
	private static Object callHandler = null;
	private static Handler NDKHelperHandler = null;
	private static Activity uiActivity;

	private static native void NativeCallHandler(String json);

	private static void _NativeCallHandler(final String json) {
		if (uiActivity != null) {
			uiActivity.runOnUiThread(new Runnable() {
				public void run() {
					NativeCallHandler(json);
				}
			});
		}
	}

	private final static int __MSG_FROM_CPP__ = 5;
	private static String __CALLED_METHOD__ = "calling_method_name";
	private static String __CALLED_METHOD_PARAMS__ = "calling_method_params";

	public static void init(Object callReciever, Activity act) {
		callHandler = callReciever;
		uiActivity = act;
		NDKHelperHandler = new Handler(uiActivity.getMainLooper()) {
			public void handleMessage(Message msg) {
				switch (msg.what) {
				case __MSG_FROM_CPP__:
					try {
						NDKMessage message = (NDKMessage) msg.obj;
						message.methodToCall.invoke(NDKHelper.callHandler, message.methodParams);
					} catch (IllegalArgumentException e) {
						e.printStackTrace();
					} catch (IllegalAccessException e) {
						e.printStackTrace();
					} catch (InvocationTargetException e) {
						e.printStackTrace();
					}
					break;
				}
			}
		};
	}

	public static void sendToNative(String methodToCall, String paramList) {
		JSONObject obj = new JSONObject();
		try {
			obj.put(__CALLED_METHOD__, methodToCall);
			obj.put(__CALLED_METHOD_PARAMS__, paramList);
			FineLog.d(TAG, "sendToNative:" + obj.toString());
			_NativeCallHandler(obj.toString());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static void sendToNative(Map<String, Object> map) {
		JSONObject json = new JSONObject();
		try {
			if (map != null && map.size() > 0) {
				for (Map.Entry<String, Object> entry : map.entrySet()) {
					json.put(entry.getKey(), entry.getValue());
				}
			}
			sendToNative("receiveCallBack", json.toString());
		} catch (JSONException e) {
			e.printStackTrace();
		}
	}

	public static void receiveFromNative(String info) {
		FineLog.d(TAG, "receiveFromNative:" + info);
		try {
			JSONObject obj = new JSONObject(info);
			if (obj.has(__CALLED_METHOD__)) {
				String methodName = obj.getString(__CALLED_METHOD__);
				String methodParams = obj.getString(__CALLED_METHOD_PARAMS__);

				Method m = NDKHelper.callHandler.getClass().getMethod(methodName, new Class[] { String.class });
				NDKMessage message = new NDKMessage();
				message.methodToCall = m;
				message.methodParams = methodParams;

				Message msg = new Message();
				msg.what = __MSG_FROM_CPP__;
				msg.obj = message;
				NDKHelper.NDKHelperHandler.sendMessage(msg);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
