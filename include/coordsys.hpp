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
#ifdef POINTER_CHECK
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
