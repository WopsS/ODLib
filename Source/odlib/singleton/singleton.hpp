#pragma once

namespace odlib
{
    /// <summary>
    /// Singleton template class.
    /// </summary>
    /// <typeparam name="T">The type of the singleton.</typeparam>
    template<typename T>
    class singleton
    {
    public:

        /// <summary>
        /// Construct the class.
        /// </summary>
        /// <returns>The instance of the class.</returns>
        template<typename... Args>
        static T* construct(Args&& ...args)
        {
            std::call_once(m_construct_flag, [&]()
            {
                m_instance = new T(std::forward<Args>(args)...);
                std::atexit(release);
            });

            return m_instance;
        }

        /// <summary>
        /// Get the instance of the singleton, construct it if needed.
        /// </summary>
        /// <returns>The instance of the class.</returns>
        static T* get_instance()
        {
            if (is_released() == true)
            {
                return construct();
            }

            return m_instance;
        }

        /// <summary>
        /// Check if the singleton is released.
        /// </summary>
        /// <returns>true if it is released, false otherwise.</returns>
        static const bool is_released()
        {
            return m_instance == nullptr;
        }

        /// <summary>
        /// Release the singleton.
        /// </summary>
        static void release()
        {
            if (is_released() == false)
            {
                std::call_once(m_release_flag, [&]()
                {
                    delete m_instance;
                    m_instance = nullptr;
                });
            }
        }

#ifdef ODLIB_SINGLETON_USE_CAMELCASE
        /// <summary>
        /// Construct the class.
        /// </summary>
        /// <returns>The instance of the class.</returns>
        template<typename... Args>
        static T* Construct(Args&& ...args)
        {
            std::call_once(m_construct_flag, [&]()
            {
                m_instance = new T(std::forward<Args>(args)...);
                std::atexit(Release);
            });

            return m_instance;
        }

        /// <summary>
        /// Get the instance of the singleton, construct it if needed.
        /// </summary>
        /// <returns>The instance of the class.</returns>
        static T* GetInstance()
        {
            if (IsReleased() == true)
            {
                return Construct();
            }

            return m_instance;
        }

        /// <summary>
        /// Check if the singleton is released.
        /// </summary>
        /// <returns>true if it is released, false otherwise.</returns>
        static const bool IsReleased()
        {
            return m_instance == nullptr;
        }

        /// <summary>
        /// Release the singleton.
        /// </summary>
        static void Release()
        {
            if (IsReleased() == false)
            {
                std::call_once(m_release_flag, [&]()
                {
                    delete m_instance;
                    m_instance = nullptr;
                });
            }
        }
#endif

    protected:

        singleton() = default;
        virtual ~singleton() = default;

    private:

        singleton(const singleton&) = delete;
        singleton(singleton&&) = delete;
        singleton& operator=(const singleton&) = delete;
        singleton& operator=(singleton&&) = delete;

        static T* m_instance;

        static std::once_flag m_construct_flag;

        static std::once_flag m_release_flag;
    };

    template<typename T>
    T* singleton<T>::m_instance = nullptr;

    template<typename T>
    std::once_flag singleton<T>::m_construct_flag;

    template<typename T>
    std::once_flag singleton<T>::m_release_flag;
}