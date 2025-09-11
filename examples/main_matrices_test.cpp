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
    std::printf("Create a rotation matrix, mtx, on the X-axis");
    MATRIX4 mtx;
    mtx.RotateX(0.15f);
    mtx.Print();
    
    std::printf("Compute its inverse, mtx_inv");
    MATRIX4 mtx_inv;
    mtx.Inverse(&mtx_inv);
    mtx_inv.Print();
    
    std::printf("Multiply mtx times mtx_inv");
    MATRIX4 check;
    MATRIX4::Multiply(&check, &mtx, &mtx_inv);
    
    check.Print();
    
    std::printf("Compute the transpose of mtx, mtx_t");
    MATRIX4 mtx_t;
    mtx.Transpose(&mtx_t);
    mtx_t.Print();
    
    std::printf("Multiply mtx times mtx_t");
    MATRIX4 check_t;
    MATRIX4::Multiply(&check_t, &mtx, &mtx_t);
    check_t.Print();
    
    return 0;
}
