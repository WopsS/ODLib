#pragma once

#include <ODLib/Logger/Record/Record.hpp>
#include <ODLib/Logger/Settings.hpp>

namespace ODLib
{
    namespace Logger
    {
        class Logger
        {
        public:

            /// <summary>
            /// Appends a record to the file. 
            /// </summary>
            virtual void operator+=(ODLib::Logger::Record::Record& rhs) = 0;

        protected:

            Logger(ODLib::Logger::Settings Settings);
            virtual ~Logger();

            void WriteLine(const ODLib::Logger::Record::Record& Record);

            std::wfstream m_file;

        private:

            void CreateFileIfNeeded();

            std::chrono::system_clock::time_point GetNextRotation();

            ODLib::Logger::Settings m_settings;

            std::chrono::system_clock::time_point m_nextRotation;
        };
    }
}

#ifdef ODLIB_ASYNCHRONOUS_LOGGING_AS_DEFAULT
#define LOG(Level) *(ODLib::Logger::Asynchronous::GetInstance()) += ODLib::Logger::Record::Record(Level)
#else
#define LOG(Level) *(ODLib::Logger::Synchronous::GetInstance()) += ODLib::Logger::Record::Record(Level)
#endif

#ifdef _DEBUG
#define LOG_DEBUG LOG(ODLib::Logger::Record::Level::Level::Debug)
#endif

#define LOG_INFO LOG(ODLib::Logger::Record::Level::Level::Info)
#define LOG_WARNING LOG(ODLib::Logger::Record::Level::Level::Warning)
#define LOG_ERROR LOG(ODLib::Logger::Record::Level::Level::Error)