#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <math.h>

class Vector2D
{
private:
    float x;
    float y;

public:
    Vector2D(float x, float y);

    float length();

    // vector additions
    Vector2D operator+(const Vector2D &other) const;
    friend Vector2D &operator+=(Vector2D &v1, const Vector2D &v2);

    // vector subtraction
    Vector2D operator-(const Vector2D &other) const;
    friend Vector2D &operator-=(Vector2D &v1, const Vector2D &v2);

    // vector multiplication
    Vector2D operator*(float scalar) const;
    friend Vector2D &operator*=(Vector2D &v1, float scalar);

    // vector division
    Vector2D operator/(float scalar) const;
    friend Vector2D &operator/=(Vector2D &v1, float scalar);

    // normalize
    void normalize();

    // getters
    float getX() const;
    float getY() const;
    // setters
    void setX(float x);
    void setY(float y);
};

#endif