#include"qtpch.h"
#include<GLFW/glfw3.h> 
#include"Quantum/Core/Input.h"
#include"Quantum/Core/Application.h"
namespace Quantum {
	bool Input::IsKeyPressed(const KeyCode keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
			int state = glfwGetKey(window, keycode);
			return( state== GLFW_PRESS || state == GLFW_REPEAT);
	}

	bool Input::IsMouseButtonPressed(const MouseCode button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, button);
		return (state == GLFW_PRESS);

	}

float Input::GetMouseX()
	{
	auto [x, y] = GetMousePosition();
	return (float)x;
	}
	float Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return (float)y;
	}

	std::pair<float, float> Input::GetMousePosition() 
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos,(float)ypos };
	}

}
