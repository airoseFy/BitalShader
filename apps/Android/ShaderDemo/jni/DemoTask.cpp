#include "DemoTask.h"

void DemoTask::Start(EGLNativeWindowType win)
{
	m_Started = true;
	m_Window = win;
	m_Task = std::thread(std::bind(&DemoTask::OnRun, this));
	m_Task.detach();
}

void DemoTask::Stop()
{
	m_Started = false;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	m_Surface.OnSurfaceDestroy();
}

void DemoTask::OnRun()
{
	m_Surface.OnSurfaceCreated(m_Window);
	while( m_Started )
	{
		m_Surface.Render();
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
	}	
}