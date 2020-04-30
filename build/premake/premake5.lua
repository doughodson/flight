--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Target of interest:
--     vs2017     (Visual Studio 2017)
--     vs2019     (Visual Studio 2019)
--

-- we must have an ide/compiler specified
if (_ACTION == nil) then
  return
end

LibWindows = {"Ws2_32", "Winmm", "comctl32", "gdi32", "iphlpapi"}

workspace "flightgear_examples"

   -- destination directory for generated solution/project files
   location ("../" .. _ACTION)

   -- create console application by default
   kind "ConsoleApp"

   -- C++ code in all projects
   language "C++"

   --
   -- Build (solution) configuration options:
   --     Release        (Application linked to Multi-threaded DLL)
   --     Debug          (Application linked to Multi-threaded Debug DLL)
   --
   configurations { "Release", "Debug" }

   -- visual studio options and warnings
   -- /wd4351 (C4351 warning) - disable warning associated with array brace initialization
   -- /wd4996 (C4996 warning) - disable deprecated declarations
   -- /wd4005 (C4005 warning) - disable macro redefinition
   -- /wd4100 (C4100 warning) - disable unreferenced formal parameter
   -- /Oi - generate intrinsic functions
   disablewarnings { "4351",  "4996", "4005", "4100" }
   buildoptions { "/Oi" }

   -- common release configuration flags, symbols and libraries
   filter { "configurations:Release" }
      optimize "On"
      -- favor speed over size
      buildoptions { "/Ot" }
      defines { "WIN32", "NDEBUG" }

   -- common debug configuration flags, symbols and libraries
   filter { "configurations:Debug" }
      symbols "On"
      --targetsuffix "_d"
      defines { "WIN32", "_DEBUG" }

-- external flight dynamics model (sending UDP packets)
project "net_fdm"
   targetname "net_fdm"
   targetdir "../../net_fdm"
   debugdir "../../net_fdm"
   files {
      "../../net_fdm/**.h*",
      "../../net_fdm/**.cpp"
   }
   defines { "_CONSOLE" }
   filter "configurations:Release"
      links {LibWindows}
   filter "configurations:Debug"
      links {LibWindows}
