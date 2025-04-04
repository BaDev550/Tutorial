workspace "Tutorial"
    architecture "x64"
    startproject "Tutorial"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] =  "Engine/vendor/GLFW/include"

group "Dependencies"
    include "Engine/vendor/GLFW"
group ""

project "Engine"
    location "Engine"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    defines 
    {
        "_CRT_SECURE_NO_WARNINGS"
    }
    
    includedirs 
    {
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"
        buildoptions "/utf-8"

        defines 
        {
            "E_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }
        
    filter "configurations:Debug"
        defines "E_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "E_RELEASE"
        runtime "Release"
        optimize "on"