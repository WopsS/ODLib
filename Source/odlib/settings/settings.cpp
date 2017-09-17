#include <odlib/odlib.hpp>
#include <odlib/settings/settings.hpp>

std::map<std::wstring, std::any> odlib::settings::m_settings;

bool odlib::settings::exist(const std::wstring& key)
{
    return m_settings.find(key) != m_settings.end();
}

const void odlib::settings::remove(const std::wstring& key)
{
    if (exist(key) == true)
    {
        m_settings.erase(key);
    }
}