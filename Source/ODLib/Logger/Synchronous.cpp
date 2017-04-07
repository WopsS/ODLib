#include <ODLib/ODLib.hpp>
#include <ODLib/Logger/Synchronous.hpp>

ODLib::Logger::Synchronous::Synchronous(ODLib::Logger::Settings Settings)
    : Logger(Settings)
{
}

void ODLib::Logger::Synchronous::operator+=(ODLib::Logger::Record::Record& rhs)
{
    std::unique_lock<std::mutex> _(m_mutex);
    WriteLine(rhs);
}

ODLIB_IMPLEMENT_SINGLETON_SOURCE(ODLib::Logger::Synchronous)