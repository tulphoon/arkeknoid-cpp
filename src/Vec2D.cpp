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
