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

void MyRenderer::Render(JNIEnv *env, jobject bitmap) noexcept
{
	int ret = 0;
	AndroidBitmapInfo bitmapInfo;

	if ((ret = AndroidBitmap_getInfo(env, bitmap, &bitmapInfo)) < 0)
	{
		info("MyRenderer", "AndroidBitmap_getInfo failed!");
		return;
	}
	else {
		info("MyRenderer", "bitmapInfo width = %d, height = %d", bitmapInfo.width, bitmapInfo.height);
	}

	GLuint textureId;
	GLint location = glGetUniformLocation(m_Program->GetProgramId(), "s_texture");

	glGenTextures(1, &textureId);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glUniform1i(location, 0);

	void *pixels = nullptr;
	AndroidBitmap_lockPixels(env, bitmap, &pixels);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmapInfo.width, bitmapInfo.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	this->OnRender(m_Width, m_Height);
	AndroidBitmap_unlockPixels(env, bitmap);
	//GLenum format = GL_RGB;
	//if (bitmapInfo.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
	//	info("MyRenderer", "bitmapInfo format = ANDROID_BITMAP_FORMAT_RGBA_8888");
	//}
	//else if (bitmapInfo.format ==  ANDROID_BITMAP_FORMAT_RGB_565) {
	//	info("MyRenderer", "bitmapInfo format = ANDROID_BITMAP_FORMAT_RGB_565");
	//}
	//else if (bitmapInfo.format ==  ANDROID_BITMAP_FORMAT_RGBA_4444) {
	//	info("MyRenderer", "bitmapInfo format = ANDROID_BITMAP_FORMAT_RGBA_4444");
	//}
	//else if (bitmapInfo.format ==  ANDROID_BITMAP_FORMAT_A_8) {
	//	info("MyRenderer", "bitmapInfo format = ANDROID_BITMAP_FORMAT_A_8");
	//}
}

void MyRenderer::OnSurfaceCreated(int width, int height)
{
	info("MyRenderer", "OnSurfaceCreated");
	m_Width  = width;
	m_Height = height;
	char vShaderScript[] =
		"attribute vec4 a_position;		\n"
		"attribute vec2 a_texCoord;		\n"
		"varying vec2 v_texCoord;		\n"
		"void main()					\n"
		"{								\n"
		" gl_Position = a_position;		\n"
		" v_texCoord = a_texCoord;		\n"
		"}								\n";

	char fShaderScript[] =
		"precision mediump float;		\n"
		"varying vec2 v_texCoord;		\n"
		"uniform sampler2D s_texture;	\n"
		"void main()					\n"
		"{								\n"
		" gl_FragColor = texture2D(s_texture, v_texCoord); \n"
		"}								\n";

	m_VertexShader->LoadSource(vShaderScript);
	m_FragmentShader->LoadSource(fShaderScript);
	m_VertexShader->Compile();
	m_FragmentShader->Compile();

	m_Program->AttachShader(m_VertexShader);
	m_Program->AttachShader(m_FragmentShader);
	m_Program->Link();

	glBindAttribLocation(m_Program->GetProgramId(), 0, "a_position");
	glBindAttribLocation(m_Program->GetProgramId(), 1, "a_texCoord");
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
		 0.0f,  0.0f, 0.0f,
		 0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	GLfloat tCoords[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_Program->Use();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, tCoords);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}