package com.fine.sdk.dispatcher;

import java.util.HashMap;
import java.util.Map;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.widget.Toast;

import com.fine.sdk.BaseSDK;
import com.fine.sdk.constant.FineSDKCode;

public class FineDispatcherTest extends BaseSDK {

    @Override
    public void initSDK(String str) {
        Map<String, Object> map = new HashMap<String, Object>();
        map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Init);
        map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Success);
        map.put(FineSDKCode.Key_ErrMsg, "初始化成功");
        sendToNative(map);
        Toast.makeText(gameActivity, "初始化成功", Toast.LENGTH_SHORT).show();
    }

    @Override
    public void login(String str) {
        FineUI.loginUI(gameActivity, new FineUI.LoginCallBack() {
            @Override
            public void loginSuccess(int type, String param) {
                Map<String, Object> map = new HashMap<String, Object>();
                map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Login);
                map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Success);
                map.put(FineSDKCode.Key_ErrMsg, "登录成功");
                map.put("Token", param);
                sendToNative(map);
                Toast.makeText(gameActivity, "登录成功", Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    public void pay(String str) {
        FineUI.payUI(gameActivity, new FineUI.PayCallBack() {

            @Override
            public void paySuccess(int type, String param) {
                Map<String, Object> map = new HashMap<String, Object>();
                map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Pay);
                map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Success);
                map.put(FineSDKCode.Key_ErrMsg, "充值成功");
                map.put("Money", "10.00");
                sendToNative(map);
                Toast.makeText(gameActivity, "充值成功", Toast.LENGTH_SHORT).show();
            }

            @Override
            public void payFailed(int type, String param) {
                Map<String, Object> map = new HashMap<String, Object>();
                map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Pay);
                map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Failed);
                map.put(FineSDKCode.Key_ErrMsg, "充值失败");
                map.put("Money", "10.00");
                sendToNative(map);
                Toast.makeText(gameActivity, "充值失败", Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    public void logout(String str) {
        Map<String, Object> map = new HashMap<String, Object>();
        map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Logout);
        map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Success);
        map.put(FineSDKCode.Key_ErrMsg, "注销成功");
        sendToNative(map);
        Toast.makeText(gameActivity, "注销成功", Toast.LENGTH_SHORT).show();
    }

    @Override
    public void exit(String str) {
        new AlertDialog.Builder(gameActivity).setTitle("Tip").setMessage("Do you want exit?")
                .setPositiveButton("Yes", new DialogInterface.OnClickListener() {

                    public void onClick(DialogInterface dialog, int which) {
                        gameActivity.finish();
                        System.exit(0);
                    }
                }).setNegativeButton("No", null).show();
    }

    @Override
    public void enterUserCenter(String str) {
        Toast.makeText(gameActivity, "打开用户中心", Toast.LENGTH_SHORT).show();
    }

    @Override
    public void showToolBar(String str) {
        Toast.makeText(gameActivity, "显示悬浮窗", Toast.LENGTH_SHORT).show();
    }

    @Override
    public void hideToolBar(String str) {
        Toast.makeText(gameActivity, "隐藏悬浮窗", Toast.LENGTH_SHORT).show();
    }
}