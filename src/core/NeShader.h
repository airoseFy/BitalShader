#ifndef _NE_SHADER_H_
#define _NE_SHADER_H_

//	c/c++ std headers
#include <exception>

//	std headers	
#include <string>

//	local headers
#include "base.h"
#include "log.h"
#include "glError.h"
#include "platform.h"

using namespace std;

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
	 explicit NeShader(NeShaderType type, bool compiled = false);
	 NeShader(NeShaderType type, const char* const source, bool compiled = false);
	 NeShader(NeShaderType type, const string& source, bool compiled = false);
	~NeShader();

public:
	GLenum /* error_no */ LoadSource(const char* const source) noexcept;

	GLenum /* error_no */ LoadSource(GLsizei count, const char* const * src_array, const GLint *len_array);

	GLenum /* error_no */ Compile(void) noexcept;

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
	virtual char const* OnShaderCreated() noexcept;
	//virtual void OnAttached(void) noexcept;
	//virtual void OnDettached(void) noexcept;
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