#include "log.h"
#include "AN_Surface.h"
#include "MyRenderer.h"
#include <android/native_window_jni.h>

AN_Surface *pSurface;

extern "C" {

/*
 * Class:     com_bigital_shaderdemo_MainActivity
 * Method:    onSurfaceCreated
 * Signature: (Landroid/view/SurfaceView;)V
 */
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_onSurfaceCreated(JNIEnv *env, jobject, jobject jsurface)
{
	info("ShaderJNI", "onSurfaceCreated");
	pSurface = new AN_Surface(ANativeWindow_fromSurface(env, jsurface));
	pSurface->SetRenderer(new MyRenderer());
}
  
/*
 * Class:     com_bigital_shaderdemo_MainActivity
 * Method:    onSurfaceChanged
 * Signature: (Landroid/view/SurfaceView;)V
 */
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_onSurfaceChanged(JNIEnv *env, jobject, jobject jsurface)
{
	info("ShaderJNI", "onSurfaceChanged");
	//if( pTask != nullptr ) pTask->Start(ANativeWindow_fromSurface(env, jsurface));
	pSurface->Render();
}
 
/*
 * Class:     com_bigital_shaderdemo_MainActivity
 * Method:    onSurfaceDestroy
 * Signature: (Landroid/view/SurfaceView;)V
 */
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_onSurfaceDestroy(JNIEnv *env, jobject, jobject jsurface)
{
	info("ShaderJNI", "onSurfaceDestroy");
	pSurface->DestroySurface();
	delete pSurface;
}

}