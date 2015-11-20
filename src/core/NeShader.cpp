#include "base.h"
#include "NeShader.h"

NE_NAMESPACE_BEGIN

static GLuint CreateShader(NeShaderType type)
{
	GLuint shaderHandle = 0;

	switch (type) {
	case NeShaderType::SHADER_TYPE_VERTEX:
		shaderHandle = glCreateShader(GL_VERTEX_SHADER);
		break;
	case NeShaderType::SHADER_TYPE_FRAGMENT:
		shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	//case NeShaderType::SHADER_TYPE_TESS_CONTROL:
	//	shaderHandle = glCreateShader(GL_TESS_CONTROL_SHADER);
	//	break;
	//case NeShaderType::SHADER_TYPE_TESS_EVALUATION:
	//	shaderHandle = glCreateShader(GL_TESS_EVALUATION_SHADER);
	//	break;
	//case NeShaderType::SHADER_TYPE_GEOMETRY:
	//	shaderHandle = glCreateShader(GL_GEOMETRY_SHADER);
	//	break;
	//case NeShaderType::SHADER_TYPE_COMPUTE:
	//	shaderHandle = glCreateShader(GL_COMPUTE_SHADER);
	//	break;
	}

	return shaderHandle;
}

NeShader::NeShader(NeShaderType type, bool compiled)
{
	m_ShaderType = type;
	m_ShaderId	 = CreateShader(type);
	m_Source	 = this->OnShaderCreated();	
	if (compiled) this->Compile();
}

NeShader::NeShader(NeShaderType type, std::function<const char*()> func, bool compiled)
{
	m_ShaderType = type;
	m_ShaderId = CreateShader(type);
	m_Source = func();
	if (compiled) this->Compile();
}

NeShader::NeShader(NeShaderType type, const char* const source, bool compiled)
{
	m_ShaderType = type;
	m_ShaderId   = CreateShader(type);
	m_Source	 = source;
	if (compiled) this->Compile();
}

NeShader::NeShader(NeShaderType type, const string& source, bool compiled):
	NeShader(type, source.c_str(), compiled)
{

}

NeShader::~NeShader()
{
	if (m_ShaderId != 0) glDeleteShader(m_ShaderId);
}

void NeShader::LoadSource(const char* const source) noexcept
{
	m_Source = source;
}

GLenum NeShader::Compile(void) noexcept
{

	if (m_Source == nullptr) return GL_INVALID_VALUE;

	glShaderSource(m_ShaderId, 1, &m_Source, NULL);
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

/*	NeVertexShader	*/
NeVertexShader::NeVertexShader(bool compiled):
	NeShader(NeShaderType::SHADER_TYPE_VERTEX)
{

}

/*	NeFragmentShader	*/
NeFragmentShader::NeFragmentShader(bool compiled) :
	NeShader(NeShaderType::SHADER_TYPE_VERTEX)
{

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