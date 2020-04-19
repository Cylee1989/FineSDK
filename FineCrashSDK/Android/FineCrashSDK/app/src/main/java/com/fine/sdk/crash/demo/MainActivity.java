package com.fine.sdk.crash.demo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;

import com.fine.sdk.crash.android.FineCrashSDK;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.bt_divide).setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        int num = 0;
                        int result = 1 / num;
                    }
                });

        findViewById(R.id.bt_range).setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        int[] list = {10};
                        list[1] = 1;
                    }
                });

        findViewById(R.id.bt_null).setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        String str = null;
                        System.out.println(str.toString());
                    }
                });

        findViewById(R.id.bt_crash).setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        FineCrashSDK.crash();
                    }
                });
    }

    @Override
    protected void onStart() {
        super.onStart();
        FineCrashSDK.getInstance().onStart();
    }

    @Override
    protected void onStop() {
        super.onStop();
        FineCrashSDK.getInstance().onStop();
    }


}
