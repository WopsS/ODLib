#pragma once

#include <odlib/logger/record/level.hpp>

namespace odlib
{
    namespace logger
    {
        namespace record
        {
            /// <summary>
            /// Record class that represent a line for the file.
            /// </summary>
            class record
            {
            public:

                record(const odlib::logger::record::level::level level);
                record(const record& record);
                record(record&& record) noexcept;

                ~record() = default;

                /// <summary>
                /// Appends data to the stream.
                /// </summary>
                /// <typeparam name="T">The type of the value which will be added to stream.</typeparam>
                /// <returns>This instance.</returns>
                template<typename T>
                record& operator<<(const T& rhs)
                {
                    m_stream << rhs;
                    return *this;
                }

                /// <summary>
                /// Get the level of the record.
                /// </summary>
                /// <returns><see cref="odlib::logger::record::level"/> of the record.</returns>
                const odlib::logger::record::level::level& get_level() const;

                /// <summary>
                /// Get the text of the record.
                /// </summary>
                /// <returns>Text of the record.</returns>
                const std::wstring get_text() const;

                /// <summary>
                /// Get time when the record was created.
                /// </summary>
                /// <returns>Time of the record.</returns>
                const std::wstring& get_time() const;

            private:

                std::wstring m_time;

                odlib::logger::record::level::level m_level;

                std::wostringstream m_stream;
            };
        }
    }
}