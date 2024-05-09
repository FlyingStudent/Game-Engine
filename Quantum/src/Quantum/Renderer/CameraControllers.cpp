#include<qtpch.h>
#include"CameraControllers.h"
#include"Quantum/Core/Input.h"
#include"Quantum/Core/KeyCodes.h"
#include"Quantum/Debug/Instrumentor.h"
namespace Quantum {
	OrthographicCameraController::OrthographicCameraController(float aspectRation, bool rotation)
		:m_AspectRation(aspectRation), m_Bounds({ -m_AspectRation * m_ZoomLevel, m_AspectRation * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel }), m_Rotation(rotation), m_Camera(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top)
	{
		
	}
	void OrthographicCameraController::OnUpdate(TimeStep ts)
	{
		QT_PROFILE_FUNCTION();

		if (Input::IsKeyPressed(Key::A))
		{
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
		}
		else if (Input::IsKeyPressed(Key::D))
		{
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;
		}
		if (Input::IsKeyPressed(Key::W))
		{
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;
		}
		else if (Input::IsKeyPressed(Key::S))
		{
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;
		}
		if (m_Rotation)
		{
			if (Input::IsKeyPressed(Key::Q))
			{
				m_CameraRotation += m_CameraRotationSpeed * ts;

			}
			else if (Input::IsKeyPressed(Key::E))
			{
				m_CameraRotation -= m_CameraRotationSpeed * ts;
			}
			m_Camera.SetRotation(m_CameraRotation);
		}
		m_Camera.SetPosition(m_CameraPosition);
		m_CameraTranslationSpeed = m_ZoomLevel;
	}
	void OrthographicCameraController::OnEvent(Event& e)
	{
		QT_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(QT_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(QT_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}
	void OrthographicCameraController::CalculateView()
	{

		m_Bounds = { -m_AspectRation * m_ZoomLevel ,m_AspectRation * m_ZoomLevel ,-m_ZoomLevel,m_ZoomLevel };
		m_Camera.SetProjection(-m_AspectRation * m_ZoomLevel, m_AspectRation * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}
	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		QT_PROFILE_FUNCTION();
		m_ZoomLevel -= e.GetYOffset() *0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		CalculateView();
		return false;
	}
	void OrthographicCameraController::OnResize(float width, float height)
	{
		m_AspectRation = width / height;
		m_Camera.SetProjection(-m_AspectRation * m_ZoomLevel, m_AspectRation * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
	}
	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		QT_PROFILE_FUNCTION();
		
		OnResize((float)e.GetWidth(), (float)e.GetHeight());

		return false;
	}
}
