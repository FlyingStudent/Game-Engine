#pragma once
#include<Quantum.h>
#include"Panels/SceneHierarchyPanel.h"
#include"Panels/ContentBrowserPanel.h"
#include"Quantum/Renderer/EditorCamera.h"
namespace Quantum {
	class EditorLayer : public Layer {
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;
		virtual void OnAttach() override;
		virtual void OnDetach()	override;
		void OnUpdate(TimeStep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& event) override;
	private:
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();
		void SaveScene();
	private:
		OrthographicCameraController m_CameraController;

		//TEMP
		Ref<Shader> m_FlatColorShader;
		Ref<VertexArray> m_VertexArray;
		Ref<Framebuffer> m_Framebuffer;


		Ref<Scene> m_ActiveScene;
		Entity m_SquareEntity;
		Entity m_CameraEntity;	
		Entity m_SceneCamera;

		Entity m_HoveredEntity;
		bool m_PrimaryCamera = false;
		EditorCamera m_EditorCamera;
		Ref<Texture2D> m_CheckBoardTexture;


		bool m_ViewportFocused = false;
		bool m_ViewportHovered = false;
		glm::vec2 m_ViewportSize = glm::vec2(0.0f);
		glm::vec2 m_ViewportBounds[2];


		std::string  m_FilePath;

		glm::vec4 m_Color = { 0.2f,0.3f,0.8f,1.0f };

		int m_GizmoType = -1;

		//panels
		SceneHierarchyPanel m_SceneHierarchyPanel;

	};
}
