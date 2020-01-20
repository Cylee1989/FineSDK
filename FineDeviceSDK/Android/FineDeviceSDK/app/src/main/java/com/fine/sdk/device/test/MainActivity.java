package com.fine.sdk.device.test;


import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.fine.sdk.device.R;
import com.fine.sdk.device.info.FineDeviceInfo;
import com.fine.sdk.device.notch.FineDeviceNotch;

public class MainActivity extends Activity {

    private TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        FineDeviceNotch.getInstance().init(this);

        textView = findViewById(R.id.textview_show);
        findViewById(R.id.button_device_info).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String info = "";
                info += "应用包名: " + FineDeviceInfo.getPackageName(MainActivity.this) + "\n";
                info += "版本名称: " + FineDeviceInfo.getVersionName(MainActivity.this) + "\n";
                info += "版本号: " + FineDeviceInfo.getVersionCode(MainActivity.this) + "\n";
                info += "OpenGL版本: " + FineDeviceInfo.getGLVersion(MainActivity.this) + "\n";
                info += "是否模拟器: " + FineDeviceInfo.isEmulator() + "\n";
                info += "总计内存: " + FineDeviceInfo.getTotalMemory() + "KB\n";
                info += "可用内存: " + FineDeviceInfo.getAvailableMemory(MainActivity.this) + "KB\n";
                info += "应用内存: " + FineDeviceInfo.getAppMemory(MainActivity.this) + "KB\n";
                info += "国家名称: " + FineDeviceInfo.getDisplayCountry() + "\n";
                info += "国家码: " + FineDeviceInfo.getCountryCode() + "\n";
                info += "货币码: " + FineDeviceInfo.getCurrencyCode() + "\n";
                info += "货币符号: " + FineDeviceInfo.getCurrencySymbol() + "\n";
                info += "地区时区: " + FineDeviceInfo.getTimeZoneID() + "\n";
                info += "语言: " + FineDeviceInfo.getLanguage();
                textView.setText(info);
            }
        });

        findViewById(R.id.button_device_screen).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String info = "";
                info += "屏幕分辨率: " + FineDeviceNotch.getInstance().getPhysicalResolution() + "\n";
                info += "菜单栏高度: " + FineDeviceInfo.getStatusBarHeight(MainActivity.this) + "\n";
                info += "导航条高度: " + FineDeviceInfo.getNavigationBarHeight(MainActivity.this) + "\n";
                info += "支持刘海屏: " + FineDeviceNotch.getInstance().isSupportNotch() + "\n";
                info += "隐藏刘海屏: " + FineDeviceNotch.getInstance().isHideNotch() + "\n";
                info += "刘海宽度: " + FineDeviceNotch.getInstance().getNotchWidth() + "\n";
                info += "刘海高度: " + FineDeviceNotch.getInstance().getNotchHeigth();
                textView.setText(info);
            }
        });

    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        FineDeviceNotch.getInstance().onWindowFocusChanged(hasFocus);
    }

}
