#include "base.h"
#include "NeShader.h"

NE_NAMESPACE_BEGIN

Shader::Shader(GLenum type)
	:m_ShaderType(type), m_ShaderId(glCreateShader(type)), m_Compiled(false), m_Source(nullptr)
{

}

Shader::Shader(GLenum type, const char* const source)
	:m_ShaderType(type), m_ShaderId(glCreateShader(type)), m_Compiled(false)
{
	this->LoadSource(source);
}

Shader::~Shader()
{
	if (m_ShaderId != 0) glDeleteShader(m_ShaderId);
}

/*	ShaderFactory	*/
Shader* ShaderFactory::CreateShader(GLenum type)
{
	return new Shader(type);
}

Shader* ShaderFactory::CreateShader(GLenum type, const char* const source)
{
	return new Shader(type, source);
}

Shader* ShaderFactory::CreateVertexShader()
{
	return new Shader(GL_VERTEX_SHADER);
}

Shader* ShaderFactory::CreateVertexShader(const char* const source)
{
	return new Shader(GL_VERTEX_SHADER, source);
}

Shader* ShaderFactory::CreateFragmentShader()
{
	return new Shader(GL_FRAGMENT_SHADER);
}

Shader* ShaderFactory::CreateFragmentShader(const char* const source)
{
	return new Shader(GL_FRAGMENT_SHADER, source);
}

NE_NAMESPACE_END