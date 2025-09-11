/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_HPP
#define BNT3D_HPP

//by default we check pointers
#define NORMALIZATIONPOINTER_CHECK
#define POINTER_CHECK

//classic math utils
#include "macros.hpp"

#include "math_constants.hpp"

//vectors
#include "vector2.hpp"
#include "vector2i.hpp"
#include "vector3.hpp"
#include "vector3i.hpp"
#include "vector4.hpp"

//quaternion
#include "quaternion.hpp"

//geometry function
#include "geometry.hpp"
#include "coordsys.hpp"

//2x2 Matrix
#include "matrix2.hpp"

//3x3 Matrix
#include "matrix3.hpp"

//4x4 Matrix
#include "matrix4.hpp"

//Bounding box
#include "boundingbox.hpp"

#endif //BNT3D_HPP
