#pragma once

namespace odlib
{
    namespace utils
    {
        namespace number
        {
            template<typename T>
            const bool is_double(const std::basic_string<T>& text)
            {
                double number;

                std::basic_istringstream<T> stream(text);
                stream >> std::noskipws >> number;

                return stream.eof() && (stream.fail() == false);
            }

            template<typename T>
            const bool is_long_double(const std::basic_string<T>& text)
            {
                long double number;

                std::basic_istringstream<T> stream(text);
                stream >> std::noskipws >> number;

                return stream.eof() && (stream.fail() == false);
            }

            template<typename T>
            const bool is_float(const std::basic_string<T>& text)
            {
                float number;

                std::basic_istringstream<T> stream(text);
                stream >> std::noskipws >> number;

                return stream.eof() && (stream.fail() == false);
            }

            template<typename T>
            const bool is_integer(const std::basic_string<T>& text, const std::locale& locale = std::locale())
            {
                if (text.length() == 0)
                {
                    return false;
                }

                for (size_t i = 0; i < text.length(); i++)
                {
                    if (std::isdigit(text[i], locale) == false)
                    {
                        return false;
                    }
                }

                return true;
            }

            template<typename T, typename Elem>
            const bool is_valid(const std::basic_string<Elem>& text)
            {
                // The stream will insert just one character for char types, prevent this by trying to convert it to short.
                if constexpr (std::is_same_v<T, char> || std::is_same_v<T, int8_t> || std::is_same_v<T, unsigned char> || std::is_same_v<T, uint8_t>)
                {
                    return is_valid<int16_t>(text);
                }
                else
                {
                    T value;

                    std::basic_istringstream<Elem> stream(text);
                    stream >> value;

                    return stream.eof() && (stream.fail() == false);
                }
            }
        }
    }
}