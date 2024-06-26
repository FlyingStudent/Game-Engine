#pragma once
#include"Quantum/Renderer/Buffer.h"
namespace Quantum {
	class OpenGLVertexBuffer :public VertexBuffer {
	public:
		OpenGLVertexBuffer(uint32_t size);
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void SetData(void* data, uint32_t size) override;

		virtual const BufferLayout& getLayout() const override {
			return m_Layout;
		}
		virtual void SetLayout(const BufferLayout& layout) override {
			m_Layout = layout;
		}

		static Ref<VertexBuffer> Create(float* vertices, uint32_t size) ;	 
	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	};
	class OpenGLIndexBuffer :public IndexBuffer {
	public:
		OpenGLIndexBuffer(uint32_t* indecies, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		static Ref<IndexBuffer> Create(uint32_t* indecies,uint32_t count) ;
		virtual uint32_t GetCount() const {
			return m_Count;
		};
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;

	};
}
