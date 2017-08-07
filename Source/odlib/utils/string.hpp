#pragma once

namespace odlib
{
    namespace utils
    {
        namespace string
        {
            std::vector<std::string> split(const std::string& text, const char delimiter);

            std::vector<std::wstring> split(const std::wstring& text, const wchar_t delimiter);
        }
    }
}