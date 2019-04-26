package com.fine.sdk.dispatcher;

import android.os.Bundle;

import com.fine.ndk.NDKHelper;
import com.fine.sdk.BaseSDK;
import com.fine.sdk.InterfaceFunc;
import com.fine.sdk.constant.FineSDKCode;
import com.xiaomi.gamecenter.sdk.GameInfoField;
import com.xiaomi.gamecenter.sdk.MiCommplatform;
import com.xiaomi.gamecenter.sdk.MiErrorCode;
import com.xiaomi.gamecenter.sdk.OnLoginProcessListener;
import com.xiaomi.gamecenter.sdk.OnPayProcessListener;
import com.xiaomi.gamecenter.sdk.entry.MiAccountInfo;
import com.xiaomi.gamecenter.sdk.entry.MiBuyInfo;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by Cylee on 2019/4/24.
 */

public class FineDispatcher extends BaseSDK implements InterfaceFunc {

    @Override
    public void initSDK(String str) {
        Map<String, Object> map = new HashMap<>();
        map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Init);
        map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Success);
        map.put(FineSDKCode.Key_ErrMsg, "初始化成功");
        NDKHelper.sendToNative(map);
    }

    @Override
    public void login(String str) {
        MiCommplatform.getInstance().miLogin(gameActivity, new OnLoginProcessListener() {
            @Override
            public void finishLoginProcess(int i, MiAccountInfo miAccountInfo) {
                Map<String, Object> map = new HashMap<>();
                map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Login);
                switch (i) {
                    case MiErrorCode.MI_XIAOMI_GAMECENTER_SUCCESS:
                        map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Success);
                        map.put(FineSDKCode.Key_ErrMsg, "登录成功");
                        map.put("uid", miAccountInfo.getUid());
                        map.put("token", miAccountInfo.getSessionId());
                        break;
                    default:
                        map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Failed);
                        map.put(FineSDKCode.Key_ErrMsg, "登录失败(错误码-" + i + ")");
                        break;
                }
                NDKHelper.sendToNative(map);
            }
        });
    }

    @Override
    public void pay(String str) {
        try {
            JSONObject json = new JSONObject(str);
            String orderId = json.optString("OrderID");
            String productPrice = json.optString("ProductPrice");
            String extInfo = json.optString("ExtInfo");
            String pid = json.optString("Pid");
            String serverId = json.optString("ServerID");
            String roleName = json.optString("RoleName");
            String roleLevel = json.optString("RoleLevel");
            String balance = json.optString("Balance");
            String vip = json.optString("Vip");
            String guild = json.optString("Guild");

            int amount = Integer.parseInt(productPrice);

            MiBuyInfo miBuyInfo = new MiBuyInfo();
            miBuyInfo.setCpOrderId(orderId);
            miBuyInfo.setCpUserInfo(extInfo);
            miBuyInfo.setAmount(amount);

            Bundle mBundle = new Bundle();
            mBundle.putString(GameInfoField.GAME_USER_BALANCE, balance); // 用户余额
            mBundle.putString(GameInfoField.GAME_USER_GAMER_VIP, vip); // vip等级
            mBundle.putString(GameInfoField.GAME_USER_LV, roleLevel); // 角色等级
            mBundle.putString(GameInfoField.GAME_USER_PARTY_NAME, guild); // 工会，帮派
            mBundle.putString(GameInfoField.GAME_USER_ROLE_NAME, roleName); // 角色名称
            mBundle.putString(GameInfoField.GAME_USER_ROLEID, pid); // 角色id
            mBundle.putString(GameInfoField.GAME_USER_SERVER_NAME, serverId); // 所在服务器
            miBuyInfo.setExtraInfo(mBundle);
            MiCommplatform.getInstance().miUniPay(gameActivity, miBuyInfo, new OnPayProcessListener() {
                @Override
                public void finishPayProcess(int i) {
                    Map<String, Object> map = new HashMap<>();
                    map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Pay);
                    switch (i) {
                        case MiErrorCode.MI_XIAOMI_PAYMENT_SUCCESS:
                            map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Success);
                            map.put(FineSDKCode.Key_ErrMsg, "充值成功");
                            map.put("Money", "10.00");
                            break;
                        default:
                            map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Failed);
                            map.put(FineSDKCode.Key_ErrMsg, "充值失败");
                            break;
                    }
                    NDKHelper.sendToNative(map);
                }
            });
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void logout(String str) {
        Map<String, Object> map = new HashMap<>();
        map.put(FineSDKCode.Key_Action, FineSDKCode.Action_Logout);
        map.put(FineSDKCode.Key_ErrCode, FineSDKCode.ErrCode_Success);
        map.put(FineSDKCode.Key_ErrMsg, "注销成功");
        NDKHelper.sendToNative(map);
    }

    @Override
    public void exit(String str) {
        super.exit(str);
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
