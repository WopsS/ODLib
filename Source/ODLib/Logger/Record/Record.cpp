#include <ODLib/ODLib.hpp>
#include <ODLib/Logger/Record/Record.hpp>

ODLib::Logger::Record::Record::Record(const Logger::Record::Level::Level Level)
    : m_level(Level)
{
    auto Time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::wostringstream Result;
    Result << std::put_time(std::localtime(&Time), L"%c");

    m_time = Result.str();
}

ODLib::Logger::Record::Record::Record(const Record& Record)
    : m_level(Record.m_level)
    , m_stream(Record.m_stream.str())
    , m_time(Record.m_time)
{
}

ODLib::Logger::Record::Record::Record(Record&& Record) noexcept
    : m_level(std::move(Record.m_level))
    , m_stream(std::move(Record.m_stream))
    , m_time(std::move(Record.m_time))
{
}

const ODLib::Logger::Record::Level::Level& ODLib::Logger::Record::Record::GetLevel() const
{
    return m_level;
}

const std::wstring ODLib::Logger::Record::Record::GetText() const
{
    return m_stream.str() + L"\n";
}

const std::wstring& ODLib::Logger::Record::Record::GetTime() const
{
    return m_time;
}
