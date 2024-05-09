	#include <Quantum.h>
#include <Quantum/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Quantum::Application
{
public:
	Sandbox(Quantum::ApplicationCommandLineArgs args)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Quantum::Application* Quantum::CreateApplication(Quantum::ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}
