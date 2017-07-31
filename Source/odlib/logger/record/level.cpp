#include <odlib/odlib.hpp>
#include <odlib/logger/record/level.hpp>

const std::wstring odlib::logger::record::level::to_string(const level level)
{
    switch (level)
    {
        case odlib::logger::record::level::level::debug:
        {
            return L"DEBUG";
        }
        case odlib::logger::record::level::level::error:
        {
            return L"ERROR";
        }
        case odlib::logger::record::level::level::info:
        {
            return L"INFO";
        }
        case odlib::logger::record::level::level::warning:
        {
            return L"WARNING";
        }
    }

    return L"UNKNOWN(" + std::to_wstring(static_cast<uint16_t>(level)) + L")";
}