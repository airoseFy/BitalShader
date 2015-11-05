#include "NeProgram.h"
#include "NeShader.h"
#include "log.h"
#include "glError.h"

NE_NAMESPACE_BEGIN

Program::Program()
	:m_ProgramId(glCreateProgram())
{

}

Program::~Program()
{
	if (m_ProgramId != 0) glDeleteProgram(m_ProgramId);
}

GLenum Program::AttachShader(Shader* shader)
{
	glAttachShader(m_ProgramId, shader->GetShaderId());
	return glGetError();
}

GLenum Program::DetachShader(Shader* shader)
{
	glDetachShader(m_ProgramId, shader->GetShaderId());
	return glGetError();
}

GLenum Program::Link(void) const
{
	glLinkProgram(m_ProgramId);

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printGLError(error);

		GLint len = 0;
		glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &len);
		char info_log[len];
		glGetProgramInfoLog(m_ProgramId, len, &len, info_log);
		info("Program", "Link Error : %s", info_log);
	}

	return error;
}

GLenum Program::Use(void) const
{
	glUseProgram(m_ProgramId);

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printGLError(error);

		GLint len = 0;
		glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &len);
		char info_log[len];
		glGetProgramInfoLog(m_ProgramId, len, &len, info_log);
		info("Program", "Link Error : %s", info_log);
	}

	return error;
}

NE_NAMESPACE_END