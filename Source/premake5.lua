project("ODLib")
    kind("StaticLib")
    language("C++")
    pchheader("ODLib.hpp")
    pchsource("ODLib.cpp")
    targetdir(buildpath())

    filter({ "configurations:Debug" })
        symbols("On")

    filter({ "configurations:Release" })
        symbols("Off")

    filter({})

    includedirs({ "." })

    files({  "**.cpp", "**.hpp" })