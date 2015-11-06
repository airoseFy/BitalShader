#ifndef _NE_SURFACE_H_
#define _NE_SURFACE_H_

/*--------------------------
 |	Includes
 +-------------------------*/
#include <EGL/egl.h>
#include "base.h"

NE_NAMESPACE_BEGIN

class ISurface {
public:
	virtual ~ISurface() = default;

	virtual void AllocSurface(int width, int height);
	virtual void ReleaseSurface(void);
};

class Surface{
public:
	 Surface();
	~Surface();
	
	virtual void OnSurfaceCreated(EGLNativeWindowType win);
	virtual void OnSurfaceDestroy();
	virtual void OnSurfaceChanged(EGLNativeWindowType win, int width, int height);
	virtual void Render();
	
protected:
	virtual bool Initialize(void);
	virtual void OnRender();
	
private:	
	EGLDisplay	m_Display;
	EGLConfig	m_Config;
	EGLSurface	m_Surface;
	EGLContext	m_Context;
	EGLNativeWindowType	m_Window;
	
	int	m_Width;
	int m_Height;
};

NE_NAMESPACE_END
#endif //_NE_SURFACE_H_