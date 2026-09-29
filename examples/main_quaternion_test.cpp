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

int main(int argc, char **argv)
{
    std::printf("Create a quaternion - axis (0,1,0) angle PI/4");
    QUATERNION q;
    VECTOR3 pV(0.0f, 1.0f, 0.0f);
    pV.Normalize();
    q.RotationAxis(&pV, C_PI / 4.0f);
    q.Print();
    
    std::printf("Convert the quaternion into a matrix");
    MATRIX4 mtx_q;
    mtx_q.FromQuaternion(&q);
    mtx_q.Print();
    
    std::printf("Convert the matrix back to a quanternion");
    QUATERNION q_b;
    mtx_q.ToQuaternion(&q_b);
    q_b.Print();
    
    return 0;
}
