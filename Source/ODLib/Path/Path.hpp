#pragma once

namespace ODLib
{
    namespace Path
    {
        /// <summary>
        /// Combines two strings into a path.
        /// </summary>
        /// <param name="Path1">The first path to combine.</param>
        /// <param name="Path2">The second path to combine.</param>
        /// <returns>The combined paths.</returns>
        const std::wstring Combine(const std::wstring& Path1, const std::wstring& Path2);

        /// <summary>
        /// Combines three strings into a path.
        /// </summary>
        /// <param name="Path1">The first path to combine.</param>
        /// <param name="Path2">The second path to combine.</param>
        /// <param name="Path3">The third path to combine.</param>
        /// <returns>The combined paths.</returns>
        const std::wstring Combine(const std::wstring& Path1, const std::wstring& Path2, const std::wstring& Path3);

        /// <summary>
        /// Combines four strings into a path.
        /// </summary>
        /// <param name="Path1">The first path to combine.</param>
        /// <param name="Path2">The second path to combine.</param>
        /// <param name="Path3">The third path to combine.</param>
        /// <param name="Path4">The fourth path to combine.</param>
        /// <returns>The combined paths.</returns>
        const std::wstring Combine(const std::wstring& Path1, const std::wstring& Path2, const std::wstring& Path3, const std::wstring& Path4);

        /// <summary>
        /// Combines an array of strings into a path.
        /// </summary>
        /// <param name="Paths">An array of parts of the path.</param>
        /// <returns>The combined paths.</returns>
        const std::wstring Combine(const std::initializer_list<std::wstring> Paths);
    }
}