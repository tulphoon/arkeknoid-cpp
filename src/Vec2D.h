//
// Created by Dawid Osuchowski on 25/12/2019.
//

#ifndef ARKEKNOID_CPP_VEC2D_H
#define ARKEKNOID_CPP_VEC2D_H


class Vec2D {
    float mX;
    float mY;
public:
    Vec2D(float x, float y) : mX(x), mY(y) {}

    void add(Vec2D v);
    void sub(Vec2D v);
    void mult(float scalar);
    void div(float n);
    float mag();
    void normalize();
};


#endif //ARKEKNOID_CPP_VEC2D_H
