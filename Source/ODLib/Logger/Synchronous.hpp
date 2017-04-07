#pragma once

#include <ODLib/Logger/Logger.hpp>

namespace ODLib
{
    namespace Logger
    {
        /// <summary>
        /// Synchronous logger class.
        /// </summary>
        class Synchronous : Logger
        {
        public:

            /// <summary>
            /// Appends a record to the file. 
            /// </summary>
            void operator+=(ODLib::Logger::Record::Record& rhs) final;

        private:

            Synchronous(ODLib::Logger::Settings Settings = ODLib::Logger::Settings());
            ~Synchronous() = default;

            std::mutex m_mutex;

            ODLIB_IMPLEMENT_SINGLETON_HEADER(Synchronous)
        };
    }
}