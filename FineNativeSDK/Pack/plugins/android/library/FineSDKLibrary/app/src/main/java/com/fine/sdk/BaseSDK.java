package com.fine.sdk;

import com.fine.ndk.NDKHelper;
import com.fine.sdk.activity.FineLogoActivity;
import com.fine.sdk.constant.FineSDKCode;
import com.fine.sdk.tools.FineLog;
import com.fine.sdk.tools.FineTools;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.KeyEvent;

import java.util.Map;

public class BaseSDK implements InterfaceActivity, InterfaceFunc {

    static {
        System.loadLibrary("FineSDK");
    }

    private static String TAG = "BaseSDK";
    protected Activity gameActivity;

    @Override
    public void onCreate(Activity activity) {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onCreate");
        this.gameActivity = activity;
        NDKHelper.init(this, activity);
    }

    @Override
    public void onStart() {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onStart");
    }

    @Override
    public void onRestart() {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onRestart");
    }

    @Override
    public void onStop() {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onStop");
    }

    @Override
    public void onPause() {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onPause");
    }

    @Override
    public void onResume() {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onResume");
    }

    @Override
    public void onLowMemory() {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onLowMemory");
    }

    @Override
    public void onDestroy() {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onDestroy");
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void onNewIntent(Intent intent) {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onNewIntent");
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onActivityResult");
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onConfigurationChanged");
    }

    @Override
    public void onSaveInstanceState(Bundle outState) {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onSaveInstanceState");
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onRequestPermissionsResult");
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        // TODO Auto-generated method stub
        FineLog.d("BaseSDK", "onWindowFocusChanged");
    }

    public void receiveFromNative(String str) {
        FineLog.d(TAG, "receiveFromNative:" + str);
    }

    public void sendToNative(Map<String, Object> map) {
        String action = (String) map.get(FineSDKCode.Key_Action);
        if (action == FineSDKCode.Action_Init) {
            String code = (String) map.get(FineSDKCode.Key_ErrCode);
            if (code == FineSDKCode.ErrCode_Success) {
                boolean isExistLogo = FineTools.isFileExistInAssets(gameActivity, "FineSDK", "logo");
                if (isExistLogo) {
                    Intent intent = new Intent(gameActivity, FineLogoActivity.class);
                    intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                    gameActivity.startActivity(intent);
                }
            }
        }

        NDKHelper.sendToNative(map);
    }

    @Override
    public void initSDK(String str) {

    }

    @Override
    public void login(String str) {

    }

    @Override
    public void pay(String str) {

    }

    @Override
    public void logout(String str) {

    }

    @Override
    public void exit(String str) {
        new AlertDialog.Builder(gameActivity).setTitle("提示").setMessage("是否退出游戏?")
                .setPositiveButton("是", new DialogInterface.OnClickListener() {

                    public void onClick(DialogInterface dialog, int which) {
                        gameActivity.finish();
                        System.exit(0);
                    }
                }).setNegativeButton("否", null).show();
    }

    @Override
    public void enterUserCenter(String str) {

    }

    @Override
    public void showToolBar(String str) {

    }

    @Override
    public void hideToolBar(String str) {

    }
}
