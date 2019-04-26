using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using AOT;
using System.Runtime.InteropServices;
using System;

public class FineSDKDemo : MonoBehaviour
{
    // Start is called before the first frame update
    void Start() {
    }

    // Update is called once per frame
    void Update() {
        
    }


    private void OnGUI() {

        if (GUI.Button(new Rect(200, 100, 100, 50), "初始化")){
            Debug.Log("initSDK");
            FineSDK.Instance.FineInitSDK("", new Unity3DCallBackDelegate(onCallBack));
        }

        if (GUI.Button(new Rect(320, 100, 100, 50), "登录")){
            Debug.Log("login");
            FineSDK.Instance.FineCallUniversalFunction("login","");
        }

        if (GUI.Button(new Rect(440, 100, 100, 50), "充值")){
            Debug.Log("pay");
            FineSDK.Instance.FineCallUniversalFunction("pay","");
        }

        if (GUI.Button(new Rect(560, 100, 100, 50), "注销")){
            Debug.Log("logout");
            FineSDK.Instance.FineCallUniversalFunction("logout","");
        }

        if (GUI.Button(new Rect(200, 300, 100, 50), "显示悬浮窗")){
            Debug.Log("showToolBar");
            FineSDK.Instance.FineCallUniversalFunction("showToolBar","");
        }

        if (GUI.Button(new Rect(320, 300, 100, 50), "隐藏悬浮窗")){
            Debug.Log("hideToolBar");
            FineSDK.Instance.FineCallUniversalFunction("hideToolBar","");
        }

        if (GUI.Button(new Rect(440, 300, 100, 50), "用户中心")){
            Debug.Log("enterUserCenter");
            FineSDK.Instance.FineCallUniversalFunction("enterUserCenter","");
        }

        if (GUI.Button(new Rect(560, 300, 100, 50), "退出")){
            Debug.Log("exit");
            FineSDK.Instance.FineCallUniversalFunction("exit","");
        }

    }

    [MonoPInvokeCallback(typeof(Unity3DCallBackDelegate))]
    public static void onCallBack(string values) {
        Debug.Log("onCallBack: "+values);
    }
    
}
