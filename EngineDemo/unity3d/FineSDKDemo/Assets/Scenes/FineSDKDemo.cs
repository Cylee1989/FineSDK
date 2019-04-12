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

        if (GUI.Button(new Rect(200, 0, 200, 200), "初始化")){
            Debug.Log("initSDK");
            FineSDK.Instance.FineInitSDK("", new Unity3DCallBackDelegate(onCallBack));
        }

        if (GUI.Button(new Rect(200, 210, 200, 200), "登录")){
            Debug.Log("login");
            FineSDK.Instance.FineCallUniversalFunction("login","");
        }

        if (GUI.Button(new Rect(200, 420, 200, 200), "充值")){
            Debug.Log("pay");
            FineSDK.Instance.FineCallUniversalFunction("pay","");
        }

        if (GUI.Button(new Rect(200, 630, 200, 200), "注销")){
            Debug.Log("logout");
            FineSDK.Instance.FineCallUniversalFunction("logout","");
        }

        if (GUI.Button(new Rect(200, 840, 200, 200), "退出")){
            Debug.Log("exit");
            FineSDK.Instance.FineCallUniversalFunction("exit","");
        }

    }

    [MonoPInvokeCallback(typeof(Unity3DCallBackDelegate))]
    public static void onCallBack(string values) {
        Debug.Log("onCallBack: "+values);
    }
    
}
