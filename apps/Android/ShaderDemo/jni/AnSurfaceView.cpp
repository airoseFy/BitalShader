#include "AnSurfaceView.h"
#include "NeAnSurfaceView.h"

NeAnSurfaceView *pSurface = nullptr;

JNIEXPORT void JNICALL Java_com_enature_AnSurfaceView_OnSurfaceCreated
(JNIEnv *env, jobject clz, jobject surface)
{
	if(pSurface == nullptr) pSurface = new NeAnSurfaceView();
	pSurface->OnSurfaceCreated(surface);
}

JNIEXPORT void JNICALL Java_com_enature_AnSurfaceView_OnSurfaceChanged
(JNIEnv *env, jobject clz, jobject surface)
{
	if(pSurface != nullptr) pSurface->OnSurfaceChanged(env, surface);
}

JNIEXPORT void JNICALL Java_com_enature_AnSurfaceView_OnSurfaceDestroyed
(JNIEnv *env, jobject clz, jobject surface)
{
	if(pSurface != nullptr) pSurface->OnSurfaceDestroyed(env, surface);
}

