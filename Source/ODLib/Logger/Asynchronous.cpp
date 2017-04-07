#include <ODLib/ODLib.hpp>
#include <ODLib/Logger/Asynchronous.hpp>

ODLib::Logger::Asynchronous::Asynchronous(ODLib::Logger::Settings Settings)
    : Logger(Settings)
    , m_continueRunning(true)
{
    m_thread = std::thread(&Asynchronous::Worker, this);
}

ODLib::Logger::Asynchronous::~Asynchronous()
{
    // Prevent destruction if the queue isn't empty.
    bool IsEmpty = false;

    do
    {
        {
            std::unique_lock<std::mutex> _(m_mutex);
            IsEmpty = m_records.empty();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    } while (IsEmpty == false);

    m_continueRunning = false;
    m_thread.join();
}

void ODLib::Logger::Asynchronous::operator+=(ODLib::Logger::Record::Record& rhs)
{
    std::unique_lock<std::mutex> _(m_mutex);
    m_records.emplace(std::move(rhs));
}

void ODLib::Logger::Asynchronous::Worker()
{
    while (m_continueRunning == true)
    {
        {
            std::unique_lock<std::mutex> _(m_mutex);

            while (m_records.empty() == false)
            {
                WriteLine(m_records.front());
                m_records.pop();
            }
        }

        std::this_thread::sleep_for(5ms);
    }
}

ODLIB_IMPLEMENT_SINGLETON_SOURCE(ODLib::Logger::Asynchronous)