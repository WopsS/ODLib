#include <odlib/odlib.hpp>
#include <odlib/utils/number.hpp>

const bool odlib::utils::number::is_float(const std::string& text)
{
    float number;

    std::istringstream stream(text);
    stream >> std::noskipws >> number;

    return stream.eof() && (stream.fail() == false);
}

const bool odlib::utils::number::is_float(const std::wstring& text)
{
    float number;

    std::wistringstream stream(text);
    stream >> std::noskipws >> number;

    return stream.eof() && (stream.fail() == false);
}

const bool odlib::utils::number::is_integer(const std::string& text)
{
    if (text.length() == 0)
    {
        return false;
    }

    for (size_t i = 0; i < text.length(); i++)
    {
        if (std::isdigit(text[i], std::locale()) == false)
        {
            return false;
        }
    }

    return true;
}

const bool odlib::utils::number::is_integer(const std::wstring& text)
{
    if (text.length() == 0)
    {
        return false;
    }

    for (size_t i = 0; i < text.length(); i++)
    {
        if (std::isdigit(text[i], std::locale()) == false)
        {
            return false;
        }
    }

    return true;
}
