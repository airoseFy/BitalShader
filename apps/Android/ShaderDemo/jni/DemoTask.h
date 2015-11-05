#ifndef _DEMO_TASK_H_
#define _DEMO_TASK_H_
#include <thread>
#include "base.h"
#include "NeSurface.h"

USING_NE_NAMESPACE;

class DemoTask{
public:
	 DemoTask() = default;
	~DemoTask() = default;
	
	void Start(EGLNativeWindowType win) noexcept;
	void Stop()  noexcept;
	
protected:
	void OnRun() noexcept;
	
private:
	EGLNativeWindowType m_Window;
	bool m_Started;
	std::thread m_Task;
	Surface m_Surface;
};

#endif //_DEMO_TASK_H_