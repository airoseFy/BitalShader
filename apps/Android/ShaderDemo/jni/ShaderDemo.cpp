#include "log.h"
#include "ShaderDemo.h"
#include "DemoTask.h"
#include <android/native_window_jni.h>

DemoTask *pTask = nullptr;

/*
 * Class:     com_bigital_shaderdemo_MainActivity
 * Method:    onSurfaceCreated
 * Signature: (Landroid/view/SurfaceView;)V
 */
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_onSurfaceCreated(JNIEnv *env, jobject, jobject jsurface)
{
	info("ShaderJNI", "onSurfaceCreated");
	if(pTask == nullptr){
		pTask = new DemoTask();
	}
}
  
/*
 * Class:     com_bigital_shaderdemo_MainActivity
 * Method:    onSurfaceChanged
 * Signature: (Landroid/view/SurfaceView;)V
 */
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_onSurfaceChanged(JNIEnv *env, jobject, jobject jsurface)
{
	info("ShaderJNI", "onSurfaceChanged");
	if( pTask != nullptr ) pTask->Start(ANativeWindow_fromSurface(env, jsurface));
}
 
/*
 * Class:     com_bigital_shaderdemo_MainActivity
 * Method:    onSurfaceDestroy
 * Signature: (Landroid/view/SurfaceView;)V
 */
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_onSurfaceDestroy(JNIEnv *env, jobject, jobject jsurface)
{
	info("ShaderJNI", "onSurfaceDestroy");
	if(pTask != nullptr)
	{
		pTask->Stop();
		delete pTask;
		pTask = nullptr;
	}	
}