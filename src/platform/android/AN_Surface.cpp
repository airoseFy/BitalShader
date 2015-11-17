#include <common/log.h>
#include "AN_Surface.h"

#define TAG "AN_Surface"

AN_Surface::AN_Surface(EGLNativeWindowType win):
	m_Display(EGL_NO_DISPLAY), m_Surface(EGL_NO_SURFACE)
{
	//if (m_Display == EGL_NO_DISPLAY)
	//{
	//	this->Initialize();
	//}

	//m_Surface = eglCreateWindowSurface(m_Display, m_Config, win, NULL);
	//if (EGL_NO_SURFACE == m_Surface)
	//{
	//	info(TAG, "eglCreateWindowSurface failed!");
	//	return;
	//}

	//int width, height;
	//if (EGL_TRUE == eglQuerySurface(m_Display, m_Surface, EGL_WIDTH, &width) &&
	//	EGL_TRUE == eglQuerySurface(m_Display, m_Surface, EGL_HEIGHT, &height))
	//{
	//	this->SetWidth(width);
	//	this->SetHeight(height);
	//	info(TAG, "Surface width = %d, height = %d", this->GetWidth(), this->GetHeight());
	//	if (EGL_TRUE != eglMakeCurrent(m_Display, m_Surface, m_Surface, m_Context))
	//	{
	//		EGLint error = eglGetError();
	//		//printEGLError(error);			
	//		info(TAG, "eglMakeCurrent failed!");
	//	}
	//}
}

bool AN_Surface::Initialize(void)
{
	/*-----------------------------------
	 |	Initialize Display
	 +----------------------------------*/
	if ((m_Display = eglGetDisplay(EGL_DEFAULT_DISPLAY)) == EGL_NO_DISPLAY)
	{
		info(TAG, "EGL_NO_DISPLAY");
		return false;
	}

	if (EGL_TRUE != eglInitialize(m_Display, 0, 0))
	{
		info(TAG, "eglInitialize failed!");
		return false;
	}

	EGLint num;
	const EGLint attribs[] = {
		EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
		EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
		EGL_BLUE_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_RED_SIZE, 8,
		EGL_DEPTH_SIZE, 24, EGL_NONE
	};

	/*-----------------------------------
	 |	Choose Config
	 +----------------------------------*/
	eglChooseConfig(m_Display, attribs, &m_Config, 1, &num);
	if (!num)
	{
		const EGLint attribs[] = {
			EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
			EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
			EGL_BLUE_SIZE, 8,
			EGL_GREEN_SIZE, 8,
			EGL_RED_SIZE, 8,
			EGL_DEPTH_SIZE, 16, EGL_NONE
		};

		eglChooseConfig(m_Display, attribs, &m_Config, 1, &num);
		info(TAG, "depth is 16");
	}
	else {
		info(TAG, "depth is 24");
	}

	if (!num)
	{
		info(TAG, "eglChooseConfig failed!");
		return false;
	}

	int format;
	eglGetConfigAttrib(m_Display, m_Config, EGL_NATIVE_VISUAL_ID, &format);

	//ANativeWindow_setBuffersGeometry(m_Window, 0, 0, format);

	/*-----------------------------------
	 |	Create Context
	 +----------------------------------*/

	const EGLint context_attribs[] = {
		EGL_CONTEXT_CLIENT_VERSION, 2, //Request opengl ES2.0
		EGL_NONE };
	m_Context = eglCreateContext(m_Display, m_Config, NULL, NULL);
	if (EGL_NO_CONTEXT == m_Context)
	{
		info(TAG, "eglCreateContext failed!");
		return false;
	}
}

void AN_Surface::Render(void)
{
	NeSurface::Render();
	//if (EGL_TRUE != eglSwapBuffers(m_Display, m_Surface))
	//{
	//	info(TAG, "eglSwapBuffers error!");
	//	EGLint error = eglGetError();
	//}
}