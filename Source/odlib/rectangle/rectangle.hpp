#pragma once

namespace odlib
{
    /// <summary>
    /// Rectangle class.
    /// </summary>
    /// <typeparam name="T">The type of <see cref="odlib::rectangle::height"/> and <see cref="odlib::rectangle::width"/>.</typeparam>
    template<typename T>
    class rectangle
    {
    public:

        rectangle()
            : width(T())
            , height(T())
        {
        }

        rectangle(const T width, const T height)
            : width(width)
            , height(height)
        {
        }

        rectangle(const rectangle& rectangle)
            : width(rectangle.width)
            , height(rectangle.height)
        {
        }

        rectangle(rectangle&& rectangle)
            : width(std::move(rectangle.width))
            , height(std::move(rectangle.height))
        {
            rectangle.width = T();
            rectangle.height = T();
        }

        ~rectangle() = default;

        bool operator==(const rectangle<T>& rhs) const
        {
            return width == rhs.width && height == rhs.height;
        }

        bool operator!=(const rectangle<T>& rhs) const
        {
            return width != rhs.width || height != rhs.height;
        }

        bool operator<(const rectangle<T>& rhs) const
        {
            return width < rhs.width && height < rhs.height;
        }

        bool operator>(const rectangle<T>& rhs) const
        {
            return width > rhs.width && height > rhs.height;
        }

        bool operator<=(const rectangle<T>& rhs) const
        {
            return width <= rhs.width && height <= rhs.height;
        }

        bool operator>=(const rectangle<T>& rhs) const
        {
            return width >= rhs.width && height >= rhs.height;
        }

        float operator[](int32_t index) const
        {
            return index == 0 ? width : height;
        }

        rectangle operator+(const rectangle& rhs) const
        {
            return rectangle<T>(width + rhs.width, height + rhs.height);
        }

        rectangle operator+(const T rhs) const
        {
            return rectangle<T>(width + rhs, height + rhs);
        }

        rectangle operator-() const
        {
            return rectangle<T>(-width, -height);
        }

        rectangle operator-(const rectangle& rhs) const
        {
            return rectangle<T>(width - rhs.width, height - rhs.height);
        }

        rectangle operator-(const T rhs) const
        {
            return rectangle<T>(width - rhs, height - rhs);
        }

        rectangle operator*(const rectangle& rhs) const
        {
            return rectangle<T>(width * rhs.width, height * rhs.height);
        }

        rectangle operator*(const T rhs) const
        {
            return rectangle<T>(width * rhs, height * rhs);
        }

        rectangle operator/(const rectangle& rhs) const
        {
            return rectangle<T>(width / rhs.width, height / rhs.height);
        }

        rectangle operator/(const T rhs) const
        {
            return rectangle<T>(width / rhs, height / rhs);
        }

        rectangle& operator=(const rectangle& rhs)
        {
            width = rhs.width;
            height = rhs.height;

            return *this;
        }

        rectangle& operator=(rectangle&& rhs)
        {
            width = std::move(rhs.width);
            height = std::move(rhs.height);

            rhs.width = 0;
            rhs.height = 0;

            return *this;
        }

        rectangle& operator+=(const rectangle& rhs)
        {
            width += rhs.width;
            height += rhs.height;

            return *this;
        }

        rectangle& operator+=(const T rhs)
        {
            width += rhs;
            height += rhs;

            return *this;
        }

        rectangle& operator-=(const rectangle& rhs)
        {
            width -= rhs.width;
            height -= rhs.height;

            return *this;
        }

        rectangle& operator-=(const T rhs)
        {
            width -= rhs;
            height -= rhs;

            return *this;
        }

        rectangle& operator*=(const rectangle& rhs)
        {
            width *= rhs.width;
            height *= rhs.height;

            return *this;
        }

        rectangle& operator*=(const T rhs)
        {
            width *= rhs;
            height *= rhs;

            return *this;
        }

        rectangle& operator/=(const rectangle& rhs)
        {
            width /= rhs.width;
            height /= rhs.height;

            return *this;
        }

        rectangle& operator/=(const T rhs)
        {
            width /= rhs;
            height /= rhs;

            return *this;
        }

        T width;

        T height;
    };
}