#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" {

JNIEXPORT jstring JNICALL Java_com_sanwaku2_ndkcallbacksample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject obj) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring JNICALL Java_com_sanwaku2_ndkcallbacksample_MainActivity_stringFromJNI2(
        JNIEnv *env,
        jobject obj,
        jobject callback) {

    __android_log_print(ANDROID_LOG_DEBUG, "JNI", "call native.");
    jclass targetClass;
    jmethodID mid;

    targetClass = env->GetObjectClass(callback);
    mid = env->GetMethodID(targetClass, "onComplete", "()V");
    if (mid == 0) {
        __android_log_print(ANDROID_LOG_DEBUG, "JNI", "method not found.");
    }

    env->CallVoidMethod(callback, mid);

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

}
