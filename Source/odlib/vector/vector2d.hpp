#pragma once

namespace odlib
{
    template<typename T>
    class vector2d
    {
    public:

        vector2d() = default;

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
            Vector.x = 0;
            Vector.y = 0;
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

        float operator[](int32_t Index) const
        {
            return Index == 0 ? x : y;
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