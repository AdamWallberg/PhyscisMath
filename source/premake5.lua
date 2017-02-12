require 'settings'

--premake5.lua
 
solution (SOLUTION_NAME)
	configurations { "Debug", "Release" }
	
	platforms {
		"Win32",
		"Win64"
	}
	
	filter { "platforms:Win32" }
		system "Windows"
		architecture "x32"
		
	filter { "platforms:Win64" }
		system "Windows"
		architecture "x64"
		
	configuration { "Debug" }
		defines { "DEBUG" }
		flags { "Symbols" }
		
	configuration { "Release" }
		defines { "RELEASE", "NDEBUG" }
		optimize "On"
	 
project (PROJECT_NAME)
	kind "StaticLib"
	language "C++"
	
	objdir ("$(SolutionDir)../build/")
	
	files { "**.h", "**.cpp", "**.hpp" }
	
	targetdir "$(SolutionDir)../lib/"
	debugdir "$(SolutionDir)../lib/"
	targetname( PROJECT_NAME .. "_$(Configuration)" )
