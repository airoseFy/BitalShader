#ifndef _GL_ERROR_H_
#define _GL_ERROR_H_

#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include "log.h"

inline void printEGLError(EGLint e) noexcept
{
	switch (e) {
	case EGL_SUCCESS:
		error("EGL", "No ERROR.");
		break;
	case EGL_NOT_INITIALIZED:
		error("EGL", "ERROR : EGL_NOT_INITIALIZED");
		break;
	case EGL_BAD_ACCESS:
		error("EGL", "ERROR : EGL_BAD_ACCESS");
		break;
	case EGL_BAD_ALLOC:
		error("EGL", "ERROR : EGL_BAD_ALLOC");
		break;
	case EGL_BAD_ATTRIBUTE:
		error("EGL", "ERROR : EGL_BAD_ATTRIBUTE");
		break;
	case EGL_BAD_CONTEXT:
		error("EGL", "ERROR : EGL_BAD_CONTEXT");
		break;
	case EGL_BAD_CONFIG:
		error("EGL", "ERROR : EGL_BAD_CONFIG");
		break;
	case EGL_BAD_CURRENT_SURFACE:
		error("EGL", "ERROR : EGL_BAD_CURRENT_SURFACE");
		break;
	case EGL_BAD_DISPLAY:
		error("EGL", "ERROR : EGL_BAD_DISPLAY");
		break;
	case EGL_BAD_SURFACE:
		error("EGL", "ERROR : EGL_BAD_SURFACE");
		break;
	case EGL_BAD_MATCH:
		error("EGL", "ERROR : EGL_BAD_MATCH");
		break;
	case EGL_BAD_PARAMETER:
		error("EGL", "ERROR : EGL_BAD_PARAMETER");
		break;
	case EGL_BAD_NATIVE_PIXMAP:
		error("EGL", "ERROR : EGL_BAD_NATIVE_PIXMAP");
		break;
	case EGL_BAD_NATIVE_WINDOW:
		error("EGL", "ERROR : EGL_BAD_NATIVE_WINDOW");
		break;
	case EGL_CONTEXT_LOST:
		error("EGL", "ERROR : EGL_CONTEXT_LOST");
		break;
	default:
		break;
	}
}

inline void printGLError(GLenum e) noexcept
{
	switch (e) {
	case GL_NO_ERROR:
		error("GL", "ERROR : GL_NO_ERROR");
		break;
	case GL_INVALID_ENUM:
		error("GL", "ERROR : GL_INVALID_ENUM");
		break;
	case GL_INVALID_VALUE:
		error("GL", "ERROR : GL_INVALID_VALUE");
		break;
	case GL_INVALID_OPERATION:
		error("GL", "ERROR : GL_INVALID_OPERATION");
		break;
	case GL_OUT_OF_MEMORY:
		error("GL", "ERROR : GL_OUT_OF_MEMORY");
		break;
	default:
		error("GL", "ERROR : UNKNOWN");
		break;
	}
}

#endif //_GL_ERROR_H_