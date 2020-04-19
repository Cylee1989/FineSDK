# FineSDK

FineSDK是一套SDK集合，其中包含多种常用SDK支持项目。

[FineNativeSDK] 跨平台聚合游戏接入SDK  
[FinePushSDK] 推送系统SDK  
[FineDeviceSDK] 设备信息SDK  
[FineCrashSDK] 崩溃收集SDK  


### FineNativeSDK

FineNativeSDK是一套跨平台游戏接入框架，制作SDK的目的是为了方便第三方iOS和Android渠道SDK接入工作，极大节省了人员接入和分包上线运营所需大量开发时间。

目前支持两种引擎版本: [Cocos2dx+Lua] [Unity3D+C#]


### FinePushSDK

FinePushSDK是一套推送系统，包含了Android和iOS双端客户端SDK，还有Go后端推送服务，实现了本地和远程推送功能。


### FineDeviceSDK

FineDeviceSDK是一套设备信息SDK，可以获取设备属性信息，其中包含了全面屏、刘海屏、挖孔屏、钻孔屏等适配方案。

屏幕适配功能覆盖了多家设备厂商，其中包含华为、小米、三星、VIVO、OPPO、努比亚、联想等。

### FineCrashSDK

FineCrashSDK是一套使用谷歌Breakpad开源框架，来收集应用的异常和崩溃信息，其中包括C++、Java、OC、C#异常的收集。