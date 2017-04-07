#pragma once

#include <ODLib/Logger/Record/Level.hpp>

namespace ODLib
{
    namespace Logger
    {
        namespace Record
        {
            /// <summary>
            /// Record class that represent a line for the file.
            /// </summary>
            class Record
            {
            public:

                Record(const ODLib::Logger::Record::Level::Level Level);
                Record(const Record& Record);
                Record(Record&& Record) noexcept;

                ~Record() = default;

                /// <summary>
                /// Appends data to the stream.
                /// </summary>
                /// <typeparam name="T">The type of the value which will be added to stream.</typeparam>
                /// <returns>This instance.</returns>
                template<typename T>
                Record& operator<<(const T& rhs)
                {
                    m_stream << rhs;
                    return *this;
                }

                /// <summary>
                /// Get the level of the record.
                /// </summary>
                /// <returns><see cref="ODLib::Logger::Record::Level"/> of the record.</returns>
                const ODLib::Logger::Record::Level::Level& GetLevel() const;

                /// <summary>
                /// Get the text of the record.
                /// </summary>
                /// <returns>Text of the record.</returns>
                const std::wstring GetText() const;

                /// <summary>
                /// Get time when the record was created.
                /// </summary>
                /// <returns>Time of the record.</returns>
                const std::wstring& GetTime() const;

            private:

                std::wstring m_time;

                ODLib::Logger::Record::Level::Level m_level;

                std::wostringstream m_stream;
            };
        }
    }
}