#ifndef _NE_CONTEXT_H_
#define _NE_CONTEXT_H_

//	gl headers	
#include <EGL/egl.h>

//	c/c++ std headers

//	local headers
#include <base.h>
#include <NeProgram.h>

NE_NAMESPACE_BEGIN

class IContext {
public:
	virtual IContext *CreateContext() = 0;
	virtual IContext *GetCurrentContext() = 0;

	static void MakeCurrentContext(IContext *context);
	static IContext* GetCurrentContext(IContext)
};

class ContextWrapper{
public:
	virtual UseProgram(NeProgram *program) = 0;
	virtual BindAttribLocation(NeProgram *program, int index, const char* attrib) = 0;
};

class Context {
public:
	Context();
};

NE_NAMESPACE_END

#endif //_NE_CONTEXT_H_