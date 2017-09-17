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
                m_settings.emplace(key, value);
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
            if (exist(key) == true)
            {
                try
                {
                    return std::any_cast<T>(m_settings.at(key));
                }
                catch (const std::bad_any_cast&)
                {
#ifdef _DEBUG
                    LOG_ERROR << L"Bad cast for the setting with key " << std::quoted(key);
#endif
                }
            }

            return T();
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
                m_settings.at(key) = value;
            }
            else
            {
                add(key, value);
            }
        }

    private:

        settings() = default;
        ~settings() = default;

        std::map<std::wstring, std::any> m_settings;

        ODLIB_SINGLETON_IMPLEMENT_HEADER(settings)
    };
}