//
// Created by Hankin on 2017/10/9.
// @email hankin.huan@gmail.com
//

#include "demo.hpp"

JNIEXPORT void JNICALL Java_hankin_myndk_MainActivity_cpp(JNIEnv *env, jobject obj, jstring jstr)
{
    char * str = jstringToChar_cpp(env, jstr);
    LOGD("%s", str);
}

JNIEXPORT void JNICALL Java_hankin_myndk_MainActivity_java(JNIEnv *env, jobject obj)
{
    Demo d;
    d.printFromJava(env, obj);
}

void Demo::printFromJava(JNIEnv *env, jobject obj)
{
    jclass clazz = env->FindClass("hankin/myndk/MainActivity");
    if (!clazz)
    {
        LOGD("find class error.");
        return;
    }
    jmethodID mid = env->GetMethodID(clazz,"print","(Ljava/lang/String;)V");
    if (!mid)
    {
        LOGD("find print method error.");
        return;
    }
    env->CallVoidMethod(obj, mid, charTojstring_cpp(env, "你好来自c++"));
}
