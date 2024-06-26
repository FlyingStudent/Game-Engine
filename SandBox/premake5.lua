project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Quantum/vendor/spdlog/include",
		"%{wks.location}/Quantum/src",
		"%{wks.location}/Quantum/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Quantum"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "QT_DEBUG"
		runtime "Debug"
		symbols "on"

		-- postbuildcommands
		-- {
		-- 	"{COPYDIR} \"%{LibraryDir.VulkanSDK_DebugDLL}\" \"%{cfg.targetdir}\""
		-- }
	filter "configurations:Release"
		defines "QT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QT_DIST"
		runtime "Release"
		optimize "on"
