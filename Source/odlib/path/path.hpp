#pragma once

namespace odlib
{
    namespace path
    {
        /// <summary>
        /// Combines two strings into a path.
        /// </summary>
        /// <param name="path1">The first path to combine.</param>
        /// <param name="path2">The second path to combine.</param>
        /// <returns>The combined paths.</returns>
        const std::wstring combine(const std::wstring& path1, const std::wstring& path2);

        /// <summary>
        /// Combines three strings into a path.
        /// </summary>
        /// <param name="path1">The first path to combine.</param>
        /// <param name="path2">The second path to combine.</param>
        /// <param name="path3">The third path to combine.</param>
        /// <returns>The combined paths.</returns>
        const std::wstring combine(const std::wstring& path1, const std::wstring& path2, const std::wstring& path3);

        /// <summary>
        /// Combines four strings into a path.
        /// </summary>
        /// <param name="path1">The first path to combine.</param>
        /// <param name="path2">The second path to combine.</param>
        /// <param name="path3">The third path to combine.</param>
        /// <param name="path4">The fourth path to combine.</param>
        /// <returns>The combined paths.</returns>
        const std::wstring combine(const std::wstring& path1, const std::wstring& path2, const std::wstring& path3, const std::wstring& path4);

        /// <summary>
        /// Combines an array of strings into a path.
        /// </summary>
        /// <param name="paths">An array of parts of the path.</param>
        /// <returns>The combined paths.</returns>
        const std::wstring combine(const std::initializer_list<std::wstring> paths);
    }
}