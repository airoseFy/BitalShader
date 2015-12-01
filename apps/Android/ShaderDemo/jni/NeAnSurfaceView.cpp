#include "log.h"
#include "NeAnSurfaceView.h"
#include <android/native_window_jni.h>
#include <GLES3/gl3.h>

void NeAnSurfaceView::OnSurfaceCreated(jobject surface)
{
	
}

void NeAnSurfaceView::OnSurfaceChanged(JNIEnv *env, jobject surface)
{
	m_Window = ANativeWindow_fromSurface(env, surface);
	m_Width  = ANativeWindow_getWidth(m_Window);
	m_Height = ANativeWindow_getHeight(m_Window);
	info("NeAnSurfaceView", "OnSurfaceChanged w = %d, h = %d", m_Width, m_Height);
	
	InitGLSurface();
	InitGLContext();
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glViewport(0, 0, m_Width, m_Height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	OnRender( m_Width, m_Height );
}

void NeAnSurfaceView::OnSurfaceDestroyed(JNIEnv *env, jobject surface)
{
	if( m_Display != EGL_NO_DISPLAY )
	{
		eglMakeCurrent( m_Display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT );
		if( m_Context != EGL_NO_CONTEXT )
		{
			eglDestroyContext( m_Display, m_Context );
		}
		
		if( m_Surface != EGL_NO_SURFACE )
		{
			eglDestroySurface( m_Display, m_Surface );
		}	
		eglTerminate( m_Display );	
	}
	
	m_Display = EGL_NO_DISPLAY;
	m_Context = EGL_NO_CONTEXT;
	m_Surface = EGL_NO_SURFACE;	
}

bool NeAnSurfaceView::InitGLSurface(void) noexcept
{
    m_Display = eglGetDisplay( EGL_DEFAULT_DISPLAY );
    eglInitialize( m_Display, 0, 0 );

    /*
     * Here specify the attributes of the desired configuration.
     * Below, we select an EGLConfig with at least 8 bits per color
     * component compatible with on-screen windows
     */
    const EGLint attribs[] = { EGL_RENDERABLE_TYPE,
            EGL_OPENGL_ES2_BIT, //Request opengl ES2.0
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_BLUE_SIZE, 8, EGL_GREEN_SIZE, 8,
            EGL_RED_SIZE, 8, EGL_DEPTH_SIZE, 24, EGL_NONE };
    EGLint num_configs;
    eglChooseConfig( m_Display, attribs, &m_Config, 1, &num_configs );

    if( !num_configs )
    {
        info("NeAnSurfaceView", "Unable to retrieve EGL config" );
        return false;
    }

    m_Surface = eglCreateWindowSurface( m_Display, m_Config, m_Window, NULL );

    /* EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is
     * guaranteed to be accepted by ANativeWindow_setBuffersGeometry().
     * As soon as we picked a EGLConfig, we can safely reconfigure the
     * ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID. */
    EGLint format;
    eglGetConfigAttrib( m_Display, m_Config, EGL_NATIVE_VISUAL_ID, &format );
    ANativeWindow_setBuffersGeometry( m_Window, 0, 0, format );
	return true;
}

bool NeAnSurfaceView::InitGLContext(void) noexcept
{
    const EGLint context_attribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, //Request opengl ES2.0
            EGL_NONE };
    m_Context = eglCreateContext( m_Display, m_Config, NULL, context_attribs );

    if( eglMakeCurrent( m_Display, m_Surface, m_Surface, m_Context ) == EGL_FALSE )
    {
        info("NeAnSurfaceView", "Unable to eglMakeCurrent" );
        return false;
    }

	return true;
}

void NeAnSurfaceView::OnRender(int w, int h) noexcept
{
	
}