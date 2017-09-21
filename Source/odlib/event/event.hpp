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
        /// <returns>True if the subscriber doesn't exist and was added, false otherwise.</returns>
        bool subscribe(const std::wstring& key, const std::function<T> function)
        {
            auto subscriber = m_subscribers.find(key);

            if (subscriber == m_subscribers.end())
            {
                m_subscribers.emplace(key, function);
                return true;
            }

            return false;
        }

        /// <summary>
        /// Unsubscribe a function to the event.
        /// </summary>
        /// <param name="key">Key of the subscriber.</param>
        /// <returns>True if the subscriber exist and was removed, false otherwise.</returns>
        bool unsubscribe(const std::wstring& key)
        {
            auto subscriber = m_subscribers.find(key);

            if (subscriber != m_subscribers.end())
            {
                m_subscribers.erase(subscriber);
                return true;
            }

            return false;
        }

    private:

        std::map<std::wstring, std::function<T>> m_subscribers;
    };
}