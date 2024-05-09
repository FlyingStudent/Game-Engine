#include"Sandbox2D.h"
#include<ImGui/imgui.h>

#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"Quantum/Debug/Instrumentor.h"

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"),m_CameraController(640.0f/480.0f), m_Color({ 0.2f, 0.3f, 0.8f, 1.0f })
{

}
void Sandbox2D::OnAttach()
{
	QT_PROFILE_FUNCTION();
	m_CheckBoardTexture = Quantum::Texture2D::Create("assets/textures/CheckBoard.png");
}

void Sandbox2D::OnDetach()
{
	QT_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Quantum::TimeStep ts)
{
	QT_PROFILE_FUNCTION();
	//update
	m_CameraController.OnUpdate(ts);
	//render
	Quantum::Renderer2D::ResetStats();
	{
		QT_PROFILE_SCOPE("Renderer Prep");
		Quantum::RenderCommand::SetClearColor({ 0.2f, 0.2f, 0.2f, 1.0f
			});

		Quantum::RenderCommand::Clear();
	}
	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		QT_PROFILE_SCOPE("Renderer Draw");
		Quantum::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Quantum::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Quantum::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Quantum::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_Color);
		Quantum::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckBoardTexture, 10.0f);
		Quantum::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckBoardTexture, 20.0f);
		Quantum::Renderer2D::EndScene();


		Quantum::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Quantum::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Quantum::Renderer2D::EndScene();
	}
}
void Sandbox2D::OnImGuiRender()
{
	QT_PROFILE_FUNCTION();
	
		//my ImGui windows
		ImGui::Begin("Settings");
		auto stats = Quantum::Renderer2D::GetStats();
		ImGui::Text("Renderer2D Stats: ");
		ImGui::Text("Draw Calls: %d", stats.DrawCalls);
		ImGui::Text("Quads: % d", stats.QuadCount);
		ImGui::Text("Vertices: % d", stats.GetTotalVertexCount());
		ImGui::Text("Indices: % d", stats.GetTotalIndexCount());
		ImGui::ColorEdit4("Quad Color", glm::value_ptr(m_Color));

		ImGui::End();
}

void Sandbox2D::OnEvent(Quantum::Event& event)
{
	m_CameraController.OnEvent(event);

}
