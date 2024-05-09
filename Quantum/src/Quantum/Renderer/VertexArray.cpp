#include"qtpch.h"
#include"VertexArray.h"
#include"Renderer.h"
#include"Quantum/Renderer/RendererAPI.h"
#include"Platform/OpenGL/OpenGLVertexArray.h"
namespace Quantum {
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{

		case RendererAPI::API::None: QT_CORE_ASSERT(false, "Renderer API None is currently not supported!");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}
		QT_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
		}
	}
