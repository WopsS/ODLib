#pragma once

#include <odlib/logger/logger.hpp>

namespace odlib
{
    namespace logger
    {
        /// <summary>
        /// Synchronous logger class.
        /// </summary>
        class synchronous : logger
        {
        public:

            /// <summary>
            /// Appends a record to the file. 
            /// </summary>
            void operator+=(odlib::logger::record::record& rhs) final;

        private:

            synchronous(odlib::logger::settings settings = odlib::logger::settings());
            ~synchronous() = default;

            std::mutex m_mutex;

            ODLIB_SINGLETON_IMPLEMENT_HEADER(synchronous)
        };
    }
}