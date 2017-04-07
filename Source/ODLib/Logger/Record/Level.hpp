#pragma once

namespace ODLib
{
    namespace Logger
    {
        namespace Record
        {
            namespace Level
            {
                /// <summary>
                /// Level of <see cref="ODLib::Logger::Record::Record"/>.
                /// </summary>
                enum class Level : uint8_t
                {
                    Debug,
                    Verbose,
                    Info,
                    Warning,
                    Error
                };

                /// <summary>
                /// Convert the <see cref="ODLib::Logger::Record::Level"/> to string.
                /// </summary>
                /// <param name="Level"><see cref="ODLib::Logger::Record::Level"/> to be converted.</param>
                /// <returns><paramref name="Level"/> as a string.</returns>
                const std::wstring ToString(const Level Level);
            }
        }
    }
}