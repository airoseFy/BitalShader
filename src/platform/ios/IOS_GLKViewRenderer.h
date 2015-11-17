#ifndef _IOS_GLKVIEW_RENDER_H_
#define _IOS_GLKVIEW_RENDER_H_

#include "base.h"
#include "log.h"
#include "NeRenderer.h"
#include "NeProgram.h"
#include "NeShader.h"

USING_NE_NAMESPACE;

class IOS_GLKViewRenderer:public NeRenderer{
public:
     IOS_GLKViewRenderer() ;
    ~IOS_GLKViewRenderer() ;
    
public:
    virtual void OnSurfaceCreated(int width, int height);
    virtual void OnSurfaceDestroyed(void);
    virtual void OnRender(int width, int height);
    
private:
    NeProgram	*m_Program;
    NeShader	*m_VertexShader;
    NeShader	*m_FragmentShader;
};

#endif //_IOS_GLKVIEW_RENDER_H_