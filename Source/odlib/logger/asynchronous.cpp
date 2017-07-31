#include <odlib/odlib.hpp>
#include <odlib/logger/asynchronous.hpp>

odlib::logger::asynchronous::asynchronous(odlib::logger::settings settings)
    : logger(settings)
    , m_continue_running(true)
{
    m_thread = std::thread(&asynchronous::worker, this);
}

odlib::logger::asynchronous::~asynchronous()
{
    // Prevent destruction if the queue isn't empty.
    bool is_empty = false;

    do
    {
        {
            std::unique_lock<std::mutex> _(m_mutex);
            is_empty = m_records.empty();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    } while (is_empty == false);

    m_continue_running = false;
    m_thread.join();
}

void odlib::logger::asynchronous::operator+=(odlib::logger::record::record& rhs)
{
    std::unique_lock<std::mutex> _(m_mutex);
    m_records.emplace(std::move(rhs));
}

void odlib::logger::asynchronous::worker()
{
    while (m_continue_running == true)
    {
        {
            std::unique_lock<std::mutex> _(m_mutex);

            while (m_records.empty() == false)
            {
                write_line(m_records.front());
                m_records.pop();
            }
        }

        std::this_thread::sleep_for(5ms);
    }
}

ODLIB_SINGLETON_IMPLEMENT_SOURCE(odlib::logger::asynchronous)