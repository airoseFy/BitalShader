#ifndef _AN_SURFACE_H_
#define _AN_SURFACE_H_

#include <common/base.h>
#include <core/NeSurface.h>

#include <EGL/egl.h>

USING_NE_NAMESPACE;

class AN_Surface : public NeSurface {
public:
	AN_Surface(EGLNativeWindowType win);
	//AN_Surface(EGLNativeWindowType win, NeRenderer *renderer);
	virtual ~AN_Surface() = default;

	//virtual inline void CreateSurface(int width, int height) = default;
	//virtual inline void DestroySurface(void) = default;
	//virtual inline void Render(void) = default;
	//virtual inline void Present(void) = default;
	virtual void Render(void);
protected:
	bool Initialize(void);

private:
	EGLDisplay	m_Display;
	EGLConfig	m_Config;
	EGLSurface	m_Surface;
	EGLContext	m_Context;
	EGLNativeWindowType	m_Window;
};

#endif //_AN_SURFACE_H_