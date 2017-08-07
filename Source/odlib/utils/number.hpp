#pragma once

namespace odlib
{
    namespace utils
    {
        namespace number
        {
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
        }
    }
}