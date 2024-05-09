#include"qtpch.h"
#include"OpenGLRendererAPI.h"
#include"OpenGLErrorHandling.h"
#include"Quantum/Debug/Instrumentor.h"
#include<glad/glad.h>
namespace Quantum {
	void OpenGLRendererAPI::Init()
	{
		QT_PROFILE_FUNCTION();
		GLValidate(glEnable(GL_BLEND));
		GLValidate(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		GLValidate(glEnable(GL_DEPTH_TEST));
	}
	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		GLValidate(glViewport(x, y, width, height));
	}
	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		GLValidate(glClearColor(color.r, color.g, color.b, color.a));
	}
	void OpenGLRendererAPI::Clear()
	{
		GLValidate(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	}
	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount)
	{
		vertexArray->Bind();
		uint32_t count = indexCount ? indexCount: vertexArray->GetIndexBuffer()->GetCount();
		GLValidate(glDrawElements(GL_TRIANGLES,count, GL_UNSIGNED_INT, nullptr));
	}
}
