using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System;

public delegate void Unity3DCallBackDelegate(string jsonStr);

public class FineSDK 
{

	private static FineSDK _instance;

	public static FineSDK Instance
    {
        get
        {
            if (_instance == null) {
                _instance = new FineSDK();
            }
            return _instance;
        }
    }

    #if UNITY_ANDROID || UNITY_EDITOR
	    //编辑器环境下或者安卓发布下使用
	    const string libname = "FineSDK";
	#else
	    //IOS环境下使用
	    const string libname = "__Internal";
	#endif
    
    [DllImport(libname)]
    public static extern void initSDK(string jsonString, Unity3DCallBackDelegate dlg);
    [DllImport(libname)]
    public static extern void callUniversalFunction(string functionName, string jsonString);

    public void FineInitSDK(string jsonString, Unity3DCallBackDelegate dlg) {
        initSDK(jsonString, dlg);
    }

    public void FineCallUniversalFunction(string functionName, string jsonString) {
        callUniversalFunction(functionName, jsonString);
    }

}
