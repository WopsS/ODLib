#pragma once

namespace ODLib
{
    template<typename T>
    class Vector2D
    {
    public:

        Vector2D() = default;

        Vector2D(const T X, const T Y)
            : X(X)
            , Y(Y)
        {
        }

        Vector2D(const Vector2D& Vector)
            : X(Vector.X)
            , Y(Vector.Y)
        {
        }

        Vector2D(Vector2D&& Vector)
            : X(std::move(Vector.X))
            , Y(std::move(Vector.Y))
        {
            Vector.X = 0;
            Vector.Y = 0;
        }

        ~Vector2D() = default;

        bool operator==(const Vector2D<T>& rhs) const
        {
            return X == rhs.X && Y == rhs.Y;
        }

        bool operator!=(const Vector2D<T>& rhs) const
        {
            return X != rhs.X || Y != rhs.Y;
        }

        bool operator<(const Vector2D<T>& rhs) const
        {
            return X < rhs.X && Y < rhs.Y;
        }

        bool operator>(const Vector2D<T>& rhs) const
        {
            return X > rhs.X && Y > rhs.Y;
        }

        bool operator<=(const Vector2D<T>& rhs) const
        {
            return X <= rhs.X && Y <= rhs.Y;
        }

        bool operator>=(const Vector2D<T>& rhs) const
        {
            return X >= rhs.X && Y >= rhs.Y;
        }

        float operator[](int32_t Index) const
        {
            return Index == 0 ? X : Y;
        }

        Vector2D operator+(const Vector2D& rhs) const
        {
            return Vector2D<T>(X + rhs.X, Y + rhs.Y);
        }

        Vector2D operator+(const T rhs) const
        {
            return Vector2D<T>(X + rhs, Y + rhs);
        }

        Vector2D operator-() const
        {
            return Vector2D<T>(-X, -Y);
        }

        Vector2D operator-(const Vector2D& rhs) const
        {
            return Vector2D<T>(X - rhs.X, Y - rhs.Y);
        }

        Vector2D operator-(const T rhs) const
        {
            return Vector2D<T>(X - rhs, Y - rhs);
        }

        Vector2D operator*(const Vector2D& rhs) const
        {
            return Vector2D<T>(X * rhs.X, Y * rhs.Y);
        }

        Vector2D operator*(const T rhs) const
        {
            return Vector2D<T>(X * rhs, Y * rhs);
        }

        Vector2D operator/(const Vector2D& rhs) const
        {
            return Vector2D<T>(X / rhs.X, Y / rhs.Y);
        }

        Vector2D operator/(const T rhs) const
        {
            return Vector2D<T>(X / rhs, Y / rhs);
        }

        Vector2D& operator=(const Vector2D& rhs)
        {
            X = rhs.X;
            Y = rhs.Y;

            return *this;
        }

        Vector2D& operator=(Vector2D&& rhs)
        {
            X = std::move(rhs.X);
            Y = std::move(rhs.Y);

            rhs.X = 0;
            rhs.Y = 0;

            return *this;
        }

        Vector2D& operator+=(const Vector2D& rhs)
        {
            X += rhs.X;
            Y += rhs.Y;

            return *this;
        }

        Vector2D& operator+=(const T rhs)
        {
            X += rhs;
            Y += rhs;

            return *this;
        }

        Vector2D& operator-=(const Vector2D& rhs)
        {
            X -= rhs.X;
            Y -= rhs.Y;

            return *this;
        }

        Vector2D& operator-=(const T rhs)
        {
            X -= rhs;
            Y -= rhs;

            return *this;
        }

        Vector2D& operator*=(const Vector2D& rhs)
        {
            X *= rhs.X;
            Y *= rhs.Y;

            return *this;
        }

        Vector2D& operator*=(const T rhs)
        {
            X *= rhs;
            Y *= rhs;

            return *this;
        }

        Vector2D& operator/=(const Vector2D& rhs)
        {
            X /= rhs.X;
            Y /= rhs.Y;

            return *this;
        }

        Vector2D& operator/=(const T rhs)
        {
            X /= rhs;
            Y /= rhs;

            return *this;
        }

        T X;

        T Y;
    };
}