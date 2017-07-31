#include <odlib/odlib.hpp>
#include <odlib/path/path.hpp>

const std::wstring odlib::path::combine(const std::wstring& path1, const std::wstring& path2)
{
    return combine({ path1, path2 });
}

const std::wstring odlib::path::combine(const std::wstring& path1, const std::wstring& path2, const std::wstring& path3)
{
    return combine({ path1, path2, path3 });
}

const std::wstring odlib::path::combine(const std::wstring& path1, const std::wstring& path2, const std::wstring& path3, const std::wstring& path4)
{
    return combine({ path1, path2, path3, path4 });
}

const std::wstring odlib::path::combine(const std::initializer_list<std::wstring> paths)
{
    std::wostringstream result;

#ifdef _WIN64
    wchar_t delimiter[] = L"\\";
#else
    wchar_t delimiter[] = L"//";
#endif

    // Append all elements except the last one, we will add it later because we don't want the trailing delimiter at the end of the path.
    std::copy(paths.begin(), paths.end() - 1, std::ostream_iterator<std::wstring, wchar_t>(result, delimiter));

    // Append the last element.
    result << *std::rbegin(paths);

    return result.str();
}