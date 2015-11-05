#ifndef _NE_PROGRAM_H_
#define _NE_PROGRAM_H_

//	c/c++ std headers
#include <vector>

//	gl headers	
#include <GLES3/gl3.h>

//	local headers
#include "base.h"

NE_NAMESPACE_BEGIN

class Shader;
class Program {
public:
	 Program();

	~Program();

	 GLenum /* error_no */ AttachShader(Shader* shader) noexcept;
	
	 GLenum /* error_no */ DetachShader(Shader* shader) noexcept;

	 GLenum /* error_no */ Link(void) const noexcept;

	 GLenum /* error_no */ Use(void) const noexcept;

private:
	GLuint m_ProgramId;
};

NE_NAMESPACE_END

#endif //_NE_PROGRAM_H_