#pragma once

#include <ODLib/Logger/Logger.hpp>

namespace ODLib
{
    namespace Logger
    {
        /// <summary>
        /// Asynchronous logger class.
        /// </summary>
        class Asynchronous : Logger
        {
        public:

            /// <summary>
            /// Appends a record to the queue. 
            /// </summary>
            void operator+=(ODLib::Logger::Record::Record& rhs) final;

        private:

            Asynchronous(ODLib::Logger::Settings Settings = ODLib::Logger::Settings());
            ~Asynchronous();

            void Worker();

            std::thread m_thread;

            std::mutex m_mutex;

            std::atomic_bool m_continueRunning;

            std::queue<ODLib::Logger::Record::Record> m_records;

            ODLIB_IMPLEMENT_SINGLETON_HEADER(Asynchronous)
        };
    }
}