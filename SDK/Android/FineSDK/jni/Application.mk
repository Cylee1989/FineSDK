APP_ABI :=armeabi-v7a
APP_PLATFORM:=android-9
APP_STL:=gnustl_static
APP_CFLAGS += -Wno-error=format-security -Wformat-security -Wwrite-strings
APP_CPPFLAGS := -frtti
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS += -std=c++11 -D__STDC_LIMIT_MACROS 
