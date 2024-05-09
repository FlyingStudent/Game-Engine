#include"qtpch.h"
#include"RenderCommand.h"
#include"Platform/OpenGL/OpenGLRendererAPI.h"
namespace Quantum
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
