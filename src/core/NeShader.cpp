#include "base.h"
#include "NeShader.h"

NE_NAMESPACE_BEGIN

NeShader::NeShader(NeShaderType type)
{
	m_ShaderType = type;
	m_Compiled = false;
	m_Source = nullptr;
	m_ShaderId = (type == NeShaderType::SHADER_TYPE_FRAGMENT) ? glCreateShader(GL_FRAGMENT_SHADER) : glCreateShader(GL_VERTEX_SHADER);
}

NeShader::NeShader(NeShaderType type, const char* const source)
{
	m_ShaderType = type;
	m_Compiled = false;
	m_ShaderId = (type == NeShaderType::SHADER_TYPE_FRAGMENT) ? glCreateShader(GL_FRAGMENT_SHADER) : glCreateShader(GL_VERTEX_SHADER);
	this->LoadSource(source);
}

NeShader::~NeShader()
{
	if (m_ShaderId != 0) glDeleteShader(m_ShaderId);
}

GLenum NeShader::Compile(void) noexcept
{
	glCompileShader(m_ShaderId);

	GLint compiled = 0;
	glGetShaderiv(m_ShaderId, GL_COMPILE_STATUS, &compiled);

	if (!compiled)
	{
		GLint len;
		glGetShaderiv(m_ShaderId, GL_INFO_LOG_LENGTH, &len);
		if (len > 0)
		{
			char log_info[len];
			glGetShaderInfoLog(m_ShaderId, len, &len, log_info);
			info("Shader", "Compile Error : %s", log_info);
		}
	}
	else {
		m_Compiled = true;
	}

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printGLError(error);
	}

	return error;
}

/*	ShaderFactory	*/
NeShader* NeShaderFactory::CreateShader(NeShaderType type)
{
	return new NeShader(type);
}

NeShader* NeShaderFactory::CreateShader(NeShaderType type, const char* const source)
{
	return new NeShader(type, source);
}

NeShader* NeShaderFactory::CreateVertexShader()
{
	return new NeShader(NeShaderType::SHADER_TYPE_VERTEX);
}

NeShader* NeShaderFactory::CreateVertexShader(const char* const source)
{
	return new NeShader(NeShaderType::SHADER_TYPE_VERTEX, source);
}

NeShader* NeShaderFactory::CreateFragmentShader()
{
	return new NeShader(NeShaderType::SHADER_TYPE_FRAGMENT);
}

NeShader* NeShaderFactory::CreateFragmentShader(const char* const source)
{
	return new NeShader(NeShaderType::SHADER_TYPE_FRAGMENT, source);
}

NE_NAMESPACE_END