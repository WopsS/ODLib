#pragma once

namespace odlib
{
    class settings
    {
    public:

        template<typename T>
        void add(const std::wstring& key, const T value)
        {
            if (exist(key) == false)
            {
                std::wostringstream result;
                result << value;

                m_settings.emplace(key, result.str());
            }
            else
            {
                set(key, value);
            }
        }

        bool exist(const std::wstring& key);

        template<typename T>
        const T get(const std::wstring& key)
        {
            T result;

            if (exist(key) == true)
            {
                std::wstringstream stream;
                wchar_t temp;

                stream << m_settings.at(key);
                stream >> result;

                // If we still have something in the stream it may be a string, so we need all of its content.
                while (stream >> std::noskipws >> temp)
                {
                    result += temp;
                }
            }

            return result;
        }

        const void remove(const std::wstring& key);

        template<typename T>
        void set(const std::wstring& key, const T value)
        {
            if (exist(key) == true)
            {
                std::wstringstream result;

                result << value;
                result >> m_settings.at(key);
            }
            else
            {
                add(key, value);
            }
        }

    private:

        settings() = default;
        ~settings() = default;

        std::map<std::wstring, std::wstring> m_settings;

        ODLIB_SINGLETON_IMPLEMENT_HEADER(settings)
    };
}