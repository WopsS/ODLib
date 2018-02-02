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

    includedirs({ ".", "./utfcpp/source" })

    files({  "odlib/**.cpp", "odlib/**.hpp" })