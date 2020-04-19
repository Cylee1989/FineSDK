using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class FineCrashSDK
{
    private static FineCrashSDK _instance;

    public static FineCrashSDK Instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = new FineCrashSDK();
            }
            return _instance;
        }
    }

    public void Start()
    {
        Application.logMessageReceived += HandleLog;
    }

    #if UNITY_ANDROID || UNITY_EDITOR
        const string libname = "fine_breakpad";
    #else
	    const string libname = "__Internal";
    #endif

    [DllImport(libname)]
    private static extern void callBackExceptionFromUnity(string logString, string stackTrace);

    private void HandleLog(string logString, string stackTrace, LogType type)
    {
        if (type == LogType.Exception || type == LogType.Error)
        {
        #if UNITY_ANDROID || UNITY_EDITOR
            callJavaFunc(logString, stackTrace);
        #else
            callBackExceptionFromUnity(logString, stackTrace);
        #endif
        }
    }

    private void callJavaFunc(string logString, string stackTrace)
    {
        try
        {
            using (AndroidJavaClass jc = new AndroidJavaClass("com.fine.sdk.crash.android.FineCrashSDK"))
            {
                using (AndroidJavaObject jo = jc.GetStatic<AndroidJavaObject>("instance"))
                {
                    jo.Call("callBackExceptionFromUnity", logString, stackTrace);
                }
            }
        }
        catch (System.Exception ex)
        {
            Debug.Log("FineCrashSDK Unity Error:" + ex.Message);
        }
    }

}
