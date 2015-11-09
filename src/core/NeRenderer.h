#ifndef _NE_RENDERER_H_
#define _NE_RENDERER_H_

/*--------------------------
|	Includes
+-------------------------*/
#include "base.h"

NE_NAMESPACE_BEGIN

class NeSurface;
class NeRenderer {
public:
	virtual ~NeRenderer() = default;

protected:
	virtual void OnSurfaceCreated(int width, int height) = 0;
	virtual void OnSurfaceDestroyed(void) = 0;
	virtual void OnRender(int width, int height) = 0;

	friend class NeSurface;
};

NE_NAMESPACE_END

#endif //_NE_RENDERER_H_