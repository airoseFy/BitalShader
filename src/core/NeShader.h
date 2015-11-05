#ifndef _NE_SHADER_H_
#define _NE_SHADER_H_

//	c/c++ std headers
#include <exception>

//	gl headers	
#include <GLES3/gl3.h>

//	local headers
#include "base.h"
#include "log.h"
#include "glError.h"

NE_NAMESPACE_BEGIN

class Shader;
class ShaderFactory;
class ShaderException;
class Fragment;

class ShaderException : public std::exception {
public:
	explicit ShaderException(const char* msg) { _what = msg; }
	~ShaderException() = default;

	virtual const char* what() const noexcept
	{
		return _what;
	}
private:
	const char* _what;
};

class Shader {
public:
	 explicit Shader(GLenum type);
	 Shader(GLenum type, const char* const source);
	~Shader();

public:
	inline GLenum /* error_no */ LoadSource(const char* const source) noexcept
	{
		m_Source = source;
		if (m_ShaderId != 0 && source != nullptr)
		{
			glShaderSource(m_ShaderId, 1, &m_Source, NULL);
		}
		
		return GL_NO_ERROR;
	}

	inline GLenum /* error_no */ LoadSource(GLsizei count, const char* const * src_array, const GLint *len_array)
	{
		if (m_ShaderId != 0)
		{
			glShaderSource(m_ShaderId, count, src_array, len_array);
		}

		return GL_NO_ERROR;
	}

	inline GLenum /* error_no */ Compile(void) throw (ShaderException)
	{
		glCompileShader(m_ShaderId);

		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printGLError(error);
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

		return error;
	}

	inline GLenum /* error_no */ Attach(Fragment& fragment) const noexcept
	{
		return GL_NO_ERROR;
	}

	inline GLenum /* error_no */ Detach(Fragment& fragment) const noexcept
	{
		return GL_NO_ERROR;
	}

public:
	inline GLenum GetShaderType(void) const noexcept
	{
		return m_ShaderType;
	}

	inline GLuint GetShaderId(void) const noexcept
	{
		return m_ShaderId;
	}

protected:
	friend class Program;  //declare friend class Program

private:
	GLenum	m_ShaderType;
	GLuint	m_ShaderId;
	bool	m_Compiled;
	char const* m_Source;
};

class ShaderFactory {
public:
	static Shader* CreateShader(GLenum type);
	static Shader* CreateShader(GLenum type, const char* const source);
	static Shader* CreateVertexShader();
	static Shader* CreateVertexShader(const char* const source);
	static Shader* CreateFragmentShader();
	static Shader* CreateFragmentShader(const char* const source);
};

NE_NAMESPACE_END

#endif //_NE_SHADER_H_