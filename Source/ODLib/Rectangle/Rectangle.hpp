#pragma once

namespace ODLib
{
    template<typename T>
    class Rectangle
    {
    public:

        Rectangle() = default;

        Rectangle(const T Width, const T Height)
            : Width(Width)
            , Height(Height)
        {
        }

        Rectangle(const Rectangle& Rectangle)
            : Width(Rectangle.Width)
            , Height(Rectangle.Height)
        {
        }

        Rectangle(Rectangle&& Rectangle)
            : Width(std::move(Rectangle.Width))
            , Height(std::move(Rectangle.Height))
        {
            Rectangle.Width = 0;
            Rectangle.Height = 0;
        }

        ~Rectangle() = default;

        bool operator==(const Rectangle<T>& rhs) const
        {
            return Width == rhs.Width && Height == rhs.Height;
        }

        bool operator!=(const Rectangle<T>& rhs) const
        {
            return Width != rhs.Width || Height != rhs.Height;
        }

        bool operator<(const Rectangle<T>& rhs) const
        {
            return Width < rhs.Width && Height < rhs.Height;
        }

        bool operator>(const Rectangle<T>& rhs) const
        {
            return Width > rhs.Width && Height > rhs.Height;
        }

        bool operator<=(const Rectangle<T>& rhs) const
        {
            return Width <= rhs.Width && Height <= rhs.Height;
        }

        bool operator>=(const Rectangle<T>& rhs) const
        {
            return Width >= rhs.Width && Height >= rhs.Height;
        }

        float operator[](int32_t IndeWidth) const
        {
            return IndeWidth == 0 ? Width : Height;
        }

        Rectangle operator+(const Rectangle& rhs) const
        {
            return Rectangle<T>(Width + rhs.Width, Height + rhs.Height);
        }

        Rectangle operator+(const T rhs) const
        {
            return Rectangle<T>(Width + rhs, Height + rhs);
        }

        Rectangle operator-() const
        {
            return Rectangle<T>(-Width, -Height);
        }

        Rectangle operator-(const Rectangle& rhs) const
        {
            return Rectangle<T>(Width - rhs.Width, Height - rhs.Height);
        }

        Rectangle operator-(const T rhs) const
        {
            return Rectangle<T>(Width - rhs, Height - rhs);
        }

        Rectangle operator*(const Rectangle& rhs) const
        {
            return Rectangle<T>(Width * rhs.Width, Height * rhs.Height);
        }

        Rectangle operator*(const T rhs) const
        {
            return Rectangle<T>(Width * rhs, Height * rhs);
        }

        Rectangle operator/(const Rectangle& rhs) const
        {
            return Rectangle<T>(Width / rhs.Width, Height / rhs.Height);
        }

        Rectangle operator/(const T rhs) const
        {
            return Rectangle<T>(Width / rhs, Height / rhs);
        }

        Rectangle& operator=(const Rectangle& rhs)
        {
            Width = rhs.Width;
            Height = rhs.Height;

            return *this;
        }

        Rectangle& operator=(Rectangle&& rhs)
        {
            Width = std::move(rhs.Width);
            Height = std::move(rhs.Height);

            rhs.Width = 0;
            rhs.Height = 0;

            return *this;
        }

        Rectangle& operator+=(const Rectangle& rhs)
        {
            Width += rhs.Width;
            Height += rhs.Height;

            return *this;
        }

        Rectangle& operator+=(const T rhs)
        {
            Width += rhs;
            Height += rhs;

            return *this;
        }

        Rectangle& operator-=(const Rectangle& rhs)
        {
            Width -= rhs.Width;
            Height -= rhs.Height;

            return *this;
        }

        Rectangle& operator-=(const T rhs)
        {
            Width -= rhs;
            Height -= rhs;

            return *this;
        }

        Rectangle& operator*=(const Rectangle& rhs)
        {
            Width *= rhs.Width;
            Height *= rhs.Height;

            return *this;
        }

        Rectangle& operator*=(const T rhs)
        {
            Width *= rhs;
            Height *= rhs;

            return *this;
        }

        Rectangle& operator/=(const Rectangle& rhs)
        {
            Width /= rhs.Width;
            Height /= rhs.Height;

            return *this;
        }

        Rectangle& operator/=(const T rhs)
        {
            Width /= rhs;
            Height /= rhs;

            return *this;
        }

        T Width;

        T Height;
    };
}