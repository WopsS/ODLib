#include <odlib/odlib.hpp>
#include <odlib/utils/string.hpp>

std::vector<std::string> odlib::utils::string::split(const std::string& text, const char delimiter)
{
    std::vector<std::string> result;
    std::stringstream stream(text);
    std::string string;

    while (std::getline(stream, string, delimiter))
    {
        result.push_back(std::move(string));
    }

    return result;
}

std::vector<std::wstring> odlib::utils::string::split(const std::wstring& text, const wchar_t delimiter)
{
    std::vector<std::wstring> result;
    std::wstringstream stream(text);
    std::wstring string;

    while (std::getline(stream, string, delimiter))
    {
        result.push_back(std::move(string));
    }

    return result;
}
