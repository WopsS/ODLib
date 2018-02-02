#pragma once

namespace odlib
{
    namespace utils
    {
        namespace string
        {
            template<typename T>
            std::basic_string<T> to_lower(std::basic_string<T> text, const std::locale& locale = std::locale())
            {
                std::transform(text.begin(), text.end(), text.begin(), [&locale](T character)
                {
                    return std::tolower(character, locale);
                });

                return text;
            }

            template<typename T>
            std::basic_string<T> to_upper(std::basic_string<T> text, const std::locale& locale = std::locale())
            {
                std::transform(text.begin(), text.end(), text.begin(), [&locale](T character)
                {
                    return std::toupper(character, locale);
                });

                return text;
            }

            template<typename T>
            std::vector<std::basic_string<T>> split(const std::basic_string<T>& text, const T delimiter)
            {
                std::vector<std::basic_string<T>> result;
                std::basic_stringstream<T> stream(text);
                std::basic_string<T> string;

                while (std::getline(stream, string, delimiter))
                {
                    result.push_back(std::move(string));
                }

                return result;
            }

            template<typename T>
            std::basic_string<T> ltrim(std::basic_string<T> text, const std::locale& locale = std::locale())
            {
                text.erase(text.begin(), std::find_if(text.begin(), text.end(), [&locale](T character)
                {
                    return !std::isspace<T>(character, locale);
                }));

                return text;
            }

            template<typename T>
            std::basic_string<T> rtrim(std::basic_string<T> text, const std::locale& locale = std::locale())
            {
                text.erase(std::find_if(text.rbegin(), text.rend(), [&locale](T character)
                {
                    return !std::isspace<T>(character, locale);
                }).base(), text.end());

                return text;
            }

            template<typename T>
            std::basic_string<T> trim(std::basic_string<T> text, const std::locale& locale = std::locale())
            {
                return ltrim(rtrim(text, locale));
            }

            std::u16string utf8_to_16(const std::string& text);

            std::u16string utf8_to_16(const std::string_view text);

            std::u32string utf8_to_32(const std::string& text);

            std::u32string utf8_to_32(const std::string_view text);

            std::wstring utf8_to_wide(const std::string& text);

            std::wstring utf8_to_wide(const std::string_view text);

            std::string utf16_to_8(const std::u16string& text);

            std::string utf16_to_8(const std::u16string_view text);

            std::string utf32_to_8(const std::u32string& text);

            std::string utf32_to_8(const std::u32string_view text);

            std::string wide_to_utf8(const std::wstring& text);

            std::string wide_to_utf8(const std::wstring_view text);
        }
    }
}