#include "MyRenderer.h"

MyRenderer::MyRenderer():
	m_Program(new NeProgram), 
	m_VertexShader(new NeShader(NeShaderType::SHADER_TYPE_VERTEX)),
	m_FragmentShader(new NeShader(NeShaderType::SHADER_TYPE_FRAGMENT))
{

}

MyRenderer::~MyRenderer()
{
	if (m_VertexShader != nullptr) {
		delete m_VertexShader;
		m_VertexShader = nullptr;
	}

	if (m_FragmentShader != nullptr) {
		delete m_FragmentShader;
		m_FragmentShader = nullptr;
	}

	if (m_Program != nullptr) {
		delete m_Program;
		m_Program = nullptr;
	}
}

void MyRenderer::OnSurfaceCreated(int width, int height)
{
	info("MyRenderer", "OnSurfaceCreated");
	char vShaderScript[] =
	//	"#version 300 es							\n"
		"attribute vec4 vPosition;	\n"
		"void main()								\n"
		"{											\n"
		"gl_Position = vPosition;					\n"
		"}											\n";

	char fShaderScript[] =
	//	"#version 300 es						\n"
		"precision mediump float;				\n"
		//"out vec4 fragColor;					\n"
		"void main()							\n"
		"{										\n"
		"gl_FragColor = vec4 (1.0, 0.0, 0.0, 1.0); \n"
		"}										\n";

	m_VertexShader->LoadSource(vShaderScript);
	m_FragmentShader->LoadSource(fShaderScript);
	m_VertexShader->Compile();
	m_FragmentShader->Compile();

	m_Program->AttachShader(m_VertexShader);
	m_Program->AttachShader(m_FragmentShader);
	m_Program->Link();

	glBindAttribLocation(m_Program->GetProgramId(), 0, "vPoistion");
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void MyRenderer::OnSurfaceDestroyed(void)
{
	info("MyRenderer", "OnSurfaceCreated");
}

void MyRenderer::OnRender(int width, int height)
{
	//info("MyRenderer", "OnRender");
	GLfloat vVertices[] = { 
		 0.0f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f };

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_Program->Use();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}