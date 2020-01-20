package com.fine.sdk.dispatcher;

import java.util.UUID;
import java.util.regex.Pattern;

import org.json.JSONException;
import org.json.JSONObject;

import android.app.Activity;
import android.app.Dialog;
import android.content.Context;
import android.graphics.Color;
import android.graphics.PixelFormat;
import android.text.TextUtils;
import android.view.Gravity;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.Toast;
import android.widget.LinearLayout.LayoutParams;
import android.widget.TextView;

import com.fine.sdk.tools.FineTools;

/**
 * Created by Cylee on 2019/4/24.
 */

public class FineUI {

    public static abstract class LoginCallBack{
        public abstract void loginSuccess(int type, String param);
    }

    public static abstract class PayCallBack{
        public abstract void paySuccess(int type, String param);
        public abstract void payFailed(int type, String param);
    }

    public static void loginUI(final Activity activity, final LoginCallBack loginCallBack){
        final Dialog dialog = new Dialog(activity);
        dialog.setCancelable(false);

        //上边距（dp值）
        int topMargin = FineTools.dip2px(activity, 20);
        int width = FineTools.dip2px(activity, 300);

        LinearLayout layoutRoot = new LinearLayout(activity);
        LayoutParams layoutRootRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT);
        layoutRootRarams.gravity = Gravity.CENTER;
        layoutRoot.setLayoutParams(layoutRootRarams);
        layoutRoot.setBackgroundColor(Color.GRAY);
        layoutRoot.setOrientation(LinearLayout.VERTICAL);

        /**-----------title start------------**/
        TextView titleTV = new TextView(activity);
        titleTV.setGravity(Gravity.CENTER_HORIZONTAL);
        LayoutParams titleTVRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        titleTV.setLayoutParams(titleTVRarams);
        titleTV.setText("登录");
        layoutRoot.addView(titleTV);
        /**-----------title end------------**/

        /**-----------username start------------**/
        LinearLayout userNameLL = new LinearLayout(activity);
        LayoutParams userNameLLRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        userNameLLRarams.topMargin = topMargin;
        userNameLLRarams.gravity = Gravity.CENTER;
        userNameLL.setLayoutParams(userNameLLRarams);
        userNameLL.setOrientation(LinearLayout.HORIZONTAL);

        TextView userNameTV = new TextView(activity);
        userNameTV.setText("用户:");
        LayoutParams userNameTVParams = new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
        userNameTV.setLayoutParams(userNameTVParams);
        userNameLL.addView(userNameTV);

        final EditText userNameET = new EditText(activity);
        userNameET.setText("FineUser");
        LayoutParams userNameETParams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        userNameET.setLayoutParams(userNameETParams);
        userNameLL.addView(userNameET);

        layoutRoot.addView(userNameLL);
        /**-----------username end------------**/



        /**-----------password start------------**/
        LinearLayout passwordLL = new LinearLayout(activity);
        LayoutParams passwordLLRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        passwordLLRarams.gravity = Gravity.CENTER;
        passwordLL.setLayoutParams(passwordLLRarams);
        passwordLL.setOrientation(LinearLayout.HORIZONTAL);

        TextView passwordTV = new TextView(activity);
        passwordTV.setText("密码:");
        LayoutParams passwordTVParams = new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
        passwordTV.setLayoutParams(passwordTVParams);
        passwordLL.addView(passwordTV);

        EditText passwordET = new EditText(activity);
        passwordET.setText("FinePassword");
        passwordET.setEnabled(false);
        LayoutParams passwordETParams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        passwordET.setLayoutParams(passwordETParams);
        passwordLL.addView(passwordET);

        layoutRoot.addView(passwordLL);
        /**-----------password end------------**/



