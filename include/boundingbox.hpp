/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_BOUNDINGBOX_HPP
#define BNT3D_BOUNDINGBOX_HPP

#include "vector3.hpp"
#include "matrix4.hpp"

namespace bnt3d {

/**
 * @brief ExtendBBox computes a bounding box (bMax,bMin) is expanded according to p.
 * @param bMax
 * @param bMin
 * @param p
 */
INLINE void ExtendBBox(VECTOR3 *bMax, VECTOR3 *bMin, const VECTOR3 *p)
{
    bMin->x = MIN(p->x, bMin->x);
    bMin->y = MIN(p->y, bMin->y);
    bMin->z = MIN(p->z, bMin->z);
    
    bMax->x = MAX(p->x, bMax->x);
    bMax->y = MAX(p->y, bMax->y);
    bMax->z = MAX(p->z, bMax->z);
}

/**
 * @brief MinBBox calculates the minimum box.
 * @param max
 * @param min
 * @param bMax
 * @param bMin
 */
INLINE void MinBBox(VECTOR3 *max, VECTOR3 *min, const VECTOR3 *bMax, const VECTOR3 *bMin)
{
    if (bMin->x > min->x) min->x = bMin->x;
    if (bMin->y > min->y) min->y = bMin->y;
    if (bMin->z > min->z) min->z = bMin->z;
    
    if (bMax->x < max->x) max->x = bMax->x;
    if (bMax->y < max->y) max->y = bMax->y;
    if (bMax->z < max->z) max->z = bMax->z;
}

/**
 * @brief CheckPointBBox checks if a point p is in a bounding box (bMax,bMin).
 * @param bMax
 * @param bMin
 * @param p
 * @return
 */
INLINE bool CheckPointBBox(const VECTOR2 *bMax, const VECTOR2 *bMin, const VECTOR2 *p)
{
    return ((p->x >= bMin->x) &&
            (p->y >= bMin->y) &&
            (p->x <= bMax->x) &&
            (p->y <= bMax->y));
}

/**
 * @brief CheckPointBBox checks if a point p is in a bounding box (bMax, bMin).
 * @param bMax is the maximum of the input bounding box.
 * @param bMin is the minimum of the input bounding box.
 * @param p is an input point.
 * @return It returns true if the p is inside the bounding box, false otherwise.
 */
INLINE bool CheckPointBBox(const VECTOR3 *bMax, const VECTOR3 *bMin, const VECTOR3 *p)
{
    return ((p->x >= bMin->x) &&
            (p->y >= bMin->y) &&
            (p->z >= bMin->z) &&
            (p->x <= bMax->x) &&
            (p->y <= bMax->y) &&
            (p->z <= bMax->z));
}

/**
 * @brief CheckPointBBoxLength checks if a point p is in a bounding box defined by its center and its length.
 * @param bCenter is the center of the bounding box.
 * @param bRadius is the lenght of the box for each directions.
 * @param p is an input point.
 * @return It returns true if the p is inside the bounding box, false otherwise.
 */
INLINE bool CheckPointBBoxLength(const VECTOR3 &bCenter, const float bRadius, const VECTOR3 &p)
{
    return (p.x >= (bCenter.x - bRadius)) && (p.x <= (bCenter.x + bRadius)) &&
           (p.y >= (bCenter.y - bRadius)) && (p.y <= (bCenter.y + bRadius)) &&
           (p.z >= (bCenter.z - bRadius)) && (p.z <= (bCenter.z + bRadius));
}

/**
 * @brief CheckPlaneBBox checks if a plane (nor, d) intersects a bounding box (bMax,bMin).
 * @param bMax is the maximum of the input bounding box.
 * @param bMin is the minimum of the input bounding box.
 * @param nor is the normal of the input plane.
 * @param d is the distance of the input plane.
 * @return It returns true if the bounding box intersects the plane , false otherwise.
 */
INLINE bool CheckPlaneBBox(const VECTOR3 *bMax, const VECTOR3 *bMin,
                           const VECTOR3 *nor, float d)
{
    
    VECTOR3 vMax, vMin;
    for (int i = 0; i < 3; i++) {
        if ((*nor)[i] > 0.0f) {
            vMax[i] = (*bMax)[i];
            vMin[i] = (*bMin)[i];
        }
        else {
            vMax[i] = (*bMin)[i];
            vMin[i] = (*bMax)[i];
        }
    }
    
    if ((VECTOR3::Dot(nor, &vMax) + d) < 0.0f) {
        return false;
    }
    
    if ((VECTOR3::Dot(nor, &vMin) + d) > 0.0f) {
        return false;
    } else {
        return true;
    }
}

/**
 * @brief BBoxFromSphere computes bounding box froma a sphere.
 * @param center is the center of the sphere.
 * @param radius is the radius of the sphere.
 * @param bMax is the maximum of the output bounding box.
 * @param bMin is the minimum of the output bounding box.
 */
INLINE void BBoxFromSphere(const VECTOR3 *center, float radius,
                               VECTOR3 *bMax, VECTOR3 *bMin)
{
    VECTOR3 rVec = VECTOR3(radius, radius, radius);
    *bMax = *center + rVec;
    *bMin = *center - rVec;
}

/**
 * @brief BBoxFromTri computes bounding box from a triangle.
 * @param v0 is the first vertex in the triangle.
 * @param v1 is the second vertex in the triangle.
 * @param v2 is the third vertex in the triandle.
 * @param bMax is the maximum of the output bounding box.
 * @param bMin is the minimum of the output bounding box.
 */
INLINE void BBoxFromTri(const VECTOR3 *v0, const VECTOR3 *v1, const VECTOR3 *v2,
                              VECTOR3 *bMax, VECTOR3 *bMin)
{
    
    bMax->x = v0->x;
    bMax->y = v0->y;
    bMax->z = v0->z;
    
    bMin->x = v0->x;
    bMin->y = v0->y;
    bMin->z = v0->z;
    
    //Min X
    bMin->x = bMin->x > v1->x ? v1->x : bMin->x;
    bMin->x = bMin->x > v2->x ? v2->x : bMin->x;
    //Min Y
    bMin->y = bMin->y > v1->y ? v1->y : bMin->y;
    bMin->y = bMin->y > v2->y ? v2->y : bMin->y;
    //Min Z
    bMin->z = bMin->z > v1->z ? v1->z : bMin->z;
    bMin->z = bMin->z > v2->z ? v2->z : bMin->z;
    
    //Max X
    bMax->x = bMax->x < v1->x ? v1->x : bMax->x;
    bMax->x = bMax->x < v2->x ? v2->x : bMax->x;
    //Max Y
    bMax->y = bMax->y < v1->y ? v1->y : bMax->y;
    bMax->y = bMax->y < v2->y ? v2->y : bMax->y;
    //Max Z
    bMax->z = bMax->z < v1->z ? v1->z : bMax->z;
    bMax->z = bMax->z < v2->z ? v2->z : bMax->z;
}

/**
 * @brief CheckBBoxBBox checks if two bounding boxes overlaps.
 * @param aMax is the maximum of the bounding box A
 * @param aMin is the minimum of the bounding box A
 * @param bMax is the maximum of the bounding box B
 * @param bMin is the minimum of the bounding box B
 * @return
 */
INLINE bool CheckBBoxBBox(const VECTOR3 *aMax, const VECTOR3 *aMin,
                          const VECTOR3 *bMax, const VECTOR3 *bMin)
{
    //X axis
    if (aMin->x > bMin->x) {
        if (aMin->x > bMax->x) {
            return false;
        }
    }
    else {
        if (bMin->x > aMax->x) {
            return false;
        }
    }
    
    //Y axis
    if (aMin->y > bMin->y) {
        if (aMin->y > bMax->y) {
            return false;
        }
    }
    else {
        if (bMin->y > aMax->y) {
            return false;
        }
    }
    
    //Z axis
    if (aMin->z > bMin->z) {
        if (aMin->z > bMax->z) {
            return false;
        }
    }
    else {
        if (bMin->z > aMax->z) {
            return false;
        }
    }
    
    return true;
}

/**
 * @brief AreaBBox calculates the area of the bounding box.
 * @param bMax is the maximum of the bounding box
 * @param bMin is the minimum of the bounding box
 * @return
 */
INLINE float AreaBBox(const VECTOR3 *bMax, const VECTOR3 *bMin)
{
    float dx = bMax->x - bMin->x;
    float dy = bMax->y - bMin->y;
    float dz = bMax->z - bMin->z;
    
    return 2.0f * (dx * dy + dy * dz + dz * dx);
}

/**
 * @brief CheckSphereSphere
 * @param c0 is the center of sphere 0
 * @param c1 is the center of sphere 1
 * @param r0 is the radius of sphere 0
 * @param r1 is the radius of sphere 1
 * @return
 */
INLINE bool CheckSphereSphere(const VECTOR3 *c0, const VECTOR3 *c1, float r0, float r1)
{
    return (VECTOR3::Distance(c0, c1) <= (r0 + r1));
}

/**
 * @brief CheckSphereBBox
 * @param bMax is the maximum of the bounding box
 * @param bMin is the minimum of the bounding box
 * @param sph_center is the sphere's center
 * @param sph_radius_sq is the squared sphere's radius
 * @return
 */
INLINE bool CheckSphereBBox(const VECTOR3 *bMax, const VECTOR3 *bMin,
                            const VECTOR3 *sph_center, float sph_radius_sq)
{
    float dmin = 0.0f;
    for (int i = 0; i < 3; i++) {
        if ((*sph_center)[i] < (*bMin)[i]) {
            float tmp = (*sph_center)[i] - (*bMin)[i];
            dmin += tmp * tmp;
        }
        else {
            if ((*sph_center)[i] > (*bMax)[i]) {
                float tmp = (*sph_center)[i] - (*bMax)[i];
                dmin += tmp * tmp;
            }
        }
    }
    
    return (dmin <= (sph_radius_sq));
}

/**
 * @brief ClosestCube computes the closest cube from a starting bounding box (bMax,bMin).
 * @param bMax
 * @param bMin
 * @param aMax
 * @param aMin
 */
INLINE void ClosestCube(const VECTOR3 *bMax, const VECTOR3 *bMin, VECTOR3 *aMax, VECTOR3 *aMin)
{
    VECTOR3 len = *bMax - *bMin;
    float maxLen = MAX(MAX(len.x, len.y), len.z) / 2.0f + 1e-6f;
    VECTOR3 c = (*bMax + *bMin) / 2.0f;
    
    len = VECTOR3(maxLen, maxLen, maxLen);
    
    *aMax = c + len;
    *aMin = c - len;
    
    //*aMax = VECTOR3(1.0f, 1.0f, 1.0f);
    //*aMin = VECTOR3(-1.0f, -1.0f, -1.0f);
}

/**
 * @brief BBoxClamp
 * @param max
 * @param min
 * @param p
 */
INLINE void BBoxClamp(const VECTOR3 *max, const VECTOR3 *min, VECTOR3 *p)
{
    p->x = (p->x < min->x) ? min->x : p->x;
    p->y = (p->y < min->y) ? min->y : p->y;
    p->z = (p->z < min->z) ? min->z : p->z;
    
    p->x = (p->x > max->x) ? max->x : p->x;
    p->y = (p->y > max->y) ? max->y : p->y;
    p->z = (p->z > max->z) ? max->z : p->z;
}

/**
 * @brief BBoxLocal
 * @param max
 * @param min
 * @param p
 */
INLINE void BBoxLocal(const VECTOR3 *max, const VECTOR3 *min, VECTOR3 *p)
{
    VECTOR3 len = *max - *min;
    *p = (*p - *min) / len;
}

/**
 * @brief BBoxApplyTransform
 * @param bbox
 * @param transform
 * @param bboxOut
 */
INLINE void BBoxApplyTransform(const VECTOR3 *bMax, const VECTOR3 *bMin, const MATRIX4 *transform,
                                     VECTOR3 *pMax, VECTOR3 *pMin)
{
    VECTOR3 frame[8];
    frame[0] = *bMin;
    frame[1] = VECTOR3(bMax->x, bMin->y, bMax->z);
    frame[2] = VECTOR3(bMin->x, bMin->y, bMax->z);
    frame[3] = VECTOR3(bMax->x, bMin->y, bMin->z);
    
    frame[4] = *bMax;
    frame[5] = VECTOR3(bMin->x, bMax->y, bMin->z);
    frame[6] = VECTOR3(bMin->x, bMax->y, bMax->z);
    frame[7] = VECTOR3(bMax->x, bMax->y, bMin->z);
    
    for (int i = 0; i < 8; i++) {
        VECTOR3 tmp;
        transform->TransformCoord(&tmp, &frame[i]);
        frame[i] = tmp;
    }
    
    *pMax = frame[0];
    *pMin = frame[0];
    
    for (int i = 1; i < 8; i++) {
        ExtendBBox(pMax, pMin, &frame[i]);
    }
}

/**
 * @brief BBoxClampLocal
 * @param max
 * @param min
 * @param p
 */
INLINE void BBoxClampLocal(const VECTOR3 *max, const VECTOR3 *min, VECTOR3 *p)
{
    BBoxClamp(max, min, p);
    BBoxLocal(max, min, p);
}

/**
 * @brief Bool2Ind
 * @param x
 * @param y
 * @param z
 * @return
 */
INLINE int Bool2Ind(bool x, bool y, bool z)
{
    return (x << 0) + (y << 1) + (z << 2);
}

/**
 * @brief Ind2Bool
 * @param ind
 * @param pos
 * @return
 */
INLINE bool Ind2Bool(int ind, int pos)
{
    return (ind >> pos) & 0x1;
}

/**
 * @brief BoxOctant calculates an octant of a box.
 * @param max
 * @param min
 * @param maxOut
 * @param minOut
 * @param ind
 */
INLINE void BoxOctant(VECTOR3 *max, VECTOR3 *min, VECTOR3 *maxOut, VECTOR3 *minOut, int ind)
{
    for (int i = 0; i < 3; i++) {
        if (Ind2Bool(ind, i)) {
            (*maxOut)[i] = ((*max)[i] + (*min)[i]) / 2.0f;
            (*minOut)[i] = (*min)[i];
        }
        else {
            (*maxOut)[i] = (*max)[i];
            (*minOut)[i] = ((*max)[i] + (*min)[i]) / 2.0f;
        }
    }
}

/**
 * @brief ShiftOctant calculates an octant shift vector.
 * @param pOut
 * @param ind
 * @return
 */
INLINE VECTOR3 *ShiftOctant(VECTOR3 *pOut, int ind)
{
    for (int i = 0; i < 3; i++) {
        if (Ind2Bool(ind, i)) {
            (*pOut)[i] = -1.0f;
        }
        else {
            (*pOut)[i] = 1.0f;
        }
    }
    
    return pOut;
}

}

#endif //BNT3D_BOUNDINGBOX_HPP
