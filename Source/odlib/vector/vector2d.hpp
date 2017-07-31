#pragma once

namespace odlib
{
    /// <summary>
    /// Vector2D class.
    /// </summary>
    /// <typeparam name="T">The type of <see cref="odlib::vector2d::x"/> and <see cref="odlib::vector2d::y"/>.</typeparam>
    template<typename T>
    class vector2d
    {
    public:

        vector2d()
            : x(T())
            , y(T())
        {
        }

        vector2d(const T x, const T y)
            : x(x)
            , y(y)
        {
        }

        vector2d(const vector2d& Vector)
            : x(Vector.x)
            , y(Vector.y)
        {
        }

        vector2d(vector2d&& Vector)
            : x(std::move(Vector.x))
            , y(std::move(Vector.y))
        {
            Vector.x = T();
            Vector.y = T();
        }

        ~vector2d() = default;

        bool operator==(const vector2d<T>& rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }

        bool operator!=(const vector2d<T>& rhs) const
        {
            return x != rhs.x || y != rhs.y;
        }

        bool operator<(const vector2d<T>& rhs) const
        {
            return x < rhs.x && y < rhs.y;
        }

        bool operator>(const vector2d<T>& rhs) const
        {
            return x > rhs.x && y > rhs.y;
        }

        bool operator<=(const vector2d<T>& rhs) const
        {
            return x <= rhs.x && y <= rhs.y;
        }

        bool operator>=(const vector2d<T>& rhs) const
        {
            return x >= rhs.x && y >= rhs.y;
        }

        float operator[](int32_t index) const
        {
            return index == 0 ? x : y;
        }

        vector2d operator+(const vector2d& rhs) const
        {
            return vector2d<T>(x + rhs.x, y + rhs.y);
        }

        vector2d operator+(const T rhs) const
        {
            return vector2d<T>(x + rhs, y + rhs);
        }

        vector2d operator-() const
        {
            return vector2d<T>(-x, -y);
        }

        vector2d operator-(const vector2d& rhs) const
        {
            return vector2d<T>(x - rhs.x, y - rhs.y);
        }

        vector2d operator-(const T rhs) const
        {
            return vector2d<T>(x - rhs, y - rhs);
        }

        vector2d operator*(const vector2d& rhs) const
        {
            return vector2d<T>(x * rhs.x, y * rhs.y);
        }

        vector2d operator*(const T rhs) const
        {
            return vector2d<T>(x * rhs, y * rhs);
        }

        vector2d operator/(const vector2d& rhs) const
        {
            return vector2d<T>(x / rhs.x, y / rhs.y);
        }

        vector2d operator/(const T rhs) const
        {
            return vector2d<T>(x / rhs, y / rhs);
        }

        vector2d& operator=(const vector2d& rhs)
        {
            x = rhs.x;
            y = rhs.y;

            return *this;
        }

        vector2d& operator=(vector2d&& rhs)
        {
            x = std::move(rhs.x);
            y = std::move(rhs.y);

            rhs.x = 0;
            rhs.y = 0;

            return *this;
        }

        vector2d& operator+=(const vector2d& rhs)
        {
            x += rhs.x;
            y += rhs.y;

            return *this;
        }

        vector2d& operator+=(const T rhs)
        {
            x += rhs;
            y += rhs;

            return *this;
        }

        vector2d& operator-=(const vector2d& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;

            return *this;
        }

        vector2d& operator-=(const T rhs)
        {
            x -= rhs;
            y -= rhs;

            return *this;
        }

        vector2d& operator*=(const vector2d& rhs)
        {
            x *= rhs.x;
            y *= rhs.y;

            return *this;
        }

        vector2d& operator*=(const T rhs)
        {
            x *= rhs;
            y *= rhs;

            return *this;
        }

        vector2d& operator/=(const vector2d& rhs)
        {
            x /= rhs.x;
            y /= rhs.y;

            return *this;
        }

        vector2d& operator/=(const T rhs)
        {
            x /= rhs;
            y /= rhs;

            return *this;
        }

        T x;

        T y;
    };
}