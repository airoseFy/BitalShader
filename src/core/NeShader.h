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

class NeShader;
class NeShaderFactory;
class NeFragment;

enum class NeShaderType {
	SHADER_TYPE_VERTEX   = 0x01,
	SHADER_TYPE_FRAGMENT = 0x02
};

class NeShader {
public:
	 explicit NeShader(NeShaderType type);
	 NeShader(NeShaderType type, const char* const source);
	~NeShader();

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

	GLenum /* error_no */ Compile(void) noexcept;

	inline GLenum /* error_no */ Attach(NeFragment& fragment) const noexcept
	{
		return GL_NO_ERROR;
	}

	inline GLenum /* error_no */ Detach(NeFragment& fragment) const noexcept
	{
		return GL_NO_ERROR;
	}

public:
	inline NeShaderType GetShaderType(void) const noexcept
	{
		return m_ShaderType;
	}

	inline GLuint GetShaderId(void) const noexcept
	{
		return m_ShaderId;
	}

protected:
	friend class NeProgram;  //declare friend class Program

private:
	NeShaderType m_ShaderType;
	GLuint	m_ShaderId;
	bool	m_Compiled;
	char const* m_Source;
};

class NeShaderFactory {
public:
	static NeShader* CreateShader(NeShaderType type);
	static NeShader* CreateShader(NeShaderType type, const char* const source);
	static NeShader* CreateVertexShader();
	static NeShader* CreateVertexShader(const char* const source);
	static NeShader* CreateFragmentShader();
	static NeShader* CreateFragmentShader(const char* const source);
};

NE_NAMESPACE_END

#endif //_NE_SHADER_H_