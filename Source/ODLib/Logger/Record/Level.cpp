#include <ODLib/ODLib.hpp>
#include <ODLib/Logger/Record/Level.hpp>

const std::wstring ODLib::Logger::Record::Level::ToString(const Level Level)
{
    switch (Level)
    {
        case ODLib::Logger::Record::Level::Level::Debug:
        {
            return L"DEBUG";
        }
        case ODLib::Logger::Record::Level::Level::Error:
        {
            return L"ERROR";
        }
        case ODLib::Logger::Record::Level::Level::Info:
        {
            return L"INFO";
        }
        case ODLib::Logger::Record::Level::Level::Warning:
        {
            return L"WARNING";
        }
    }

    return L"UNKNOWN(" + std::to_wstring(static_cast<uint16_t>(Level)) + L")";
}