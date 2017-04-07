#include <ODLib/ODLib.hpp>

const uint32_t ODLib::Version::Id()
{
    return 100;
}

const std::string ODLib::Version::String()
{
    return "0.1.0";
}

const std::wstring ODLib::Version::WString()
{
    return L"0.1.0";
}