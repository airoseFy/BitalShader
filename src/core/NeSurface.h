#ifndef _NE_SURFACE_H_
#define _NE_SURFACE_H_

/*--------------------------
 |	Includes
 +-------------------------*/
#include "base.h"

NE_NAMESPACE_BEGIN

class NeRenderer;
class NeSurface{
public:
             NeSurface();
			 NeSurface(NeRenderer *renderer);
    virtual ~NeSurface();
    
    void SetRenderer(NeRenderer *renderer) noexcept;
    NeRenderer *GetRenderer(void) const noexcept;
    
public:
    virtual void CreateSurface(int width, int height);
    virtual void DestroySurface(void);
    virtual void Render(void);
    virtual void Present(void);
    
protected:
	inline void SetWidth(int width) noexcept { m_Width = width;  }
	inline void SetHeight(int height) noexcept { m_Height = height; }
	inline int GetWidth(void) const noexcept { return m_Width; }
	inline int GetHeight(void) const noexcept { return m_Height; }

private:
    NeRenderer *m_Renderer;
    int m_Width;
    int m_Height;
};

NE_NAMESPACE_END
#endif //_NE_SURFACE_H_