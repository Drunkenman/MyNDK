LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := myndk

LOCAL_LDLIBS := -llog

LOCAL_SRC_FILES := .\demo.cpp

include $(BUILD_SHARED_LIBRARY)