#pragma once

namespace odlib
{
    namespace logger
    {
        namespace record
        {
            namespace level
            {
                /// <summary>
                /// Level of <see cref="odlib::logger::record::record"/>.
                /// </summary>
                enum class level : uint8_t
                {
                    debug,
                    verbose,
                    info,
                    warning,
                    error
                };

                /// <summary>
                /// Convert the <see cref="odlib::logger::record::level"/> to string.
                /// </summary>
                /// <param name="Level"><see cref="odlib::logger::record::level"/> to be converted.</param>
                /// <returns><paramref name="level"/> as a string.</returns>
                const std::wstring to_string(const level level);
            }
        }
    }
}