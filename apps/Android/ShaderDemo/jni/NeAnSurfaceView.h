#ifndef _NE_ANSURFACEVIEW_H_
#define _NE_ANSURFACEVIEW_H_

#include "jni.h"
#include <EGL/egl.h>

class NeAnSurfaceView{
public:
	NeAnSurfaceView()  = default;
	~NeAnSurfaceView() = default;
	
public:
	void OnSurfaceCreated(jobject surface);
	void OnSurfaceChanged(JNIEnv *env, jobject surface);
	void OnSurfaceDestroyed(JNIEnv *env, jobject surface);
	
protected:
	bool InitGLSurface(void) noexcept;
	bool InitGLContext(void) noexcept;
	void OnRender(int w, int h) noexcept;
private:
	ANativeWindow*	m_Window;
	EGLDisplay	m_Display;
	EGLConfig	m_Config;
	EGLSurface	m_Surface;
	EGLContext	m_Context;
	int m_Width;
	int m_Height;
};

#endif //_NE_ANSURFACEVIEW_H_