/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_COORDSYS_HPP
#define BNT3D_COORDSYS_HPP

#include <math.h>

#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix2.hpp"

namespace  bnt3d {

#define COORDSYS_EPSILON 1e-6f

/**
 * @brief CreateOrthoNormalBase create an orthonormal base from a vector (n).
 * @param n
 * @param u
 * @param v
 */
INLINE void CreateOrthoNormalBase(const VECTOR3 *n, VECTOR3 *u, VECTOR3 *v)
{
    if (fabsf(n->z) > COORDSYS_EPSILON) {
        v->x = 0.0f;
        v->y = n->z;
        v->z = -n->y;
    }
    else {
        if (fabsf(n->x) > COORDSYS_EPSILON) {
            v->x = n->z;
            v->y = 0.0f;
            v->z = -n->x;
        }
        else {
            v->x = n->y;
            v->y = 0.0f;
            v->z = 0.0f;
        }
    }
    
    v->Normalize();
    VECTOR3::Cross(u, v, n);
    
    //NOTE: This should not be required
    u->Normalize();
}

/**
 * @brief BaseProjection projects onto a base.
 * @param pOut
 * @param V0
 * @param V1
 * @param V2
 * @param pV
 * @return
 */
INLINE VECTOR3 *BaseProjection(       VECTOR3 *pOut,
                                const VECTOR3 *V0,
                                const VECTOR3 *V1,
                                const VECTOR3 *V2,
                                const VECTOR3 *pV)
{
#ifdef POINTER_CHECK
    if (pOut == NULL) {
        pOut = new VECTOR3();
    }
#endif
    
    pOut->x = VECTOR3::Dot(V0, pV);
    pOut->y = VECTOR3::Dot(V1, pV);
    pOut->z = VECTOR3::Dot(V2, pV);
    
    return pOut;
}

/**
 * @brief BaseApply applies a base.
 * @param V0
 * @param V1
 * @param V2
 * @param pV
 * @param pOut
 * @return
 */
INLINE VECTOR3 *BaseApply(      VECTOR3 *pOut,
                          const VECTOR3 *V0,
                          const VECTOR3 *V1,
                          const VECTOR3 *V2,
                          const VECTOR3 *pV)
{
#ifdef _POINTER_CHECK
    if (pOut == NULL) {
        pOut = new VECTOR3();
    }
#endif
    
    *pOut = (*V0) * pV->x +
            (*V1) * pV->y +
            (*V2) * pV->z;
    
    return pOut;
}

}

#endif //BNT3D_COORDSYS_HPP
