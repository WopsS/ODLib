#include <odlib/odlib.hpp>
#include <odlib/logger/synchronous.hpp>

odlib::logger::synchronous::synchronous(odlib::logger::settings settings)
    : logger(settings)
{
}

void odlib::logger::synchronous::operator+=(odlib::logger::record::record& rhs)
{
    std::unique_lock<std::mutex> _(m_mutex);
    write_line(rhs);
}

ODLIB_SINGLETON_IMPLEMENT_SOURCE(odlib::logger::synchronous)