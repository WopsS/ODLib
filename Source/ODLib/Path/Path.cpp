#include <ODLib/ODLib.hpp>
#include <ODLib/Path/Path.hpp>

const std::wstring ODLib::Path::Combine(const std::wstring& Path1, const std::wstring& Path2)
{
    return Combine({ Path1, Path2 });
}

const std::wstring ODLib::Path::Combine(const std::wstring& Path1, const std::wstring& Path2, const std::wstring& Path3)
{
    return Combine({ Path1, Path2, Path3 });
}

const std::wstring ODLib::Path::Combine(const std::wstring& Path1, const std::wstring& Path2, const std::wstring& Path3, const std::wstring& Path4)
{
    return Combine({ Path1, Path2, Path3, Path4 });
}

const std::wstring ODLib::Path::Combine(const std::initializer_list<std::wstring> Paths)
{
    std::wostringstream Result;

#ifdef _WIN64
    wchar_t Delimiter[] = L"\\";
#else
    wchar_t Delimiter[] = L"//";
#endif

    // Append all elements except the last one, we will add it later because we don't want the trailing delimiter at the end of the path.
    std::copy(Paths.begin(), Paths.end() - 1, std::ostream_iterator<std::wstring, wchar_t>(Result, Delimiter));

    // Append the last element.
    Result << *std::rbegin(Paths);

    return Result.str();
}