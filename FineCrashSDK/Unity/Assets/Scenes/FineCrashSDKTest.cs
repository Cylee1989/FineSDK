using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class FineCrashSDKTest : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        FineCrashSDK.Instance.Start();
    }

    // Update is called once per frame
    void Update()
    {

    }

    private void OnGUI()
    {

        if (GUI.Button(new Rect(200, 200, 100, 50), "除零"))
        {
            int num = 0;
            int result = 1 / num;
        }

        if (GUI.Button(new Rect(400, 200, 100, 50), "数组越界"))
        {
            int[] list = { 10 };
            list[1] = 1;
        }

        if (GUI.Button(new Rect(600, 200, 100, 50), "空指针"))
        {
            string str = null;
            Debug.Log(str.ToString());
        }

    }

}
