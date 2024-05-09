#pragma once
#include <glm.hpp>
#include "Quantum/Core/KeyCodes.h"
#include "Quantum/Core/MouseButtonsCode.h"
namespace Quantum {
	class  Input {
	public :
			static bool IsKeyPressed(KeyCode keycode);
		static bool IsMouseButtonPressed(MouseCode button);
			static float  GetMouseY();
			static float GetMouseX();
		static std::pair<float, float> GetMousePosition();
	};
}
