#include <odlib/odlib.hpp>
#include <odlib/utils/string.hpp>

std::u16string odlib::utils::string::utf8_to_16(const std::string& text)
{
    std::u16string result;
    utf8::utf8to16(text.begin(), text.end(), std::back_inserter(result));

    return result;
}

std::u16string odlib::utils::string::utf8_to_16(const std::string_view text)
{
    return utf8_to_16(std::string(text));
}

std::u32string odlib::utils::string::utf8_to_32(const std::string& text)
{
    std::u32string result;
    utf8::utf8to32(text.begin(), text.end(), std::back_inserter(result));

    return result;
}

std::u32string odlib::utils::string::utf8_to_32(const std::string_view text)
{
    return utf8_to_32(std::string(text));
}

std::wstring odlib::utils::string::utf8_to_wide(const std::string& text)
{
    std::wstring result;

    if constexpr (sizeof(wchar_t) == sizeof(char16_t))
    {
        utf8::utf8to16(text.begin(), text.end(), std::back_inserter(result));
    }
    else
    {
        utf8::utf8to32(text.begin(), text.end(), std::back_inserter(result));
    }

    return result;
}

std::wstring odlib::utils::string::utf8_to_wide(const std::string_view text)
{
    return utf8_to_wide(std::string(text));
}

std::string odlib::utils::string::utf16_to_8(const std::u16string& text)
{
    std::string result;
    utf8::utf16to8(text.begin(), text.end(), std::back_inserter(result));

    return result;
}

std::string odlib::utils::string::utf16_to_8(const std::u16string_view text)
{
    return utf16_to_8(std::u16string(text));
}

std::string odlib::utils::string::utf32_to_8(const std::u32string& text)
{
    std::string result;
    utf8::utf32to8(text.begin(), text.end(), std::back_inserter(result));

    return result;
}

std::string odlib::utils::string::utf32_to_8(const std::u32string_view text)
{
    return utf32_to_8(std::u32string(text));
}

std::string odlib::utils::string::wide_to_utf8(const std::wstring& text)
{
    std::string result;

    if constexpr (sizeof(wchar_t) == sizeof(char16_t))
    {
        utf8::utf16to8(text.begin(), text.end(), std::back_inserter(result));
    }
    else
    {
        utf8::utf32to8(text.begin(), text.end(), std::back_inserter(result));
    }

    return result;
}

std::string odlib::utils::string::wide_to_utf8(const std::wstring_view text)
{
    return wide_to_utf8(std::wstring(text));
}
