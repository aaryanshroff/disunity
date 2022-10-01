#include "vector.h"

// ctor
Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2D::length()
{
    return sqrt(x * x + y * y);
}

// vector additions
Vector2D Vector2D::operator+(const Vector2D &other) const
{
    return Vector2D(x + other.x, y + other.y);
}

Vector2D &operator+=(Vector2D &v1, const Vector2D &v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
}

// vector subtraction
Vector2D Vector2D::operator-(const Vector2D &other) const
{
    return Vector2D(x - other.x, y - other.y);
}

Vector2D &operator-=(Vector2D &v1, const Vector2D &v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
}

// vector multiplication
Vector2D Vector2D::operator*(float scalar) const
{
    return Vector2D(x * scalar, y * scalar);
}

Vector2D &operator*=(Vector2D &v1, float scalar)
{
    v1.x *= scalar;
    v1.y *= scalar;
    return v1;
}

// vector division
Vector2D Vector2D::operator/(float scalar) const
{
    return Vector2D(x / scalar, y / scalar);
}

Vector2D &operator/=(Vector2D &v1, float scalar)
{
    v1.x /= scalar;
    v1.y /= scalar;
    return v1;
}

// normalize
void Vector2D::normalize()
{
    float l = length();
    if (l > 0)
    {
        (*this) *= 1 / l;
    }
}

// getters

float Vector2D::getX() const
{
    return x;
}

float Vector2D::getY() const
{
    return y;
}

void Vector2D::setX(float x)
{
    this->x = x;
}

void Vector2D::setY(float y)
{
    this->y = y;
}