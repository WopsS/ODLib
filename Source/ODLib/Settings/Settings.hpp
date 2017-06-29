#pragma once

namespace ODLib
{
    class Settings
    {
    public:

        template<typename T>
        void Add(const std::wstring& Key, const T Value)
        {
            if (Exist(Key) == false)
            {
                std::wostringstream Result;
                Result << Value;

                m_settings.emplace(Key, Result.str());
            }
            else
            {
                Set(Key, Value);
            }
        }

        bool Exist(const std::wstring& Key);

        template<typename T>
        const T Get(const std::wstring& Key)
        {
            T Result;

            if (Exist(Key) == true)
            {
                std::wstringstream Stream;
                wchar_t Temp;

                Stream << m_settings.at(Key);
                Stream >> Result;

                // If we still have something in the stream it may be a string, so we need all of its content.
                while (Stream >> std::noskipws >> Temp)
                {
                    Result += Temp;
                }
            }

            return Result;
        }

        const void Remove(const std::wstring& Key);

        template<typename T>
        void Set(const std::wstring& Key, const T Value)
        {
            if (Exist(Key) == true)
            {
                std::wstringstream Result;

                Result << Value;
                Result >> m_settings.at(Key);
            }
            else
            {
                Add(Key, Value);
            }
        }

    private:

        Settings() = default;
        ~Settings() = default;

        std::map<std::wstring, std::wstring> m_settings;

        ODLIB_IMPLEMENT_SINGLETON_HEADER(Settings)
    };
}