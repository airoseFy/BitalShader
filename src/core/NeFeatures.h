#ifndef _NE_FEATURES_H
#define _NE_FEATURES_H

#include "base.h"

NE_NAMESPACE_BEGIN

enum class NeGLVersion {
	GL_VERSION_1_0 = 0x01,
	GL_VERSION_2_0 = 0x02,
	GL_VERSION_3_0 = 0x03,
	GL_VERSION_3_1 = 0x04,
};


class NeFeatures {
public:
	static NeGLVersion GetGLVersion(void) const noexcept;

private:
	static NeGLVersion _s_gl_version;
};

//NeGLVersion NeFeatures::_s_gl_version 
NE_NAMESPACE_END

#endif //_NE_FEATURES_H