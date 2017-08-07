#pragma once

namespace odlib
{
    namespace utils
    {
        namespace number
        {
            const bool is_float(const std::string& text);

            const bool is_float(const std::wstring& text);

            const bool is_integer(const std::string& text);

            const bool is_integer(const std::wstring& text);
        }
    }
}