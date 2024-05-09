include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Quantum"
	architecture "x86_64"
	startproject "Atom"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}
	defines{
		"QT_PLATFORM_WINDOWS"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Quantum/vendor/GLFW"
	include "Quantum/vendor/Glad"
	include "Quantum/vendor/imgui"
	include "Quantum/vendor/yaml-cpp"
group ""

include "Quantum"
include "Sandbox"
include "Atom"
