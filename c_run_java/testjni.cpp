#include <jni.h>
#include <stdio.h>
#ifdef WIN
#include "windows.h"  

typedef jint (WINAPI *_CreateJavaVM)(JavaVM **, void **, void *);
#endif

class TestJNI
{
public:
    TestJNI();
    void say();
private:
    JavaVMOption options[1];
    JNIEnv *env;
    JavaVM *jvm;
    JavaVMInitArgs vm_args;
    long status;
};

TestJNI::TestJNI()
{
    options[0].optionString = "-Djava.class.path=.";
    vm_args.version = JNI_VERSION_1_2;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_TRUE;
#ifdef WIN
	HINSTANCE hInstance = LoadLibrary(TEXT("C:\\Program Files (x86)\\Java\\jre1.8.0_74\\bin\\client\\jvm.dll"));
	_CreateJavaVM m_CreateJavaVM = (_CreateJavaVM)GetProcAddress(hInstance, "JNI_CreateJavaVM");
	status = (*m_CreateJavaVM)(&jvm, (void**)&env, &vm_args);  
#else
    status = JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);
#endif	
}

void TestJNI::say()
{
    if(status != JNI_ERR){
        jclass cls = env->FindClass("demo/Test");
//        jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
//        jstring arg = NewJString(name.c_str());
//        jobject demo = env->NewObject(cls, mid, arg);
        jmethodID mid = env->GetMethodID(cls, "<init>", "()V");//调用demo.Test类的构造函数，第二个参数必须填"<init>"
        jobject test = env->NewObject(cls, mid);
        mid = env->GetMethodID(cls, "printHello", "()V");
//        env->CallObjectMethod(demo, mid);
        env->CallVoidMethod(test, mid);
    }
}

int main()
{
	printf("kaishi\n");
    TestJNI test;
    test.say();
	printf("jieshu\n");
}
