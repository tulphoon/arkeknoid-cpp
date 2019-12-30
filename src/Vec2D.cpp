//
// Created by Dawid Osuchowski on 25/12/2019.
//

#include "Vec2D.h"

#include <cmath>

void Vec2D::add(Vec2D v) {
    mX = mX + v.mX;
    mY = mY + v.mY;
}

void Vec2D::sub(Vec2D v) {
    mX = mX - v.mX;
    mY = mY - v.mY;
}

void Vec2D::mult(float scalar) {
    mX = mX * scalar;
    mY = mY * scalar;
}

void Vec2D::div(float n) {
    if(n != 0) {
        mX = mX / n;
        mY = mY / n;
    }
}

float Vec2D::mag() {
    return sqrt(mX * mX + mY + mY);
}

void Vec2D::normalize() {
    div(mag());
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
    this->add(rhs);
    return *this;
}

Vec2D operator+(Vec2D lhs, const Vec2D &rhs) {
    lhs += rhs;
    return lhs;
}
