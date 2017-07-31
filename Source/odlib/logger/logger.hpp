#pragma once

#include <odlib/logger/record/record.hpp>
#include <odlib/logger/settings.hpp>

namespace odlib
{
    namespace logger
    {
        class logger
        {
        public:

            /// <summary>
            /// Appends a record to the file. 
            /// </summary>
            virtual void operator+=(odlib::logger::record::record& rhs) = 0;

        protected:

            logger(odlib::logger::settings settings);
            virtual ~logger();

            void write_line(const odlib::logger::record::record& record);

            std::wfstream m_file;

        private:

            void create_file_if_needed();

            std::chrono::system_clock::time_point get_next_rotation();

            odlib::logger::settings m_settings;

            std::chrono::system_clock::time_point m_next_rotation;
        };
    }
}

#ifdef ODLIB_ASYNCHRONOUS_LOGGING_AS_DEFAULT
#define LOG(level) *(odlib::logger::asynchronous::GetInstance()) += odlib::logger::record::record(level)
#else
#define LOG(level) *(odlib::logger::synchronous::get_instance()) += odlib::logger::record::record(level)
#endif

#ifdef _DEBUG
#define LOG_DEBUG LOG(odlib::logger::record::level::level::debug)
#endif

#define LOG_INFO LOG(odlib::logger::record::level::level::info)
#define LOG_WARNING LOG(odlib::logger::record::level::level::warning)
#define LOG_ERROR LOG(odlib::logger::record::level::level::error)