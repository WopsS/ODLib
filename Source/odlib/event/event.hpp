#pragma once

namespace odlib
{
    /// <summary>
    /// A class that can act as an event.
    /// </summary>
    /// <typeparam name="T">The type of the function for the event.</typeparam>
    template<typename T>
    class event
    {
    public:

        event() = default;
        ~event() = default;

        /// <summary>
        /// Notify the subscribers.
        /// </summary>
        /// <typeparam name="Args">The arguments for the function of the event.</typeparam>
        template<typename... Args>
        void notify(Args&& ...args)
        {
            for (auto& subscriber : m_subscribers)
            {
                subscriber.second(std::forward<Args>(args)...);
            }
        }

        /// <summary>
        /// Subscribe a function to the event.
        /// </summary>
        /// <param name="key">Key of the subscriber.</param>
        /// <param name="function">Function to call when the subscribers are notify.</param>
        void subscribe(const std::wstring& key, const std::function<T> function)
        {
            auto subscriber = m_subscribers.find(key);

            if (subscriber == m_subscribers.end())
            {
                m_subscribers.emplace(key, function);

#ifdef _DEBUG
                LOG_DEBUG << L"A subscriber with key " << std::quoted(key) << L" was added";
#endif
            }
            else
            {
                LOG_WARNING << L"A subscriber with key " << std::quoted(key) << L" already exists";
            }
        }

        /// <summary>
        /// Unsubscribe a function to the event.
        /// </summary>
        /// <param name="key">Key of the subscriber.</param>
        void unsubscribe(const std::wstring& key)
        {
            auto subscriber = m_subscribers.find(key);

            if (subscriber != m_subscribers.end())
            {
                m_subscribers.erase(subscriber);

#ifdef _DEBUG
                LOG_DEBUG << L"A subscriber with key " << std::quoted(key) << L" was removed";
#endif
            }
            else
            {
                LOG_WARNING << L"A subscriber with key " << std::quoted(key) << L" doesn't exists";
            }
        }

    private:

        std::map<std::wstring, std::function<T>> m_subscribers;
    };
}