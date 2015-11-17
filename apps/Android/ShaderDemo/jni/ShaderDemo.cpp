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
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_OnSurfaceCreated(JNIEnv *env, jclass, jobject jsurface)
{
	//info("ShaderJNI", "onSurfaceCreated");
	pSurface = new AN_Surface(ANativeWindow_fromSurface(env, jsurface));
	pSurface->SetRenderer(new MyRenderer());
}
  
/*
 * Class:     com_bigital_shaderdemo_MainActivity
 * Method:    onSurfaceChanged
 * Signature: (Landroid/view/SurfaceView;)V
 */
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_OnSurfaceChanged(JNIEnv *env, jclass jcls, jint width, jint height)
{
	//info("ShaderJNI", "onSurfaceChanged");
	//if( pTask != nullptr ) pTask->Start(ANativeWindow_fromSurface(env, jsurface));	
	pSurface->CreateSurface(width, height);
}
 
/*
 * Class:     com_bigital_shaderdemo_MainActivity
 * Method:    onSurfaceDestroy
 * Signature: (Landroid/view/SurfaceView;)V
 */
JNIEXPORT void JNICALL Java_com_bigital_shaderdemo_MainActivity_OnDrawFrame(JNIEnv *env, jclass, jobject jsurface)
{
	//info("ShaderJNI", "OnDrawFrame");
	pSurface->Render();
}

}