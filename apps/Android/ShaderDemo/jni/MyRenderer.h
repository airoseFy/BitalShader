#ifndef _MY_RENDERER_H_
#define _MY_RENDERER_H_

#include <common/base.h>
#include <common/log.h>
#include <core/NeRenderer.h>
#include <core/NeProgram.h>
#include <core/NeShader.h>
#include <GLES3/gl3.h>

USING_NE_NAMESPACE;

class MyRenderer : public NeRenderer {
public:
	 MyRenderer() ;
	~MyRenderer() ;

protected:
	virtual inline void OnSurfaceCreated(int width, int height);
	virtual void OnSurfaceDestroyed(void);
	virtual void OnRender(int width, int height);

private:
	NeProgram	*m_Program;
	NeShader	*m_VertexShader;
	NeShader	*m_FragmentShader;
};
#endif //_MY_RENDERER_H_