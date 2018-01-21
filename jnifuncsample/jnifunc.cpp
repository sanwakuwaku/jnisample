#include "jnifunc.h"

/*
 * Class:     JniFuncMain
 * Method:    createJniObject
 * Signature: ()LJniTest;
 */
JNIEXPORT jobject JNICALL Java_JniFuncMain_createJniObject(JNIEnv *env, jclass clazz) {
  jclass targetClass;
  jmethodID mid;
  jobject newObject;
  jstring helloStr;
  jfieldID fid;
  jint staticIntField;
  jint result;

  // 1.JniFuncMainクラスのstaticIntFieldの値を取得
  fid = env->GetStaticFieldID(clazz, "staticIntField", "I");
  staticIntField = env->GetStaticIntField(clazz, fid);
  printf("[CPP]  JniFuncMainクラスのstaticIntFieldを取得\n");
  printf("       JniFuncMain.staticIntField = %d\n", staticIntField);

  // オブジェクト生成に必要なクラスを探す
  targetClass = env->FindClass("JniTest");
  // コンストラクタを探す コンストラクタの場合はメソッド名に<init>を使用する。
  // メソッドのシグネチャはjavapで確認できる。
  mid = env->GetMethodID(targetClass, "<init>", "(I)V");

  // JniTestオブジェクトを生成(オブジェクトのリファレンスを返す)
  // コンストラクタはint型の引数を受け取ることができる
  printf("[CPP]  JniTestオブジェクトの生成\n");
  newObject = env->NewObject(targetClass, mid, 100);

  // オブジェクトのメソッド呼び出し
  mid = env->GetMethodID(targetClass, "callByNative", "(I)I");
  result = env->CallIntMethod(newObject, mid, 200);
  
  // JniオブジェクトのintFieldの値の設定
  fid = env->GetFieldID(targetClass, "intField", "I");
  printf("[CPP]  JniTestオブジェクトのintField値を200に設定\n");
  env->SetIntField(newObject, fid, result);

  // 生成したオブジェクトを返す
  return newObject;
}
