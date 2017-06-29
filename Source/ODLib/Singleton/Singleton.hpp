#pragma once

namespace ODLib
{
    /// <summary>
    /// Singleton template class.
    /// </summary>
    /// <typeparam name="T">The type of the singleton.</typeparam>
    template<typename T>
    class Singleton
    {
    public:

        /// <summary>
        /// Construct the class.
        /// </summary>
        /// <returns>The instance of the class.</returns>
        template<typename... Args>
        static T* Construct(Args&& ...args)
        {
            std::call_once(m_constructFlag, [&]()
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
                std::call_once(m_releaseFlag, [&]()
                {
                    delete m_instance;
                    m_instance = nullptr;
                });
            }
        }

    protected:

        Singleton() = default;
        virtual ~Singleton() = default;

    private:

        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;

        static T* m_instance;

        static std::once_flag m_constructFlag;

        static std::once_flag m_releaseFlag;
    };

    template<typename T>
    T* Singleton<T>::m_instance = nullptr;

    template<typename T>
    std::once_flag Singleton<T>::m_constructFlag;

    template<typename T>
    std::once_flag Singleton<T>::m_releaseFlag;
}