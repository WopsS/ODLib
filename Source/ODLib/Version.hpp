#pragma once

namespace ODLib
{
    namespace Version
    {
        /// <summary>
        /// Get ODLib's version as an integer.
        /// </summary>
        const uint32_t Id();

        /// <summary>
        /// Get ODLib's version as a string.
        /// </summary>
        const std::string String();

        /// <summary>
        /// Get ODLib's version as a wstring.
        /// </summary>
        const std::wstring WString();
    }
}