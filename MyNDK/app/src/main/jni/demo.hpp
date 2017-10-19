//
// Created by Hankin on 2017/10/9.
// @email hankin.huan@gmail.com
//

#ifndef MYNDK_DEMO_H
#define MYNDK_DEMO_H

#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include <string.h>
#include <android/log.h>

#define log_debug "mydebug---"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,log_debug,__VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

    //java中的中文字符串与c++中的中文字符串需要转化
    char* jstringToChar_cpp(JNIEnv* env,jstring jstr)
    {
        char* cs;
        cs=(char*)env->GetStringUTFChars(jstr,NULL);
        return cs;
    }
    jstring charTojstring_cpp(JNIEnv* env,char* str)
    {
        jsize len=strlen(str);
        jclass clsstring=env->FindClass("java/lang/String");
        jstring strencode=env->NewStringUTF("UTF-8");
        jmethodID mid=env->GetMethodID(clsstring,"<init>","([BLjava/lang/String;)V");
        jbyteArray barr=env->NewByteArray(len);
        env->SetByteArrayRegion(barr,0,len,(jbyte*)str);
        return (jstring)env->NewObject(clsstring,mid,barr,strencode);
    }

    //这两个是MainActivity中的native函数
    JNIEXPORT void JNICALL Java_hankin_myndk_MainActivity_cpp(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_hankin_myndk_MainActivity_java(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif

class Demo
{
public:
    void printFromJava(JNIEnv *env, jobject obj);//在此函数中调用java函数
};

#endif //MYNDK_DEMO_H
