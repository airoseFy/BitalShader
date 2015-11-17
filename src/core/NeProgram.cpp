#include "NeProgram.h"
#include "NeShader.h"
#include "log.h"
#include "glError.h"

NE_NAMESPACE_BEGIN

NeProgram::NeProgram()
	:m_ProgramId(glCreateProgram())
{

}

NeProgram::~NeProgram()
{
	if (m_ProgramId != 0) glDeleteProgram(m_ProgramId);
}

GLenum NeProgram::AttachShader(NeShader* shader) noexcept
{
	glAttachShader(m_ProgramId, shader->GetShaderId());
	return glGetError();
}

GLenum NeProgram::DetachShader(NeShader* shader) noexcept
{
	glDetachShader(m_ProgramId, shader->GetShaderId());
	return glGetError();
}

GLenum NeProgram::Link(void) const noexcept
{
	glLinkProgram(m_ProgramId);

	GLint linked = 0;
	glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		info("Program", "Link failed!");
		GLint len = 0;
		glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &len);
		char info_log[len];
		glGetProgramInfoLog(m_ProgramId, len, &len, info_log);
		info("Program", "Link Error : %s", info_log);
	}
	
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printGLError(error);
	}

	return error;
}

GLenum NeProgram::Use(void) const noexcept
{
	info("Program", "Use m_ProgramId = %d", m_ProgramId);
	glUseProgram(m_ProgramId);

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printGLError(error);

		GLint len = 0;
		glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &len);
		char info_log[len];
		glGetProgramInfoLog(m_ProgramId, len, &len, info_log);
		info("Program", "Use Error : %s", info_log);
	}

	return error;
}

NE_NAMESPACE_END