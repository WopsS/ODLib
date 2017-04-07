project("ODLib")
    kind("StaticLib")
    language("C++")
    pchheader("ODLib/ODLib.hpp")
    pchsource("ODLib/ODLib.cpp")
    targetdir(buildpath())

    filter({ "configurations:Debug" })
        symbols("On")

    filter({ "configurations:Release" })
        symbols("Off")

    filter({})

    includedirs({ "." })

    files({  "ODLib/**.cpp", "ODLib/**.hpp" })