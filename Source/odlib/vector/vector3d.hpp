#pragma once

namespace odlib
{
    template<typename T>
    class vector3d
    {
    public:

        vector3d() = default;

        vector3d(const T x, const T y, const T z)
            : x(x)
            , y(y)
            , z(z)
        {
        }

        vector3d(const vector3d& Vector)
            : x(Vector.x)
            , y(Vector.y)
            , z(Vector.z)
        {
        }

        vector3d(vector3d&& Vector)
            : x(std::move(Vector.x))
            , y(std::move(Vector.y))
            , z(std::move(Vector.z))
        {
            Vector.x = 0;
            Vector.y = 0;
            Vector.z = 0;
        }

        ~vector3d() = default;

        bool operator==(const vector3d<T>& rhs) const
        {
            return x == rhs.x && y == rhs.y && z == rhs.z;
        }

        bool operator!=(const vector3d<T>& rhs) const
        {
            return x != rhs.x || y != rhs.y || z != rhs.z;
        }

        bool operator<(const vector3d<T>& rhs) const
        {
            return x < rhs.x && y < rhs.y && z < rhs.z;
        }

        bool operator>(const vector3d<T>& rhs) const
        {
            return x > rhs.x && y > rhs.y && z > rhs.z;
        }

        bool operator<=(const vector3d<T>& rhs) const
        {
            return x <= rhs.x && y <= rhs.y && z <= rhs.z;
        }

        bool operator>=(const vector3d<T>& rhs) const
        {
            return x >= rhs.x && y >= rhs.y && z >= rhs.z;
        }

        float operator[](int32_t Index) const
        {
            if (Index == 0)
            {
                return x;
            }
            else if (Index == 1)
            {
                return y;
            }

            return z;
        }

        vector3d operator+(const vector3d& rhs) const
        {
            return vector3d<T>(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        vector3d operator+(const T rhs) const
        {
            return vector3d<T>(x + rhs, y + rhs, z + rhs);
        }

        vector3d operator-() const
        {
            return vector3d<T>(-x, -y, -z);
        }

        vector3d operator-(const vector3d& rhs) const
        {
            return vector3d<T>(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        vector3d operator-(const T rhs) const
        {
            return vector3d<T>(x - rhs, y - rhs, z - rhs);
        }

        vector3d operator*(const vector3d& rhs) const
        {
            return vector3d<T>(x * rhs.x, y * rhs.y, z * rhs.z);
        }

        vector3d operator*(const T rhs) const
        {
            return vector3d<T>(x * rhs, y * rhs, z * rhs);
        }

        vector3d operator/(const vector3d& rhs) const
        {
            return vector3d<T>(x / rhs.x, y / rhs.y, z / rhs.z);
        }

        vector3d operator/(const T rhs) const
        {
            return vector3d<T>(x / rhs, y / rhs, z / rhs);
        }

        vector3d& operator=(const vector3d& rhs)
        {
            x = rhs.x;
            y = rhs.y;
            z = rhs.z;

            return *this;
        }

        vector3d& operator=(vector3d&& rhs)
        {
            x = std::move(rhs.x);
            y = std::move(rhs.y);
            z = std::move(rhs.z);

            rhs.x = 0;
            rhs.y = 0;
            rhs.z = 0;

            return *this;
        }

        vector3d& operator+=(const vector3d& rhs)
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;

            return *this;
        }

        vector3d& operator+=(const T rhs)
        {
            x += rhs;
            y += rhs;
            z += rhs;

            return *this;
        }

        vector3d& operator-=(const vector3d& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;

            return *this;
        }

        vector3d& operator-=(const T rhs)
        {
            x -= rhs;
            y -= rhs;
            z -= rhs;

            return *this;
        }

        vector3d& operator*=(const vector3d& rhs)
        {
            x *= rhs.x;
            y *= rhs.y;
            z *= rhs.z;

            return *this;
        }

        vector3d& operator*=(const T rhs)
        {
            x *= rhs;
            y *= rhs;
            z *= rhs;

            return *this;
        }

        vector3d& operator/=(const vector3d& rhs)
        {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;

            return *this;
        }

        vector3d& operator/=(const T rhs)
        {
            x /= rhs;
            y /= rhs;
            z /= rhs;

            return *this;
        }

        T x;

        T y;

        T z;
    };
}