/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_GEOMETRY_HPP
#define BNT3D_GEOMETRY_HPP

#include <math.h>

#include "vector3.hpp"

namespace bnt3d {

/**
 * @brief TriangleNormal computes the normal of a triangle with normalization.
 * @param pOut is the output normal.
 * @param p1 is the first vertex position of the triangle.
 * @param p2 is the second vertex position of the triangle.
 * @param p3 is the third vertex position of the triangle.
 * @return It returns the normal of the triangle (p1, p2, p3).
 */
INLINE VECTOR3 *TriangleNormal(VECTOR3 *pOut, const VECTOR3 *p1, const VECTOR3 *p2, const VECTOR3 *p3)
{
    #ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR3();
        }
    #endif

    VECTOR3 a, b;
    a.x = p1->x - p2->x;
    a.y = p1->y - p2->y;
    a.z = p1->z - p2->z;
    
    b.x = p2->x - p3->x;
    b.y = p2->y - p3->y;
    b.z = p2->z - p3->z;
    
    pOut = VECTOR3::Cross(pOut, &a, &b);
    pOut->Normalize();
    return pOut;
}

/**
 * @brief TriangleNormalWithoutNormalization computes the normal of a triangle without normalization.
 * @param pOut is the output normal.
 * @param p1 is the first vertex position of the triangle.
 * @param p2 is the second vertex position of the triangle.
 * @param p3 is the third vertex position of the triangle.
 * @return It returns the normal of the triangle (p1, p2, p3).
 */
INLINE VECTOR3 *TriangleNormalWithoutNormalization(VECTOR3 *pOut, const VECTOR3 *p1, const VECTOR3 *p2, const VECTOR3 *p3)
{
    VECTOR3 a, b;
    a.x = p1->x - p2->x;
    a.y = p1->y - p2->y;
    a.z = p1->z - p2->z;
    
    b.x = p2->x - p3->x;
    b.y = p2->y - p3->y;
    b.z = p2->z - p3->z;
    
    return VECTOR3::Cross(pOut, &a, &b);
}

/**
 * @brief TriangleArea computes the area of a triangle given its verticies.
 * @param v0 is the first vertex position of the triangle.
 * @param v1 is the second vertex position of the triangle.
 * @param v2 is the third vertex position of the triangle.
 * @return
 */
INLINE float TriangleArea(VECTOR3 *v0, VECTOR3 *v1, VECTOR3 *v2)
{
    float v01 = VECTOR3::Distance(v0, v1);
    float v02 = VECTOR3::Distance(v0, v2);
    float v12 = VECTOR3::Distance(v1, v2);
    
    float s = (v01 + v02 + v12) / 2.0f;
    
    float area_sq = s * (s - v01) * (s - v02) * (s - v12);
    return (area_sq > 0.0f) ? sqrtf(area_sq) : 0.0f;
}

/**
 * @brief TriangleArea computes teh area of a triangle given the lengths of its edges.
 * @param v01 is the length of the edge (v0, v1).
 * @param v02 is the length of the edge (v0, v2).
 * @param v12 is the length of the edge (v1, v2).
 * @return
 */
INLINE float TriangleArea(float v01, float v02, float v12)
{
    float s = (v01 + v02 + v12) / 2.0f;
    
    float area_sq = s * (s - v01) * (s - v02) * (s - v12);
    return (area_sq > 0.0f) ? sqrtf(area_sq) : 0.0f;
}

/**
 * @brief DistanceRayPoint computes the distance from a ray to a point.
 * @param rO is the ray origin.
 * @param rD is the ray direction.
 * @param p is the point.
 * @return
 */
INLINE float DistanceRayPoint(const VECTOR3 *rO, const VECTOR3 *rD, const VECTOR3 *p)
{
    VECTOR3 tmp0 = (*rO) - (*p);
    float tmp1 = VECTOR3::Dot(&tmp0, rD);
    VECTOR3 tmp2 = (*rD) * tmp1;
    
    return VECTOR3::Distance(&tmp0, &tmp2);
}

/**
 * @brief DistanceRayPointF computes the distance from a ray to a point.
 * @param rO is the ray origin.
 * @param rD is the ray direction.
 * @param p is the point.
 * @return
 */
INLINE float DistanceRayPointF(const VECTOR3 *rO, const VECTOR3 *rD, const VECTOR3 *p)
{
    VECTOR3 tmp0 = (*p) - (*rO);
    return VECTOR3::Dot(&tmp0, rD);
}

