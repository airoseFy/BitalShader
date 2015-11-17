#include "log.h"
#include "NeSurface.h"
#include "NeRenderer.h"

#define TAG "NeSurface"

NE_NAMESPACE_BEGIN

NeSurface::NeSurface() :
	m_Renderer(nullptr)
{

}

NeSurface::NeSurface(NeRenderer *renderer):
	m_Renderer(renderer)
{

}

NeSurface::~NeSurface()
{
	if (m_Renderer != nullptr) delete m_Renderer;
}

void NeSurface::SetRenderer(NeRenderer *renderer) noexcept
{
    m_Renderer = renderer;
}

NeRenderer* NeSurface::GetRenderer() const noexcept
{
    return m_Renderer;
}

void NeSurface::CreateSurface(int width, int height)
{
    m_Width  = width;
    m_Height = height;
	if(m_Renderer != nullptr) m_Renderer->OnSurfaceCreated(width, height);  
}

void NeSurface::DestroySurface()
{
	if(m_Renderer != nullptr) m_Renderer->OnSurfaceDestroyed();   
}

void NeSurface::Render()
{
	if(m_Renderer != nullptr) m_Renderer->OnRender(m_Width, m_Height);   
}

void NeSurface::Present()
{
    
}

NE_NAMESPACE_END