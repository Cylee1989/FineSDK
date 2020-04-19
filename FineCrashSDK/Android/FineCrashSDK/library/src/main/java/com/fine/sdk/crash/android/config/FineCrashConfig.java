package com.fine.sdk.crash.android.config;

/**
 * 崩溃SDK配置类
 *
 * @author Cylee
 */
public class FineCrashConfig {

    /**
     * 版本号
     */
    public static final String VERSION = "1.0.0";

    /**
     * 语言类型
     */
    public static final String ENV_TYPE_CPP = "cpp";
    public static final String ENV_TYPE_JAVA = "java";
    public static final String ENV_TYPE_C_SHARP = "c#";

    /**
     * 上报地址
     */
    public static final String CRASH_REPORT_URL = "http://192.168.199.114:7777/report";
    /**
     * 上报时间(时间戳(秒))
     */
    public static final String CRASH_PARAMS_REPORT_TIME = "report_time";
    /**
     * 发生时间(时间戳(秒))
     */
    public static final String CRASH_PARAMS_TIME = "time";
    /**
     * 使用时间(分钟）
     */
    public static final String CRASH_PARAMS_USE_TIME = "use_time";
    /**
     * 是否需要通过字符表解码(true:需要, false:不需要)
     */
    public static final String CRASH_PARAMS_IS_DECODE = "is_decode";
    /**
     * 出错信息
     */
    public static final String CRASH_PARAMS_MSG = "msg";
    /**
     * 异常进程#线程
     */
    public static final String CRASH_PARAMS_THREAD = "thread";


    /**
     * 应用信息
     */
    public static final String CRASH_PARAMS_APP = "app";
    /**
     * 应用包名
     */
    public static final String CRASH_PARAMS_APP_BUNDLE = "bundle";
    /**
     * 开发者平台中的应用编号
     */
    public static final String CRASH_PARAMS_APP_ID = "id";
    /**
     * APP名称
     */
    public static final String CRASH_PARAMS_APP_NAME = "name";
    /**
     * SDK的版本
     */
    public static final String CRASH_PARAMS_APP_SDKVER = "sdkver";
    /**
     * APP的版本
     */
    public static final String CRASH_PARAMS_APP_VER = "ver";
    /**
     * 前后台状态(1:前台运行, 2:后台运行)
     */
    public static final String CRASH_PARAMS_APP_RUN_FLAG = "run_flag";
    /**
     * 屏幕方向(1:竖屏, 2:横屏)
     */
    public static final String CRASH_PARAMS_APP_SCREEN_TYPE = "screen_type";


    /**
     * 设备信息
     */
    public static final String CRASH_PARAMS_DEVICE = "device";
    /**
     * 设备型号
     */
    public static final String CRASH_PARAMS_DEVICE_MODEL = "model";
    /**
     * 设备品牌
     */
    public static final String CRASH_PARAMS_DEVICE_MAKE = "make";
    /**
     * CPU架构
     */
    public static final String CRASH_PARAMS_DEVICE_CPU_TYPE = "cpu_type";
    /**
     * 可用RAM(MB)
     */
    public static final String CRASH_PARAMS_DEVICE_AVAILABLE_RAM = "available_ram";
    /**
     * 可用磁盘(GB)
     */
    public static final String CRASH_PARAMS_DEVICE_AVAILABLE_DISK = "available_disk";
    /**
     * 连接类型,值域 {-1,2G,3G,4G,WIFI} -1表示未知。
     */
    public static final String CRASH_PARAMS_DEVICE_NW = "nw";
    /**
     * 运营商
     */
    public static final String CRASH_PARAMS_DEVICE_CARRIER = "carrier";
    /**
     * 操作系统 0:Android 1:iOS
     */
    public static final String CRASH_PARAMS_DEVICE_OS = "os";
    /**
     * 操作系统版本
     */
    public static final String CRASH_PARAMS_DEVICE_OSV = "osv";
    /**
     * 设备类型
     * 0：phone
     * 1：tablet
     * -1: 未知
     */
    public static final String CRASH_PARAMS_DEVICE_TYPE = "type";
    /**
     * 操作系统语言。例如：“zh”
     */
    public static final String CRASH_PARAMS_DEVICE_LNG = "lng";
    /**
     * Android Google广告ID (Android系统时必须)
     */
    public static final String CRASH_PARAMS_DEVICE_GAID = "gaid";


    /**
     * 扩展信息
     */
    public static final String CRASH_PARAMS_EXT = "ext";
    /**
     * 存放自定义Key, Value的字符串
     */
    public static final String CRASH_PARAMS_EXT_CUSTOM = "custom";


}
