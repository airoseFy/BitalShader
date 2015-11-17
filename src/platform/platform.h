#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#ifdef __ANDROID__
#include <GLES3/gl3.h>
#else
#import <OpenGLES/ES3/gl.h>
#endif

#endif //_PLATFORM_H_
