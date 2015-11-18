#ifndef _NE_PROGRAM_H_
#define _NE_PROGRAM_H_

//	c/c++ std headers
#include <vector>

//	gl headers	
#include "platform.h"

//	local headers
#include "base.h"

NE_NAMESPACE_BEGIN

class NeShader;
class NeProgram {
public:
	NeProgram();

	~NeProgram();

public:
	GLenum /* error_no */ AttachShader(NeShader* shader) noexcept;
	
	GLenum /* error_no */ DetachShader(NeShader* shader) noexcept;

	GLenum /* error_no */ Link(void) const noexcept;

	GLenum /* error_no */ Use(void) const noexcept;

	GLuint GetProgramId(void) const noexcept;

private:
	GLuint m_ProgramId;
};

NE_NAMESPACE_END

#endif //_NE_PROGRAM_H_