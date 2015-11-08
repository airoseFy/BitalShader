#include "log.h"
#include "NeSurface.h"

#define TAG "NeSurface"

NE_NAMESPACE_BEGIN

NeSurface::NeSurface():
    m_Renderer(nullptr)
{
    
}

void NeSurface::SetRenderer(NeRenderer *render) noexcept
{
    m_Renderer = render;
}

NeRenderer* NeSurface::GetRenderer() const noexcept
{
    return m_Renderer;
}

void NeSurface::CreateSurface(int width, int height)
{
    m_Width  = width;
    m_Height = height;
    m_Renderer->OnSurfaceCreated(width, height);
}

void NeSurface::DestroySurface()
{
    m_Renderer->OnSurfaceDestroy();
}

void NeSurface::Render()
{
    m_Renderer->OnRender(m_Width, m_Height);
}

void NeSurface::Present()
{
    
}

//Surface::Surface()
//:m_Display(EGL_NO_DISPLAY), m_Surface(EGL_NO_SURFACE)
//{
//	
//}
//
//Surface::~Surface()
//{
//	
//}
//
//void Surface::OnSurfaceCreated(EGLNativeWindowType win)
//{
//	info(TAG, "OnSurfaceCreated");
//	if(m_Display == EGL_NO_DISPLAY)
//	{
//		this->Initialize();
//	}
//	
//	m_Surface = eglCreateWindowSurface(m_Display, m_Config, win, NULL);
//	if(EGL_NO_SURFACE == m_Surface)
//	{
//		info(TAG, "eglCreateWindowSurface failed!");
//		return ;
//	}
//	
//	int width, height;
//	if(EGL_TRUE == eglQuerySurface(m_Display, m_Surface, EGL_WIDTH, &width) && 
//		EGL_TRUE == eglQuerySurface(m_Display, m_Surface, EGL_HEIGHT, &height))
//	{
//		m_Width  = width;
//		m_Height = height;
//		info(TAG, "Surface width = %d, height = %d", m_Width, m_Height);
//		if(EGL_TRUE != eglMakeCurrent(m_Display, m_Surface, m_Surface, m_Context))
//		{
//			EGLint error = eglGetError();
//			printEGLError(error);			
//			info(TAG, "eglMakeCurrent failed!");
//		}
//	}	
//}
//
//void Surface::OnSurfaceDestroy()
//{
//	if (EGL_TRUE != eglDestroySurface(m_Display, m_Surface)) info(TAG, "Destroy surface failed!");
//
//	if (EGL_TRUE != eglDestroyContext(m_Display, m_Context)) info(TAG, "Destroy context failed!");
//}
//
//void Surface::OnSurfaceChanged(EGLNativeWindowType win, int width, int height)
//{
//	/*if(width != m_Width || height != m_Height)
//	{
//		m_Surface = eglCreateWindowSurface(m_Display, m_Config, win, NULL);
//	}*/
//}
//
//bool Surface::Initialize(void)
//{
//	/*-----------------------------------
//	 |	Initialize Display
//	 +----------------------------------*/
//	if((m_Display = eglGetDisplay(EGL_DEFAULT_DISPLAY)) == EGL_NO_DISPLAY)
//	{
//		info(TAG, "EGL_NO_DISPLAY");
//		return false;	
//	}
//	
//	if(EGL_TRUE != eglInitialize(m_Display, 0, 0))
//	{
//		info(TAG, "eglInitialize failed!");
//		return false;			
//	}
//	
//	EGLint num;
//	const EGLint attribs[] = {
//		EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
//		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
//		EGL_BLUE_SIZE, 8,
//		EGL_GREEN_SIZE, 8,
//		EGL_RED_SIZE, 8,
//		EGL_DEPTH_SIZE, 24, EGL_NONE
//	};
//	
//	/*-----------------------------------
//	 |	Choose Config
//	 +----------------------------------*/
//	eglChooseConfig(m_Display, attribs, &m_Config, 1, &num);
//	if(!num)
//	{
//        const EGLint attribs[] = {
//			EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
//			EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
//			EGL_BLUE_SIZE, 8,
//			EGL_GREEN_SIZE, 8,
//			EGL_RED_SIZE, 8,
//			EGL_DEPTH_SIZE, 16, EGL_NONE
//		};
//		
//        eglChooseConfig( m_Display, attribs, &m_Config, 1, &num );
//		info(TAG, "depth is 16");
//	}else{
//		info(TAG, "depth is 24");
//	}
//	
//	if(!num)
//	{
//		info(TAG, "eglChooseConfig failed!");
//		return false;
//	}
//	
//	/*-----------------------------------
//	 |	Create Context
//	 +----------------------------------*/
//
//	const EGLint context_attribs[] = { 
//		EGL_CONTEXT_CLIENT_VERSION, 1, //Request opengl ES2.0
//		EGL_NONE };
//	m_Context = eglCreateContext( m_Display, m_Config, NULL, NULL );
//	if(EGL_NO_CONTEXT == m_Context)
//	{
//		info(TAG, "eglCreateContext failed!");
//		return false;
//	}		
//}
//
//void Surface::Render()
//{
//	//info(TAG, "Render");
//	this->OnRender();
//	if(EGL_TRUE != eglSwapBuffers(m_Display, m_Surface))
//	{
//		info(TAG, "eglSwapBuffers error!");
//		EGLint error = eglGetError();
//		printEGLError(error);
//	}
//}
//
//void Surface::OnRender()
//{
//	
//}

NE_NAMESPACE_END