/**
 * @brief Diffuse creates a diffuse vector given random values (u1, u2).
 * @param u1 is a value in [0, 1].
 * @param u2 is a value in [0, 1].
 * @param out
 * @return
 */
INLINE VECTOR3 *Diffuse(VECTOR3 *pOut, float u1, float u2)
{
#ifdef POINTER_CHECK
    if (pOut == NULL) {
        pOut = new VECTOR3();
    }
#endif
    
    float cosTheta = sqrtf(MAX(u1, 0.0f));
    float tmp = 1.0f - cosTheta * cosTheta;
    float sinTheta = tmp > 0.0f ? sqrtf(tmp) : 0.0f;
    
    float phi = C_PI_2 * u2;
    
    pOut->x = sinTheta * cosf(phi);
    pOut->y = cosTheta;
    pOut->z = sinTheta * sinf(phi);
    
    return pOut;
}

/**
 * @brief Reflect reflects a direction (dir) against a normal (nor).
 * @param dir
 * @param nor
 * @param out
 * @return
 */
INLINE VECTOR3 *Reflect(VECTOR3 *pOut, const VECTOR3 *dir, const VECTOR3 *nor)
{
#ifdef POINTER_CHECK
    if (pOut == NULL) {
        pOut = new VECTOR3();
    }
#endif
    
    float dotx = 2.0f * VECTOR3::Dot(nor, dir);
    
    pOut->x = dir->x - dotx * nor->x;
    pOut->y = dir->y - dotx * nor->y;
    pOut->z = dir->z - dotx * nor->z;
    
    pOut->Normalize();
    
    return pOut;
}

/**
 * @brief ReflectNeg reflects a direction (-dir) against a normal (nor).
 * @param dir
 * @param nor
 * @param out
 * @return
 */
INLINE VECTOR3 *ReflectNeg(VECTOR3 *pOut, const VECTOR3 *dir, const VECTOR3 *nor)
{
#ifdef POINTER_CHECK
    if (pOut == NULL) {
        pOut = new VECTOR3();
    }
#endif
    
    float dotx = 2.0f * VECTOR3::Dot(nor, dir);
    
    pOut->x = dotx * nor->x - dir->x;
    pOut->y = dotx * nor->y - dir->y;
    pOut->z = dotx * nor->z - dir->z;
    
    pOut->Normalize();

    return pOut;
}

/**
 * @brief Refract refracts a directionr (dir) against a normal (nor) with (n1, n2).
 * @param dir
 * @param nor
 * @param n1
 * @param n2
 * @param out
 * @return
 */
INLINE bool Refract(VECTOR3 *pOut, const VECTOR3 *dir, const VECTOR3 *nor, float n1, float n2)
{
    VECTOR3 I = (*dir);
    VECTOR3 N = (*nor);
    
    float NdotI = VECTOR3::Dot(&N, &I);
    float eta = n1 / n2;
    
    float k = 1.0f - eta * eta * (1.0f - NdotI * NdotI);
    if (k <= 0.0f) {
#ifdef TOTAL_REFRACTION_OFF
        *pOut = *dir;
        return true;
#else
        Reflect(pOut, &I, &N);
        return false;
#endif
    } else {
        *pOut = I * eta - N * (sqrtf(MAX(k, 0.0f)) + eta * NdotI);
        return true;
    }
}

/**
 * @brief RefractNeg refracts a directionr (-dir) against a normal (nor) with (n1,n2).
 * @param dir
 * @param nor
 * @param n1
 * @param n2
 * @param out
 * @return
 */
INLINE bool RefractNeg(VECTOR3 *pOut, const VECTOR3 *dir, const VECTOR3 *nor, float n1, float n2)
{
    VECTOR3 I = (*dir);
    VECTOR3 N = (*nor);
    
    float NdotI = -VECTOR3::Dot(&N, &I);
    float eta = n1 / n2;
    
    float k = 1.0f - eta * eta * (1.0f - NdotI * NdotI);
    
    if (k <= 0.0f) {
#ifdef TOTAL_REFRACTION_OFF
        *out = *dir;
        return true;
#else
        ReflectNeg(pOut, &I, &N);
        return false;
#endif
    } else {
        *pOut = -I * eta - N * (sqrtf(MAX(k, 0.0f)) + eta * NdotI);
        return true;
    }
}

}

#endif //BNT3D_GEOMETRY_HPP
