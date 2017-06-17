#pragma once

namespace ODLib
{
    template<typename T>
    class Event
    {
    public:

        Event() = default;
        ~Event() = default;

        template<typename... Args>
        void Notify(Args&& ...args)
        {
            for (auto& Subscriber : m_subscribers)
            {
                Subscriber.second(std::forward<Args>(args)...);
            }
        }

        void Subscribe(const std::wstring& Key, const std::function<T> Function)
        {
            auto Subscriber = m_subscribers.find(Key);

            if (Subscriber == m_subscribers.end())
            {
                m_subscribers.emplace(Key, Function);

#ifdef _DEBUG
                LOG_DEBUG << L"A subscriber with key " << std::quoted(Key) << L" was added";
#endif
            }
            else
            {
                LOG_WARNING << L"A subscriber with key " << std::quoted(Key) << L" already exists";
            }
        }

        void Unsubscribe(const std::wstring& Key)
        {
            auto Subscriber = m_subscribers.find(Key);

            if (Subscriber != m_subscribers.end())
            {
                m_subscribers.erase(Subscriber);

#ifdef _DEBUG
                LOG_DEBUG << L"A subscriber with key " << std::quoted(Key) << L" was removed";
#endif
            }
            else
            {
                LOG_WARNING << L"A subscriber with key " << std::quoted(Key) << L" doesn't exists";
            }
        }

    private:

        std::map<std::wstring, std::function<T>> m_subscribers;
    };
}