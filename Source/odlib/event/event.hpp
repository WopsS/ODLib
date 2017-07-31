#pragma once

namespace odlib
{
    template<typename T>
    class event
    {
    public:

        event() = default;
        ~event() = default;

        template<typename... Args>
        void notify(Args&& ...args)
        {
            for (auto& subscriber : m_subscribers)
            {
                subscriber.second(std::forward<Args>(args)...);
            }
        }

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