#pragma once

namespace odlib
{
    namespace utils
    {
        namespace string
        {
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
        }
    }
}