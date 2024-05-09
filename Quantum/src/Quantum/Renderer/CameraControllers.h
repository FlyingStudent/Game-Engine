#pragma once

#include"Quantum/Renderer/OrthographicCamera.h"
#include"Quantum/Core/TimeStep.h"

#include"Quantum/Events/ApplicationEvent.h"
#include"Quantum/Events/MouseEvent.h"

namespace Quantum
{

	struct OrthographicCameraBounds {
		float Left, Right;
		float Bottom, Top;
		float GetWidth() const { return Right - Left; }
		float GetHeight() const { return Top - Bottom; }
	};

	class OrthographicCameraController

	{
	public:
		OrthographicCameraController(float aspectRation, bool rotation = false);

		void OnUpdate(TimeStep ts);
		void OnEvent(Event& e);
		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float level) { m_ZoomLevel = level; CalculateView(); }

		const OrthographicCameraBounds& GetBounds() const { return m_Bounds; }
		void OnResize(float width,float height);


	private:
		void CalculateView();

		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRation;
		float m_ZoomLevel = 1.0f;
		OrthographicCameraBounds m_Bounds;
		OrthographicCamera m_Camera;

		bool m_Rotation;
		glm::vec3 m_CameraPosition = { 0.0f,0.0f,0.0f };
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
	};
}