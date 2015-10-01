//add for git commit
//nothing
#include <stdio.h>
//#include <jni.h>
#include </usr/lib/jvm/java-1.7.0-openjdk-i386/include/jni.h> //loacte at /usr/lib/jvm/java-1.7.0-openjdk-i386/include/(PC)
#include <stdlib.h>
//compiling command:
//gcc -I /usr/lib/jvm/java-1.7.0-openjdk-i386/include/ -shared -o libnative.so native.c
//or
//#include </usr/lib/jvm/java-1.7.0-openjdk-i386/include/jni.h> and with command:
//gcc -shared -o libnative.so native.c

//option shared: Produce a shared object which can then be linked with other objects to form an executable. 

#if 0
typedef struct {
    char *name;          /* Java里调用的函数名 */
    char *signature;    /* JNI字段描述符, 用来表示Java里调用的函数的参数和返回值类型 */
    void *fnPtr;          /* C语言实现的本地函数 */
} JNINativeMethod;
#endif

jint ledOpen(JNIEnv *env, jobject cls)
{
	return 0;
}
void ledClose(JNIEnv *env, jobject cls)
{
	//return 0;
}
jint ledCtrl(JNIEnv *env, jobject cls, jint which, jint status)
{
	return 0;
}


static const JNINativeMethod methods[] = {
	{"ledOpen", "()I", (void *)ledOpen}, 
	{"ledClose", "()V", (void *)ledClose}, 
	{"ledCtrl", "(II)I", (void *)ledCtrl}, 
};

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm, void *reserved)
{
	JNIEnv *env;
	jclass cls;

	if ((*jvm)->GetEnv(jvm, (void **)&env, JNI_VERSION_1_4)) {
		return JNI_ERR; /* JNI version not supported */
	}
	cls = (*env)->FindClass(env, "com/aspirs/hardlibrary/HardControl"); //adding path when finding class HardControl
	if (cls == NULL) {
		return JNI_ERR;
	}
	//2. map c_hello() to hello() in java
	if((*env)->RegisterNatives(env, cls, methods, sizeof(methods)/sizeof(methods[0])) < 0) /* the last arg means the number of members in array methods */
		return JNI_ERR;
	return JNI_VERSION_1_4;
}


