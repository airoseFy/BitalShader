#ifndef _NE_SURFACE_H_
#define _NE_SURFACE_H_

/*--------------------------
 |	Includes
 +-------------------------*/
#include "base.h"
#include "NeRenderer.h"

NE_NAMESPACE_BEGIN

class NeSurface{
public:
             NeSurface();
    virtual ~NeSurface() = default;
    
    void SetRenderer(NeRenderer *render) noexcept;
    NeRenderer *GetRenderer(void) const noexcept;
    
public:
    virtual inline void CreateSurface(int width, int height);
    virtual inline void DestroySurface(void);
    virtual inline void Render(void);
    virtual inline void Present(void);
    
private:
    NeRenderer *m_Renderer;
    int m_Width;
    int m_Height;
};

/*class Surface{
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
};*/

NE_NAMESPACE_END
#endif //_NE_SURFACE_H_