#include <ODLib/ODLib.hpp>
#include <ODLib/Settings/Settings.hpp>

bool ODLib::Settings::Exist(const std::wstring& Key)
{
    return m_settings.find(Key) != m_settings.end();
}

const void ODLib::Settings::Remove(const std::wstring& Key)
{
    if (Exist(Key) == true)
    {
        m_settings.erase(Key);
    }
}

ODLIB_IMPLEMENT_SINGLETON_SOURCE(ODLib::Settings)