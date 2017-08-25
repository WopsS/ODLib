require("premake", ">=5.0.0-alpha12")
include("version.lua")

basepath = path.getdirectory(os.getcwd());
buildpath = function() return path.join(basepath, "Build", "%{cfg.buildcfg}", "%{cfg.architecture}").."/" end
sourcepath = function() return path.join(basepath, "Source").."/" end

Version:format("../Source/odlib/version.hpp.in")

newoption {
    trigger     = "architecture",
    value       = "VALUE",
    description = "Choose the architecture",
    default     = "x86_64",
    allowed = {
        { "x86",    "32-bit architecture" },
        { "x86_64", "64-bit architecture" }
   }
}

workspace("ODLib")
    characterset("Unicode")
    configurations({ "Debug", "Release" })
    cppdialect("C++17")
    defines({ "_CRT_SECURE_NO_WARNINGS" })
    location("Project")

    filter({ "configurations:Debug" })
        symbols("On")

    filter({ "configurations:Release" })
        optimize("On")
        symbols("Off")

    filter({ "options:architecture=x86" })
        architecture("x86")

    filter({ "options:architecture=x86_64" })
        architecture("x86_64")

    filter({})

    include(sourcepath())