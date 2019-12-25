//
// Created by Dawid Osuchowski on 25/12/2019.
//

#include "Vec2D.h"

#include <cmath>

void Vec2D::add(Vec2D v) {
    x = x + v.x;
    y = y + v.y;
}

void Vec2D::sub(Vec2D v) {
    x = x - v.x;
    y = y - v.y;
}

void Vec2D::mult(float scalar) {
    x = x * scalar;
    y = y * scalar;
}

void Vec2D::div(float n) {
    if(n != 0) {
        x = x / n;
        y = y / n;
    }
}

float Vec2D::mag() {
    return sqrt(x * x + y + y);
}

void Vec2D::normalize() {
    div(mag());
}
