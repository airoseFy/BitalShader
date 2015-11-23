#ifndef _NE_BASE_H_
#define _NE_BASE_H_

#if defined(__ANDROID__) || defined(ANDROID)
#include <GLES3/gl3.h>
#elif defined(__APPLE__)
#import <OpenGLES/ES3/gl.h>
#endif

#ifdef __cplusplus
	#define NE_NAMESPACE_BEGIN	namespace NatureEngine {
	#define NE_NAMESPACE_END	}
	#define USING_NE_NAMESPACE using namespace NatureEngine
#else
	#define NE_NAMESPACE_BEGIN
	#define NE_NAMESPACE_END
	#define USING_NE_NAMESPACE
#endif


#endif //_NE_BASE_H_