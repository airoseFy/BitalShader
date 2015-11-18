#include "base.h"
#include "NeShader.h"

NE_NAMESPACE_BEGIN

NeShader::NeShader(NeShaderType type, bool compiled)
{
	m_ShaderType = type;
	m_ShaderId = (type == NeShaderType::SHADER_TYPE_FRAGMENT) ? glCreateShader(GL_FRAGMENT_SHADER) : glCreateShader(GL_VERTEX_SHADER);
	m_Source = this->OnShaderCreated();	
}

NeShader::NeShader(NeShaderType type, const char* const source, bool compiled)
{
	m_ShaderType = type;
	m_ShaderId = (type == NeShaderType::SHADER_TYPE_FRAGMENT) ? glCreateShader(GL_FRAGMENT_SHADER) : glCreateShader(GL_VERTEX_SHADER);
	m_Compiled = false;
	this->LoadSource(source);
}

NeShader::NeShader(NeShaderType type, const string& source, bool compiled):
	NeShader::NeShader(type, source.c_str(), compiled)
{

}

NeShader::~NeShader()
{
	if (m_ShaderId != 0) glDeleteShader(m_ShaderId);
}

GLenum /* error_no */ NeShader::LoadSource(const char* const source) noexcept
{
	m_Source = source;
	if (m_ShaderId != 0 && source != nullptr)
	{
		glShaderSource(m_ShaderId, 1, &m_Source, NULL);
	}

	return GL_NO_ERROR;
}

GLenum /* error_no */ NeShader::LoadSource(GLsizei count, const char* const * src_array, const GLint *len_array)
{
	if (m_ShaderId != 0)
	{
		glShaderSource(m_ShaderId, count, src_array, len_array);
	}

	return GL_NO_ERROR;
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

char const* NeShader::OnShaderCreated() noexcept
{
	return nullptr;
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