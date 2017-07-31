#pragma once

namespace odlib
{
    /// <summary>
    /// A class that can contains settings for the application.
    /// </summary>
    class settings
    {
    public:

        /// <summary>
        /// Add a setting.
        /// </summary>
        /// <param name="key">Key of the setting.</param>
        /// <param name="value">Value of the setting.</param>
        /// <typeparam name="T">The type of the value.</typeparam>
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

        /// <summary>
        /// Check if the setting exists.
        /// </summary>
        /// <param name="key">Key of the setting.</param>
        /// <returns>True if the key exists, false otherwise.</returns>
        bool exist(const std::wstring& key);

        /// <summary>
        /// Get the value of a setting.
        /// </summary>
        /// <param name="key">Key of the setting.</param>
        /// <typeparam name="T">The desire type of the setting.</typeparam>
        /// <returns>The value of the setting.</returns>
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

        /// <summary>
        /// Remove a setting.
        /// </summary>
        /// <param name="key">Key of the setting.</param>
        const void remove(const std::wstring& key);

        /// <summary>
        /// Set the value of a setting.
        /// </summary>
        /// <param name="key">Key of the setting.</param>
        /// <param name="value">Value of the setting.</param>
        /// <typeparam name="T">The type of the setting.</typeparam>
        /// <remarks>If a setting doesn't exists it will be added.</remarks>  
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