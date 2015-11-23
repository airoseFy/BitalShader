#ifndef _NE_SHADER_H_
#define _NE_SHADER_H_

//	c/c++ std headers
#include <exception>
#include <string>
#include <functional>

//	local headers
#include "base.h"
#include "log.h"
#include "glError.h"

using namespace std;

NE_NAMESPACE_BEGIN

class NeShader;
class NeShaderFactory;

enum class NeShaderType {
	SHADER_TYPE_VERTEX			= 0x01,
	SHADER_TYPE_FRAGMENT		= 0x02,
	SHADER_TYPE_TESS_CONTROL	= 0x03,
	SHADER_TYPE_TESS_EVALUATION = 0x04,
	SHADER_TYPE_GEOMETRY		= 0x05,
	SHADER_TYPE_COMPUTE			= 0x06,
};

class NeShader {
public:
	NeShader(NeShaderType type, bool compiled = false);
	NeShader(NeShaderType type, std::function<const char*()> func, bool compiled = false);
	NeShader(NeShaderType type, const char* const source, bool compiled = false);
	NeShader(NeShaderType type, const string& source, bool compiled = false);
	virtual ~NeShader();

public:
	void LoadSource(const char* const source) noexcept;

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
	/*----------------------------------------------------------------
	+when shader create,return the shader source code string
	+@param void \n
	+@return	 \n OUT : source code string
	-----------------------------------------------------------------*/
	virtual char const* OnShaderCreated() noexcept;
	friend class NeProgram;  //declare friend class Program

private:
	NeShaderType m_ShaderType;
	GLuint	m_ShaderId;
	bool	m_Compiled;
	char const* m_Source;
};

class NeVertexShader : public NeShader{
public:
	explicit NeVertexShader(bool compiled = false);
	virtual ~NeVertexShader() = default;
};

class NeFragmentShader : public NeShader {
public:
	explicit NeFragmentShader(bool compiled = false);
	virtual ~NeFragmentShader() = default;
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