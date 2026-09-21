/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_QUATERNION_HPP
#define BNT3D_QUATERNION_HPP

#include <cmath>

namespace bnt3d {

/**
 * @brief The QUATERNION class
 */
class QUATERNION
{
public:
    
    float x, y, z, w;
    
    /**
     * @brief QUATERNION
     */
    QUATERNION()
    {
        Identity();
    }
    
    /**
     * @brief Identity creates the identity quaternion.
     * @return
     */
    void Identity()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }

    /**
     * @brief Normalize normalizes the quaternion.
     * @return
     */
    void Normalize()
    {
        float length_sq = QUATERNION::Dot(this, this);
        
        if (length_sq > 0.0f) {
            float length = sqrtf(length_sq);
            x /= length;
            y /= length;
            z /= length;
            w /= length;
        } else {
            Identity();
        }
    }
    
    /**
     * @brief RotationAxis creates a quaternion given an axis and an angle.
     * @param pV
     * @param alpha
     * @return
     */
    void RotationAxis(const VECTOR3 * pV, float alpha)
    {
        alpha /= 2.0f;
        
        float sinAlpha = sinf(alpha);
        
        x = (sinAlpha * pV->x);
        y = (sinAlpha * pV->y);
        z = (sinAlpha * pV->z);
        w = cosf(alpha);
    }
    
    /**
     * @brief RotationVec3toVec3 calculates a quaternion for rotating from vector pV0 to vector pV1
     * @param pV0
     * @param pV1
     * @return
     */
    void RotationVec3toVec3(const VECTOR3 * pV0, const VECTOR3 * pV1)
    {
        float cosAlpha = VECTOR3::Dot(pV0, pV1);
        
        if (fabsf(cosAlpha) < 1.0f) {
            
            VECTOR3 axis;
            VECTOR3::Cross(&axis, pV0, pV1);
            axis.Normalize();
            
            float alpha = acosf(cosAlpha);
            
            RotationAxis(&axis, alpha);
            
        } else {
            Identity();
        }
    }
    
    /**
     * @brief Dot evaluates dot product between quaternions.
     * @param pQ1
     * @param pQ2
     * @return
     */
    static float Dot(const QUATERNION *pQ1, const QUATERNION *pQ2)
    {
        return (pQ1->x * pQ2->x + pQ1->y * pQ2->y + pQ1->z * pQ2->z + pQ1->w * pQ2->w);
    }
    
    /**
     * @brief QuaternionSlerp performs spherical interpolation.
     * @param pOut
     * @param pQ1
     * @param pQ2
     * @param t
     * @return
     */
    static QUATERNION* QuaternionSlerp(QUATERNION *pOut, const QUATERNION *pQ1, const QUATERNION *pQ2, float t)
    {
        #ifdef POINTER_CHECK
            if (pOut == NULL) {
                pOut = new QUATERNION();
            }
        #endif
        
        float dot = QUATERNION::Dot(pQ1, pQ2);
        
        if (dot < 0.0f) {
            q2.x = -q2.x;
            q2.y = -q2.y;
            q2.z = -q2.z;
            q2.w = -q2.z;
            dot = -dot;
        }
        
        if (dot < 1.0f) {
            float theta = acosf(dot);
            
            float sinTheta = sinf(theta);
            
            float t1 = sinf((1.0f - t) * theta) / sinTheta;
            float t2 = sinf(t * theta) / sinTheta;
            
            pOut->x = pQ1->x * t1 + pQ2->x * t2;
            pOut->y = pQ1->y * t1 + pQ2->y * t2;
            pOut->z = pQ1->z * t1 + pQ2->z * t2;
            pOut->w = pQ1->w * t1 + pQ2->w * t2;
        } else {
            pOut->x = pQ1->x + t * (pQ2->x - pQ1->x);
            pOut->y = pQ1->y + t * (pQ2->y - pQ1->y);
            pOut->z = pQ1->z + t * (pQ2->z - pQ1->z);
            pOut->w = pQ1->w + t * (pQ2->w - pQ1->w);

        }
        
        pOut->Normalize();
        
        return pOut;
    }
};

}

#endif //BNT3D_QUATERNION_HPP
