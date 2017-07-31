#pragma once

#include <odlib/logger/logger.hpp>

namespace odlib
{
    namespace logger
    {
        /// <summary>
        /// Asynchronous logger class.
        /// </summary>
        class asynchronous : logger
        {
        public:

            /// <summary>
            /// Appends a record to the queue. 
            /// </summary>
            void operator+=(odlib::logger::record::record& rhs) final;

        private:

            asynchronous(odlib::logger::settings settings = odlib::logger::settings());
            ~asynchronous();

            void worker();

            std::thread m_thread;

            std::mutex m_mutex;

            std::atomic_bool m_continue_running;

            std::queue<odlib::logger::record::record> m_records;

            ODLIB_SINGLETON_IMPLEMENT_HEADER(asynchronous)
        };
    }
}