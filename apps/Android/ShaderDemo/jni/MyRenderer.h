#ifndef _MY_RENDERER_H_
#define _MY_RENDERER_H_

#include <common/base.h>
#include <common/log.h>
#include <core/NeRenderer.h>
#include <GLES2/gl2.h>

USING_NE_NAMESPACE;

class MyRenderer : public NeRenderer {
public:
	 MyRenderer() = default;
	~MyRenderer() = default;

protected:
	virtual inline void OnSurfaceCreated(int width, int height)
	{
		info("MyRenderer", "OnSurfaceCreated");
	}

	virtual void OnSurfaceDestroyed(void)
	{
		info("MyRenderer", "OnSurfaceCreated");
	}

	virtual void OnRender(int width, int height)
	{
		info("MyRenderer", "OnRender");
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glFlush();
	}
};
#endif //_MY_RENDERER_H_