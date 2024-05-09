#pragma once

#include "Quantum.h"

class ExampleLayer : public Quantum::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Quantum::TimeStep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Quantum::Event& e) override;
private:
	Quantum::ShaderLibrary m_ShaderLibrary;
	Quantum::Ref<Quantum::Shader> m_Shader;
	Quantum::Ref<Quantum::VertexArray> m_VertexArray;

	Quantum::Ref<Quantum::Shader> m_FlatColorShader;
	Quantum::Ref<Quantum::VertexArray> m_SquareVA;

	Quantum::Ref<Quantum::Texture2D> m_Texture, m_CheckBoardTexture;
	Quantum::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
