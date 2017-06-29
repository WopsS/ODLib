#pragma once

namespace ODLib
{
    template<typename T>
    class Vector3D
    {
    public:

        Vector3D() = default;

        Vector3D(const T X, const T Y, const T Z)
            : X(X)
            , Y(Y)
            , Z(Z)
        {
        }

        Vector3D(const Vector3D& Vector)
            : X(Vector.X)
            , Y(Vector.Y)
            , Z(Vector.Z)
        {
        }

        Vector3D(Vector3D&& Vector)
            : X(std::move(Vector.X))
            , Y(std::move(Vector.Y))
            , Z(std::move(Vector.Z))
        {
            Vector.X = 0;
            Vector.Y = 0;
            Vector.Z = 0;
        }

        ~Vector3D() = default;

        bool operator==(const Vector3D<T>& rhs) const
        {
            return X == rhs.X && Y == rhs.Y && Z == rhs.Z;
        }

        bool operator!=(const Vector3D<T>& rhs) const
        {
            return X != rhs.X || Y != rhs.Y || Z != rhs.Z;
        }

        bool operator<(const Vector3D<T>& rhs) const
        {
            return X < rhs.X && Y < rhs.Y && Z < rhs.Z;
        }

        bool operator>(const Vector3D<T>& rhs) const
        {
            return X > rhs.X && Y > rhs.Y && Z > rhs.Z;
        }

        bool operator<=(const Vector3D<T>& rhs) const
        {
            return X <= rhs.X && Y <= rhs.Y && Z <= rhs.Z;
        }

        bool operator>=(const Vector3D<T>& rhs) const
        {
            return X >= rhs.X && Y >= rhs.Y && Z >= rhs.Z;
        }

        float operator[](int32_t Index) const
        {
            if (Index == 0)
            {
                return X;
            }
            else if (Index == 1)
            {
                return Y;
            }

            return Z;
        }

        Vector3D operator+(const Vector3D& rhs) const
        {
            return Vector3D<T>(X + rhs.X, Y + rhs.Y, Z + rhs.Z);
        }

        Vector3D operator+(const T rhs) const
        {
            return Vector3D<T>(X + rhs, Y + rhs, Z + rhs);
        }

        Vector3D operator-() const
        {
            return Vector3D<T>(-X, -Y, -Z);
        }

        Vector3D operator-(const Vector3D& rhs) const
        {
            return Vector3D<T>(X - rhs.X, Y - rhs.Y, Z - rhs.Z);
        }

        Vector3D operator-(const T rhs) const
        {
            return Vector3D<T>(X - rhs, Y - rhs, Z - rhs);
        }

        Vector3D operator*(const Vector3D& rhs) const
        {
            return Vector3D<T>(X * rhs.X, Y * rhs.Y, Z * rhs.Z);
        }

        Vector3D operator*(const T rhs) const
        {
            return Vector3D<T>(X * rhs, Y * rhs, Z * rhs);
        }

        Vector3D operator/(const Vector3D& rhs) const
        {
            return Vector3D<T>(X / rhs.X, Y / rhs.Y, Z / rhs.Z);
        }

        Vector3D operator/(const T rhs) const
        {
            return Vector3D<T>(X / rhs, Y / rhs, Z / rhs);
        }

        Vector3D& operator=(const Vector3D& rhs)
        {
            X = rhs.X;
            Y = rhs.Y;
            Z = rhs.Z;

            return *this;
        }

        Vector3D& operator=(Vector3D&& rhs)
        {
            X = std::move(rhs.X);
            Y = std::move(rhs.Y);
            Z = std::move(rhs.Z);

            rhs.X = 0;
            rhs.Y = 0;
            rhs.Z = 0;

            return *this;
        }

        Vector3D& operator+=(const Vector3D& rhs)
        {
            X += rhs.X;
            Y += rhs.Y;
            Z += rhs.Z;

            return *this;
        }

        Vector3D& operator+=(const T rhs)
        {
            X += rhs;
            Y += rhs;
            Z += rhs;

            return *this;
        }

        Vector3D& operator-=(const Vector3D& rhs)
        {
            X -= rhs.X;
            Y -= rhs.Y;
            Z -= rhs.Z;

            return *this;
        }

        Vector3D& operator-=(const T rhs)
        {
            X -= rhs;
            Y -= rhs;
            Z -= rhs;

            return *this;
        }

        Vector3D& operator*=(const Vector3D& rhs)
        {
            X *= rhs.X;
            Y *= rhs.Y;
            Z *= rhs.Z;

            return *this;
        }

        Vector3D& operator*=(const T rhs)
        {
            X *= rhs;
            Y *= rhs;
            Z *= rhs;

            return *this;
        }

        Vector3D& operator/=(const Vector3D& rhs)
        {
            X /= rhs.X;
            Y /= rhs.Y;
            Z /= rhs.Z;

            return *this;
        }

        Vector3D& operator/=(const T rhs)
        {
            X /= rhs;
            Y /= rhs;
            Z /= rhs;

            return *this;
        }

        T X;

        T Y;

        T Z;
    };
}