#include<qtpch.h>
#include"ContentBrowserPanel.h"
#include<ImGui/imgui.h>
namespace Quantum {
	//Once we have projects, change this
	constexpr char* s_AssetsDirectory = "assets";
	void Quantum::ContentBrowserPanel::OnImGuiRender()
	{
		ImGui::Begin("Content Browser");


		for (auto& p : std::filesystem::directory_iterator(s_AssetsDirectory))
		{
			std::string path = p.path().string();
				if (p.is_directory())
				{
					if (ImGui::Button(path.c_str()))
					{

					}
				}

		}

		ImGui::End();
	}
}
