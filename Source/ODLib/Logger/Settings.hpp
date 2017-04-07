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
            std::string FileName = "logs/%Y-%m-%d-%M.log";

            /// <summary>
            /// How the log file should be open, use <see cref="std::ios"/>.
            /// </summary>
            uint32_t FileMode = std::ios::ate;
        };
    }
}