        /**-----------button start------------**/
        Button loginBtn = new Button(activity);
        loginBtn.setText("登录");
        LayoutParams loginBtnRarams = new LayoutParams(width, LayoutParams.WRAP_CONTENT);
        loginBtnRarams.topMargin = topMargin;
        loginBtn.setLayoutParams(loginBtnRarams);
        loginBtn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                String qid = userNameET.getText().toString().trim();
                if((TextUtils.isEmpty(qid)) || (!qid.matches("[A-Za-z0-9]{1,16}"))){
                    Toast.makeText(activity, "请输入1-16位字母数字组合", Toast.LENGTH_SHORT).show();
                }else{
                    String token = UUID.randomUUID().toString();
                    loginCallBack.loginSuccess(1, token);
                    dialog.dismiss();
                }
            }
        });
        layoutRoot.addView(loginBtn);
        /**-----------button end------------**/

        dialog.requestWindowFeature(Window.FEATURE_NO_TITLE);
        dialog.setContentView(layoutRoot);
        dialog.show();
    }

    public static void payUI(final Activity activity, final PayCallBack payCallBack){
        final Dialog dialog = new Dialog(activity);
        dialog.setCancelable(false);

        //上边距（dp值）
        int topMargin = FineTools.dip2px(activity, 20);
        int width = FineTools.dip2px(activity, 300);

        LinearLayout layoutRoot = new LinearLayout(activity);
        LayoutParams layoutRootRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT);
        layoutRootRarams.gravity = Gravity.CENTER;
        layoutRoot.setLayoutParams(layoutRootRarams);
        layoutRoot.setBackgroundColor(Color.GRAY);
        layoutRoot.setOrientation(LinearLayout.VERTICAL);

        /**-----------title start------------**/
        TextView titleTV = new TextView(activity);
        titleTV.setGravity(Gravity.CENTER_HORIZONTAL);
        LayoutParams titleTVRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        titleTV.setLayoutParams(titleTVRarams);
        titleTV.setText("充值");
        layoutRoot.addView(titleTV);
        /**-----------title end------------**/


        /**-----------button list start------------**/
        Button alipayBtn = new Button(activity);
        alipayBtn.setText("支付宝支付");
        LayoutParams alipayBtnRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        alipayBtnRarams.topMargin = topMargin;
        alipayBtn.setLayoutParams(alipayBtnRarams);
        layoutRoot.addView(alipayBtn);
        alipayBtn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                String param = "支付宝支付成功";
                payCallBack.paySuccess(1, param);
                dialog.dismiss();
            }
        });

        Button yinlianBtn = new Button(activity);
        yinlianBtn.setText("银联支付");
        LayoutParams yinlianBtnRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        yinlianBtn.setLayoutParams(yinlianBtnRarams);
        layoutRoot.addView(yinlianBtn);
        yinlianBtn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                String param = "银联支付成功";
                payCallBack.paySuccess(2, param);
                dialog.dismiss();
            }
        });

        Button weixinBtn = new Button(activity);
        weixinBtn.setText("微信支付");
        LayoutParams weixinBtnRarams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
        weixinBtn.setLayoutParams(weixinBtnRarams);
        layoutRoot.addView(weixinBtn);
        weixinBtn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                String param = "微信支付成功";
                payCallBack.paySuccess(3, param);
                dialog.dismiss();
            }
        });
        /**-----------button list end------------**/


        /**-----------button start------------**/
        Button cancelBtn = new Button(activity);
        cancelBtn.setText("取消");
        LayoutParams cancelBtnRarams = new LayoutParams(width, LayoutParams.WRAP_CONTENT);
        cancelBtnRarams.topMargin = topMargin;
        cancelBtn.setLayoutParams(cancelBtnRarams);
        layoutRoot.addView(cancelBtn);
        cancelBtn.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                String param = "支付失败,取消支付";
                Toast.makeText(activity, param, Toast.LENGTH_SHORT).show();
                payCallBack.payFailed(0, param);
                dialog.dismiss();
            }
        });
        /**-----------button end------------**/

        dialog.requestWindowFeature(Window.FEATURE_NO_TITLE);
        dialog.setContentView(layoutRoot);

        dialog.show();
    }

}
