#include <odlib/odlib.hpp>
#include <odlib/logger/record/record.hpp>

odlib::logger::record::record::record(const logger::record::level::level level)
    : m_level(level)
{
    auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::wostringstream result;
    result << std::put_time(std::localtime(&time), L"%c");

    m_time = result.str();
}

odlib::logger::record::record::record(const record& record)
    : m_level(record.m_level)
    , m_stream(record.m_stream.str())
    , m_time(record.m_time)
{
}

odlib::logger::record::record::record(record&& record) noexcept
    : m_level(std::move(record.m_level))
    , m_stream(std::move(record.m_stream))
    , m_time(std::move(record.m_time))
{
}

const odlib::logger::record::level::level& odlib::logger::record::record::get_level() const
{
    return m_level;
}

const std::wstring odlib::logger::record::record::get_text() const
{
    return m_stream.str() + L"\n";
}

const std::wstring& odlib::logger::record::record::get_time() const
{
    return m_time;
}
