#pragma once

namespace odlib
{
    namespace logger
    {
        /// <summary>
        /// Settings class for a logger.
        /// </summary>
        struct settings
        {
            /// <summary>
            /// Rotate the log file every day at midnight.
            /// </summary>
            bool daily_rotation = true;

            /// <summary>
            /// File name of the log.
            /// </summary>
            std::wstring file_name = L"logs/%Y-%m-%d.log";

            /// <summary>
            /// How the log file should be open, use <see cref="std::ios"/>.
            /// </summary>
            std::ios_base::openmode file_mode = std::ios_base::app;
        };
    }
}