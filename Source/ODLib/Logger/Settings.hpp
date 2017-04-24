#pragma once

namespace ODLib
{
    namespace Logger
    {
        /// <summary>
        /// Settings class for a logger.
        /// </summary>
        struct Settings
        {
            /// <summary>
            /// Rotate the log file every day at midnight.
            /// </summary>
            bool DailyRotation = true;

            /// <summary>
            /// File name of the log.
            /// </summary>
            std::wstring FileName = "logs/%Y-%m-%d.log";

            /// <summary>
            /// How the log file should be open, use <see cref="std::ios"/>.
            /// </summary>
            std::ios_base::openmode FileMode = std::ios_base::app;
        };
    }
}