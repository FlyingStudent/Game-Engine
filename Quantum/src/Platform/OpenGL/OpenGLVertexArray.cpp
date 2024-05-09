#include"qtpch.h"
#include"OpenGLVertexArray.h"
#include"OpenGLErrorHandling.h"
#include"Quantum/Debug/Instrumentor.h"

#include<glad/glad.h>
namespace Quantum {
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Quantum::ShaderDataType::Float: return GL_FLOAT;
		case Quantum::ShaderDataType::Float2: return GL_FLOAT;
		case Quantum::ShaderDataType::Float3: return GL_FLOAT;
		case Quantum::ShaderDataType::Float4: return GL_FLOAT;
		case Quantum::ShaderDataType::Int: return GL_INT;
		case Quantum::ShaderDataType::Int2: return GL_INT;
		case Quantum::ShaderDataType::Int3: return GL_INT;
		case Quantum::ShaderDataType::Int4: return GL_INT;
		case Quantum::ShaderDataType::Mat3: return GL_FLOAT;
		case Quantum::ShaderDataType::Mat4: return GL_FLOAT;
		case Quantum::ShaderDataType::Bool: return GL_BOOL;
		}
		QT_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}
	OpenGLVertexArray::OpenGLVertexArray()
	{
		QT_PROFILE_FUNCTION();
		GLValidate(glCreateVertexArrays(1, &m_RendererID));
	}
	OpenGLVertexArray:: ~OpenGLVertexArray()
	{
		QT_PROFILE_FUNCTION();
		GLValidate(glDeleteVertexArrays(1,&m_RendererID));
	}
	void OpenGLVertexArray::Bind() const
	{
		QT_PROFILE_FUNCTION();
		GLValidate(glBindVertexArray(m_RendererID));
	}
	void OpenGLVertexArray::UnBind() const
	{
		QT_PROFILE_FUNCTION();
		GLValidate(glBindVertexArray(0));
	}
	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		QT_PROFILE_FUNCTION();
		QT_CORE_ASSERT(vertexBuffer->getLayout().GetElements().size(), "Vertex Buffer has no layout!");
		GLValidate(glBindVertexArray(m_RendererID));
		vertexBuffer->Bind();
		uint32_t index = 0;
		const auto& layout = vertexBuffer->getLayout();
		for (const auto& element : layout)
		{
			switch (element.Type)
			{
			case ShaderDataType::Float:
			case ShaderDataType::Float2:
			case ShaderDataType::Float3:
			case ShaderDataType::Float4:
			{
				GLValidate(glEnableVertexAttribArray(index));
				GLValidate(glVertexAttribPointer(index, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.Type), element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)element.Offset));
				index++;
				break;
			}
			case ShaderDataType::Int:
			case ShaderDataType::Int2:
			case ShaderDataType::Int3:
			case ShaderDataType::Int4:
			case ShaderDataType::Bool:
			{
				GLValidate(glEnableVertexAttribArray(index));
				GLValidate(glVertexAttribIPointer(index, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.Type), layout.GetStride(), (const void*)element.Offset));
				index++;
				break;
			}
			
			case ShaderDataType::Mat3:
			case ShaderDataType::Mat4:
				{
				uint8_t count = element.GetComponentCount();
				for (uint8_t i = 0; i < count; i++)
				{
					GLValidate(glEnableVertexAttribArray(index));
					GLValidate(glVertexAttribPointer(index, count, ShaderDataTypeToOpenGLBaseType(element.Type), element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)(element.Offset + sizeof(float) * count * i)));
					GLValidate(glVertexAttribDivisor(index, 1));
					index++;
				}
				break;
			}
			default:
				QT_CORE_ASSERT(false, "Unknown Shader Data Type!");	
			}
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}
	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		QT_PROFILE_FUNCTION();
		GLValidate(glBindVertexArray(m_RendererID));
		indexBuffer->Bind();
		
		m_IndexBuffers = indexBuffer;


	}
}