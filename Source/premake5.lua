project("ODLib")
    kind("StaticLib")
    language("C++")
    pchheader("odlib/odlib.hpp")
    pchsource("odlib/odlib.cpp")
    targetdir(buildpath())

    filter({ "configurations:Debug" })
        symbols("On")

    filter({ "configurations:Release" })
        symbols("Off")

    filter({})

    includedirs({ "." })

    files({  "odlib/**.cpp", "odlib/**.hpp" })