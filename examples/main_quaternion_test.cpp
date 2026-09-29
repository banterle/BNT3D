/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#include <stdio.h>

#include "include/bnt3d.hpp"

using namespace bnt3d;

void test(VECTOR3 axis, float angle)
{
    std::printf("Create a quaternion");
    QUATERNION q;
    axis.Normalize();
    q.RotationAxis(&axis, angle);
    q.Print();
    
    std::printf("Convert the quaternion into a matrix");
    MATRIX4 mtx_q;
    mtx_q.FromQuaternion(&q);
    mtx_q.Print();
    
    std::printf("Convert the matrix back to a quanternion");
    QUATERNION q_b;
    mtx_q.ToQuaternion(&q_b);
    q_b.Print();
}

int main(int argc, char **argv)
{
    test(VECTOR3(0.0f, 1.0f, 0.0f), C_PI / 4.0f);
    test(VECTOR3(1.0f, 0.0f, 0.0f), C_PI * 5.0f / 6.0f);
    test(VECTOR3(0.0f, 1.0f, 0.0f), C_PI * 5.0f / 6.0f);
    test(VECTOR3(0.0f, 0.0f, 1.0f), C_PI * 5.0f / 6.0f);
    return 0;
}
