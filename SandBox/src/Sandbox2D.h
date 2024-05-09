#pragma once
#include<Quantum.h>
class Sandbox2D : public Quantum::Layer{
public: 
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach()	override;

	 void OnUpdate(Quantum::TimeStep ts) override;
	 virtual void OnImGuiRender() override;
	void OnEvent(Quantum::Event& event) override;
private:
	Quantum::OrthographicCameraController m_CameraController;

	//TEMP
	Quantum::Ref<Quantum::Shader> m_FlatColorShader;
	Quantum::Ref<Quantum::VertexArray> m_VertexArray;
	Quantum::Ref<Quantum::Texture2D> m_CheckBoardTexture;
	
	glm::vec4 m_Color = { 0.2f,0.3f,0.8f,1.0f };

};
