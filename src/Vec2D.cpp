//
// Created by Dawid Osuchowski on 25/12/2019.
//

#include "Vec2D.h"

#include <cmath>

float Vec2D::magnitude() {
    return sqrt(mX * mX + mY + mY);
}

Vec2D Vec2D::normalized() {
    float m = magnitude();
    return *(this)/m;
}

float Vec2D::getX() const {
    return mX;
}

float Vec2D::getY() const {
    return mY;
}

bool Vec2D::operator==(const Vec2D &rhs) const {
    return mX == rhs.mX &&
           mY == rhs.mY;
}

bool Vec2D::operator!=(const Vec2D &rhs) const {
    return !(rhs == *this);
}

bool Vec2D::operator<(const Vec2D &rhs) const {
    if (mX < rhs.mX)
        return true;
    if (rhs.mX < mX)
        return false;
    return mY < rhs.mY;
}

bool Vec2D::operator>(const Vec2D &rhs) const {
    return rhs < *this;
}

bool Vec2D::operator<=(const Vec2D &rhs) const {
    return !(rhs < *this);
}

bool Vec2D::operator>=(const Vec2D &rhs) const {
    return !(*this < rhs);
}

Vec2D &Vec2D::operator+=(const Vec2D &rhs) {
    mX += rhs.mX;
    mY += rhs.mY;
    return *this;
}

Vec2D operator+(Vec2D lhs, const Vec2D &rhs) {
    lhs += rhs;
    return lhs;
}

Vec2D &Vec2D::operator-=(const Vec2D &rhs) {
    mX -= rhs.mX;
    mY -= rhs.mY;
    return *this;
}

Vec2D Vec2D::operator*(const double &rhs) {
    Vec2D tmp {static_cast<float>(this->mX * rhs), static_cast<float>(this->mY * rhs)};
    return tmp;
}

Vec2D Vec2D::operator/(const float &rhs) {
    return Vec2D(mX / rhs, mY / rhs);
}

void Vec2D::setX(float mX) {
    Vec2D::mX = mX;
}

void Vec2D::setY(float mY) {
    Vec2D::mY = mY;
}
