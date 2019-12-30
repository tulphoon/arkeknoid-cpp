//
// Created by Dawid Osuchowski on 25/12/2019.
//

#ifndef ARKEKNOID_CPP_VEC2D_H
#define ARKEKNOID_CPP_VEC2D_H


class Vec2D {
    float mX;
    float mY;
public:
    Vec2D() : mX(0), mY(0) {}
    Vec2D(float x, float y) : mX(x), mY(y) {}

    Vec2D &operator +=(const Vec2D &rhs);

    friend Vec2D operator+(Vec2D lhs, const Vec2D &rhs);

    Vec2D operator*(const double &rhs);

    Vec2D operator/(const float &rhs);

    bool operator==(const Vec2D &rhs) const;

    bool operator!=(const Vec2D &rhs) const;

    bool operator<(const Vec2D &rhs) const;

    bool operator>(const Vec2D &rhs) const;

    bool operator<=(const Vec2D &rhs) const;

    bool operator>=(const Vec2D &rhs) const;

    float magnitude();
    Vec2D normalized();

    float getX() const;

    float getY() const;
};


#endif //ARKEKNOID_CPP_VEC2D_H
