/**
*     Copyright (C) 2008-2014  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_MATRIX4_HPP
#define BNT3D_MATRIX4_HPP

#include <cmath>
#include <cstdio>
#include <cstring>

#include "vector3.hpp"
#include "vector4.hpp"
#include "quaternion.hpp"
#include "plane.hpp"

namespace bnt3d {
/**
 * @brief The MATRIX4 class
 */
class MATRIX4
{
public:
    float data[16];
    
    /**
     * @brief MATRIX4
     */
    MATRIX4()
    {
    }
    
    /**
     * @brief operator +=
     * @param pM
     */
    void operator += (const MATRIX4 &pM)
    {
        data[0] += pM.data[0];
        data[1] += pM.data[1];
        data[2] += pM.data[2];
        data[3] += pM.data[3];
        
        data[4] += pM.data[4];
        data[5] += pM.data[5];
        data[6] += pM.data[6];
        data[7] += pM.data[7];
        
        data[8] += pM.data[8];
        data[9] += pM.data[9];
        data[10] += pM.data[10];
        data[11] += pM.data[11];
        
        data[12] += pM.data[12];
        data[13] += pM.data[13];
        data[14] += pM.data[14];
        data[15] += pM.data[15];
    }
    
    /**
     * @brief operator -=
     * @param pM
     */
    void operator -= (const MATRIX4 &pM)
    {
        data[0] -= pM.data[0];
        data[1] -= pM.data[1];
        data[2] -= pM.data[2];
        data[3] -= pM.data[3];
        
        data[4] -= pM.data[4];
        data[5] -= pM.data[5];
        data[6] -= pM.data[6];
        data[7] -= pM.data[7];
        
        data[8] -= pM.data[8];
        data[9] -= pM.data[9];
        data[10] -= pM.data[10];
        data[11] -= pM.data[11];
        
        data[12] -= pM.data[12];
        data[13] -= pM.data[13];
        data[14] -= pM.data[14];
        data[15] -= pM.data[15];
    }
    
    /**
     * @brief operator *=
     * @param v
     */
    void operator *= (float v)
    {
        data[0] *= v;
        data[1] *= v;
        data[2] *= v;
        data[3] *= v;
        
        data[4] *= v;
        data[5] *= v;
        data[6] *= v;
        data[7] *= v;
        
        data[8] *= v;
        data[9] *= v;
        data[10] *= v;
        data[11] *= v;
        
        data[12] *= v;
        data[13] *= v;
        data[14] *= v;
        data[15] *= v;
    }
    
    /**
     * @brief operator /=
     * @param v
     */
    void operator /= (float v)
    {
        data[0] /= v;
        data[1] /= v;
        data[2] /= v;
        data[3] /= v;
        
        data[4] /= v;
        data[5] /= v;
        data[6] /= v;
        data[7] /= v;
        
        data[8] /= v;
        data[9] /= v;
        data[10] /= v;
        data[11] /= v;
        
        data[12] /= v;
        data[13] /= v;
        data[14] /= v;
        data[15] /= v;
    }
    
    /**
     * @brief operator -
     * @return
     */
    MATRIX4 operator - () const
    {
        MATRIX4 pOut;
        
        pOut.data[0] = -data[0];
        pOut.data[1] = -data[1];
        pOut.data[2] = -data[2];
        pOut.data[3] = -data[3];
        
        pOut.data[4] = -data[4];
        pOut.data[5] = -data[5];
        pOut.data[6] = -data[6];
        pOut.data[7] = -data[7];
        
        pOut.data[8] = -data[8];
        pOut.data[9] = -data[9];
        pOut.data[10] = -data[10];
        pOut.data[11] = -data[11];
        
        pOut.data[12] = -data[12];
        pOut.data[13] = -data[13];
        pOut.data[14] = -data[14];
        pOut.data[15] = -data[15];
        
        return pOut;
    }
    
    // binary operators
    
    /**
     * @brief operator +
     * @param pM
     * @return
     */
    MATRIX4 operator + (const MATRIX4 &pM) const
    {
        MATRIX4 pOut;
        
        pOut.data[0] = data[0] + pM.data[0];
        pOut.data[1] = data[1] + pM.data[1];
        pOut.data[2] = data[2] + pM.data[2];
        pOut.data[3] = data[3] + pM.data[3];
        
        pOut.data[4] = data[4] + pM.data[4];
        pOut.data[5] = data[5] + pM.data[5];
        pOut.data[6] = data[6] + pM.data[6];
        pOut.data[7] = data[7] + pM.data[7];
        
        pOut.data[8] = data[8] + pM.data[8];
        pOut.data[9] = data[9] + pM.data[9];
        pOut.data[10] = data[10] + pM.data[10];
        pOut.data[11] = data[11] + pM.data[11];
        
        pOut.data[12] = data[12] + pM.data[12];
        pOut.data[13] = data[13] + pM.data[13];
        pOut.data[14] = data[14] + pM.data[14];
        pOut.data[15] = data[15] + pM.data[15];
        
        return pOut;
    }
    
    /**
     * @brief operator -
     * @param pM
     * @return
     */
    MATRIX4 operator - (const MATRIX4  &pM) const
    {
        MATRIX4 pOut;
        
        pOut.data[0] = data[0] - pM.data[0];
        pOut.data[1] = data[1] - pM.data[1];
        pOut.data[2] = data[2] - pM.data[2];
        pOut.data[3] = data[3] - pM.data[3];
        
        pOut.data[4] = data[4] - pM.data[4];
        pOut.data[5] = data[5] - pM.data[5];
        pOut.data[6] = data[6] - pM.data[6];
        pOut.data[7] = data[7] - pM.data[7];
        
        pOut.data[8] = data[8] - pM.data[8];
        pOut.data[9] = data[9] - pM.data[9];
        pOut.data[10] = data[10] - pM.data[10];
        pOut.data[11] = data[11] - pM.data[11];
        
        pOut.data[12] = data[12] - pM.data[12];
        pOut.data[13] = data[13] - pM.data[13];
        pOut.data[14] = data[14] - pM.data[14];
        pOut.data[15] = data[15] - pM.data[15];
        
        return pOut;
    }
    
    /**
     * @brief operator *
     * @param v
     * @return
     */
    MATRIX4 operator * (float v) const
    {
        MATRIX4 pOut;
        
        pOut.data[0] = data[0] * v;
        pOut.data[1] = data[1] * v;
        pOut.data[2] = data[2] * v;
        pOut.data[3] = data[3] * v;
        
        pOut.data[4] = data[4] * v;
        pOut.data[5] = data[5] * v;
        pOut.data[6] = data[6] * v;
        pOut.data[7] = data[7] * v;
        
        pOut.data[8] = data[8] * v;
        pOut.data[9] = data[9] * v;
        pOut.data[10] = data[10] * v;
        pOut.data[11] = data[11] * v;
        
        pOut.data[12] = data[12] * v;
        pOut.data[13] = data[13] * v;
        pOut.data[14] = data[14] * v;
        pOut.data[15] = data[15] * v;
        
        return pOut;
    }
    
    /**
     * @brief operator /
     * @param v
     * @return
     */
    MATRIX4 operator / (float v) const
    {
        MATRIX4 pOut;
        
        pOut.data[0] = data[0] / v;
        pOut.data[1] = data[1] / v;
        pOut.data[2] = data[2] / v;
        pOut.data[3] = data[3] / v;
        
        pOut.data[4] = data[4] / v;
        pOut.data[5] = data[5] / v;
        pOut.data[6] = data[6] / v;
        pOut.data[7] = data[7] / v;
        
        pOut.data[8] = data[8] / v;
        pOut.data[9] = data[9] / v;
        pOut.data[10] = data[10] / v;
        pOut.data[11] = data[11] / v;
        
        pOut.data[12] = data[12] / v;
        pOut.data[13] = data[13] / v;
        pOut.data[14] = data[14] / v;
        pOut.data[15] = data[15] / v;
        
        return pOut;
        
    }
    
    /**
     * @brief Identity
     * @return
     */
    void Identity()
    {
        data[0] = 1.0f;
        data[1] = 0.0f;
        data[2] = 0.0f;
        data[3] = 0.0f;
        
        data[4] = 0.0f;
        data[5] = 1.0f;
        data[6] = 0.0f;
        data[7] = 0.0f;
        
        data[8] = 0.0f;
        data[9] = 0.0f;
        data[10] = 1.0f;
        data[11] = 0.0f;
        
        data[12] = 0.0f;
        data[13] = 0.0f;
        data[14] = 0.0f;
        data[15] = 1.0f;
    }
    
    /**
     * @brief Multiply mul operator between matricies.
     * @param pOut
     * @param pM1
     * @param pM2
     * @return
     */
    static MATRIX4 *Multiply(MATRIX4 * pOut, const MATRIX4 * pM1, const MATRIX4 * pM2)
    {
        if (pOut == NULL) {
            pOut = new MATRIX4();
        }
        
        pOut->data[0] = pM1->data[0] * pM2->data[0] + pM1->data[1] * pM2->data[4] + pM1->data[2] * pM2->data[8] + pM1->data[3] * pM2->data[12];
        pOut->data[1] = pM1->data[0] * pM2->data[1] + pM1->data[1] * pM2->data[5] + pM1->data[2] * pM2->data[9] + pM1->data[3] * pM2->data[13];
        pOut->data[2] = pM1->data[0] * pM2->data[2] + pM1->data[1] * pM2->data[6] + pM1->data[2] * pM2->data[10] + pM1->data[3] * pM2->data[14];
        pOut->data[3] = pM1->data[0] * pM2->data[3] + pM1->data[1] * pM2->data[7] + pM1->data[2] * pM2->data[11] + pM1->data[3] * pM2->data[15];

        pOut->data[4] = pM1->data[4] * pM2->data[0] + pM1->data[5] * pM2->data[4] + pM1->data[6] * pM2->data[8] + pM1->data[7] * pM2->data[12];
        pOut->data[5] = pM1->data[4] * pM2->data[1] + pM1->data[5] * pM2->data[5] + pM1->data[6] * pM2->data[9] + pM1->data[7] * pM2->data[13];
        pOut->data[6] = pM1->data[4] * pM2->data[2] + pM1->data[5] * pM2->data[6] + pM1->data[6] * pM2->data[10] + pM1->data[7] * pM2->data[14];
        pOut->data[7] = pM1->data[4] * pM2->data[3] + pM1->data[5] * pM2->data[7] + pM1->data[6] * pM2->data[11] + pM1->data[7] * pM2->data[15];

        pOut->data[8] = pM1->data[8] * pM2->data[0] + pM1->data[9] * pM2->data[4] + pM1->data[10] * pM2->data[8] + pM1->data[11] * pM2->data[12];
        pOut->data[9] = pM1->data[8] * pM2->data[1] + pM1->data[9] * pM2->data[5] + pM1->data[10] * pM2->data[9] + pM1->data[11] * pM2->data[13];
        pOut->data[10] = pM1->data[8] * pM2->data[2] + pM1->data[9] * pM2->data[6] + pM1->data[10] * pM2->data[10] + pM1->data[11] * pM2->data[14];
        pOut->data[11] = pM1->data[8] * pM2->data[3] + pM1->data[9] * pM2->data[7] + pM1->data[10] * pM2->data[11] + pM1->data[11] * pM2->data[15];

        pOut->data[12] = pM1->data[12] * pM2->data[0] + pM1->data[13] * pM2->data[4] + pM1->data[14] * pM2->data[8] + pM1->data[15] * pM2->data[12];
        pOut->data[13] = pM1->data[12] * pM2->data[1] + pM1->data[13] * pM2->data[5] + pM1->data[14] * pM2->data[9] + pM1->data[15] * pM2->data[13];
        pOut->data[14] = pM1->data[12] * pM2->data[2] + pM1->data[13] * pM2->data[6] + pM1->data[14] * pM2->data[10] + pM1->data[15] * pM2->data[14];
        pOut->data[15] = pM1->data[12] * pM2->data[3] + pM1->data[13] * pM2->data[7] + pM1->data[14] * pM2->data[11] + pM1->data[15] * pM2->data[15];
        
        return pOut;
    }
    
    /**
     * @brief Trace
     * @return
     */
    float Trace()
    {
        return data[0] + data[5] + data[10] + data[15];
    }
    
    /**
     * @brief Zero
     * @return
     */
    void Zero()
    {
        data[0] = 0.0f; data[1] = 0.0f; data[2] = 0.0f; data[3] = 0.0f;
        data[4] = 0.0f; data[5] = 0.0f; data[6] = 0.0f; data[7] = 0.0f;
        data[8] = 0.0f; data[9] = 0.0f; data[10] = 0.0f; data[11] = 0.0f;
        data[12] = 0.0f; data[13] = 0.0f; data[14] = 0.0f; data[15] = 0.0f;
    }
    
    /**
     * @brief CheckZero
     * @return
     */
    bool CheckZero()
    {
        float acc;
        acc  = fabsf(data[0]);
        acc += fabsf(data[1]);
        acc += fabsf(data[2]);
        acc += fabsf(data[3]);
        
        acc += fabsf(data[4]);
        acc += fabsf(data[5]);
        acc += fabsf(data[6]);
        acc += fabsf(data[7]);
        
        acc += fabsf(data[8]);
        acc += fabsf(data[9]);
        acc += fabsf(data[10]);
        acc += fabsf(data[11]);
        
        acc += fabsf(data[12]);
        acc += fabsf(data[13]);
        acc += fabsf(data[14]);
        acc += fabsf(data[15]);
        
        return (acc > 0.0f);
    }
    
    /**
     * @brief Translation creates a translation matrix.
     * @param x
     * @param y
     * @param z
     * @return
     */
    void Translation(float x, float y, float z)
    {
        Identity();
        
        data[12] = x;
        data[13] = y;
        data[14] = z;
    }
    
    /**
     * @brief RotateX
     * @param alpha
     * @return
     */
    void RotateX(float alpha)
    {
        Identity();
        
        float cosAlpha = cosf(alpha);
        float sinAlpha = sinf(alpha);
        
        data[5] =  cosAlpha;
        data[10] =  cosAlpha;
        data[6] =  sinAlpha;
        data[9] = -sinAlpha;
    }
    
    /**
     * @brief RotateY
     * @param alpha
     * @return
     */
    void RotateY(float alpha)
    {
        Identity();

        float cosAlpha = cosf(alpha);
        float sinAlpha = sinf(alpha);

        data[0] =  cosAlpha;
        data[10] =  cosAlpha;
        data[2] = -sinAlpha;
        data[8] =  sinAlpha;
    }
    
    /**
     * @brief RotateZ
     * @param alpha
     * @return
     */
    void RotateZ(float alpha)
    {
        Identity();

        float cosAlpha = cosf(alpha);
        float sinAlpha = sinf(alpha);

        data[0] =  cosAlpha;
        data[5] =  cosAlpha;
        data[1] =  sinAlpha;
        data[4] = -sinAlpha;
    }
    
    /**
     * @brief FromQuaternion creates a rotation MATRIX4 based on a quatertion.
     * @param pQ
     * @return
     */
    void FromQuaternion(const QUATERNION * pQ)
    {
        Identity();
        
        float qx2 = pQ->x * pQ->x;
        float qy2 = pQ->y * pQ->y;
        float qz2 = pQ->z * pQ->z;
        
        data[0] = 1.0f - 2.0f * (qz2 + qy2);
        data[1] = 2.0f * (pQ->x * pQ->y - pQ->w * pQ->z);
        data[2] = 2.0f * (pQ->x * pQ->z + pQ->w * pQ->y);
        
        data[4] = 2.0f * (pQ->x * pQ->y + pQ->w * pQ->z);
        data[5] = 1.0f - 2.0f * (qx2 + qz2);
        data[6] = 2.0f * (pQ->y * pQ->z - pQ->w * pQ->x);
        
        data[8] = 2.0f * (pQ->x * pQ->z - pQ->w * pQ->y);
        data[9] = 2.0f * (pQ->y * pQ->z + pQ->w * pQ->x);
        data[10] = 1.0f - 2.0f * (qx2 + qy2);
    }
    

    /**
     * @brief ToQuaternion creates a quaternion from a matrix.
     * @param pOut is the output quaternion.
     * @return
     */
    QUATERNION *ToQuaternion(QUATERNION *pOut)
    {
        if (pOut == NULL) {
            pOut = new QUATERNION();
        }
            
        //trace of the rotation matrix; i.e., the 3x3 upper left block.
        float tr = data[0] + data[5] + data[10];
        
        if (tr > 0.0f) {
            pOut->w = sqrtf(MAX(tr + 1.0f, 0.0f)) * 2.0f;
            float w4 = 4.0f / pOut->w;
            pOut->x = sqrtf(MAX( data[0] - data[5] - data[10] + data[15], 0.0f)) * w4;
            pOut->y = sqrtf(MAX(-data[0] + data[5] - data[10] + data[15], 0.0f)) * w4;
            pOut->z = sqrtf(MAX(-data[0] - data[5] + data[10] + data[15], 0.0f)) * w4;
        } else {
        }
        
        return pOut;
    }

    
    /**
     * @brief Determinant computes the determinant of a matrix.
     * @return
     */
    float Determinant() const
    {
        return data[0] * data[5] * data[10] * data[15] +
               data[0] * data[6] * data[11] * data[13] +
               data[0] * data[7] * data[9]  * data[14] +
              
               data[1] * data[4] * data[11] * data[14] +
               data[1] * data[6] * data[8]  * data[15] +
               data[1] * data[7] * data[10] * data[12] +
              
               data[2] * data[4] * data[9]  * data[15] +
               data[2] * data[5] * data[11] * data[12] +
               data[2] * data[7] * data[8]  * data[13] +
              
               data[3] * data[4] * data[10] * data[13] +
               data[3] * data[5] * data[8]  * data[14] +
               data[3] * data[6] * data[9]  * data[12] - (
                                                       
               data[0] * data[5] * data[11] * data[14] +
               data[0] * data[6] * data[9]  * data[15] +
               data[0] * data[7] * data[10] * data[13] +
                                                       
               data[1] * data[4] * data[10] * data[15] +
               data[1] * data[6] * data[11] * data[12] +
               data[1] * data[7] * data[8]  * data[14] +
                                                       
               data[2] * data[4] * data[11] * data[13] +
               data[2] * data[5] * data[8]  * data[15] +
               data[2] * data[7] * data[9]  * data[12] +
                                                       
               data[3] * data[4] * data[9]  * data[14] +
               data[3] * data[5] * data[10] * data[12] +
               data[3] * data[6] * data[8]  * data[13]);
    }
    
    /**
     * @brief LookAtLH creates a left-handed view matrix.
     * @param pEye
     * @param pAt
     * @param pUp
     * @return
     */
    void LookAtLH(const VECTOR3 *pEye, const VECTOR3 *pAt, const VECTOR3 *pUp)
    {
        VECTOR3 x, y, z;
        z.x = pAt->x - pEye->x;
        z.y = pAt->y - pEye->y;
        z.z = pAt->z - pEye->z;
        
        z.Normalize();
        
        VECTOR3::Cross(&x, pUp, &z);
        x.Normalize();
        
        VECTOR3::Cross(&y, &z, &x);
        
        data[0] = x.x;
        data[1] = y.x;
        data[2] = z.x;
        data[3] = 0.0f;
        
        data[4] = x.y;
        data[5] = y.y;
        data[6] = z.y;
        data[7] = 0.0f;
        
        data[8] = x.z;
        data[9] = y.z;
        data[10] = z.z;
        data[11] = 0.0f;
        
        data[12] = -VECTOR3::Dot(&x, pEye);
        data[13] = -VECTOR3::Dot(&y, pEye);
        data[14] = -VECTOR3::Dot(&z, pEye);
        data[15] = 1.0f;
    }

    /**
     * @brief LookAtRH creates a right-handed view matrix.
     * @param pEye
     * @param pAt
     * @param pUp
     * @return
     */
    void LookAtRH(const VECTOR3 *pEye, const VECTOR3 *pAt, const VECTOR3 *pUp)
    {
        VECTOR3 x, y, z;
        z.x = pEye->x - pAt->x;
        z.y = pEye->y - pAt->y;
        z.z = pEye->z - pAt->z;
        
        z.Normalize();
        
        VECTOR3::Cross(&x, pUp, &z);
        x.Normalize();
        
        VECTOR3::Cross(&y, &z, &x);
        
        data[0] = x.x;
        data[1] = y.x;
        data[2] = z.x;
        data[3] = 0.0f;
        
        data[4] = x.y;
        data[5] = y.y;
        data[6] = z.y;
        data[7] = 0.0f;
        
        data[8] = x.z;
        data[9] = y.z;
        data[10] = z.z;
        data[11] = 0.0f;
        
        data[12] = -VECTOR3::Dot(&x, pEye);
        data[13] = -VECTOR3::Dot(&y, pEye);
        data[14] = -VECTOR3::Dot(&z, pEye);
        data[15] = 1.0f;
    }

    /**
     * @brief PerspectiveFovLH creates a perspective left-handed matrix.
     * @param fovy
     * @param Aspect
     * @param zn
     * @param zf
     * @return
     */
    void PerspectiveFovLH(float fovy, float Aspect, float zn, float zf)
    {
        Identity();
        
        float f = 1.0f / tanf(fovy * 0.5f);
        float d = zf - zn;
        
        data[0] = f / Aspect;
        data[5] = f;
        data[10] = zf / d;
        data[15] = 0.0f;
        data[14] = -zn * zf / d;
        data[11] = 1.0f;
    }
    
    /**
     * @brief PerspectiveFovRH creates a perspective right-handed matrix.
     * @param fovy
     * @param Aspect
     * @param zn
     * @param zf
     * @return
     */
    void PerspectiveFovRH(float fovy, float Aspect, float zn, float zf)
    {
        Identity();
        
        float f = 1.0f / tanf(fovy * 0.5f);
        float d = zn - zf;
        
        data[0] = f / Aspect;
        data[5] = f;
        data[10] = zf / d;
        data[15] = 0.0f;
        data[14] = zn * zf / d;
        data[11] = -1.0f;
    }
    
    /**
     * @brief OrthoLH  creates an orthographic left-handed matrix.
     * @param w
     * @param h
     * @param zn
     * @param zf
     * @return
     */
    void OrthoLH(float w, float h, float zn, float zf)
    {
        Identity();
        
        float d = zf - zn;
        
        data[0] = 2.0f / float(w);
        data[5] = 2.0f / float(h);
        data[10] = 1.0f / d;
        data[14] = -zn / d;
    }

    /**
     * @brief OrthoRH creates an orthographic right-handed matrix.
     * @param w
     * @param h
     * @param zn
     * @param zf
     * @return
     */
    void OrthoRH(float w, float h, float zn, float zf)
    {
        Identity();
        
        float d = zn - zf;
        
        data[0] = 2.0f / float(w);
        data[5] = 2.0f / float(h);
        data[10] = 1.0f / d;
        data[14] = zn / d;
    }

    /**
     * @brief Clone deep copy of the matrix.
     * @param pOut
     * @return
     */
    MATRIX4* Clone(MATRIX4* pOut = NULL) const
    {
#ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new MATRIX4();
        }
#endif
        memcpy(pOut->data, this->data, sizeof(float) * 16);

        return pOut;
    }
        
    /**
     * @brief Inverse computes the inverse of a MATRIX4 using the Cayley-Hamilton method.
     * @param pOut
     * @param pM
     * @return
     */
    MATRIX4* Inverse(MATRIX4 *pOut = NULL) const
    {
        float det = Determinant();
        
        if (fabsf(det) <= 1e-9f) {
            return pOut;
        }
        
    #ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new MATRIX4();
        }
    #endif
        
        MATRIX4 I, pM, pM2, pM3;
        
        this->Clone(&pM);
        Multiply(&pM2, &pM, &pM);
        Multiply(&pM3, &pM2, &pM);
        
        float tr_pM  = pM.Trace();
        float tr_pM2 = pM2.Trace();
        float tr_pM3 = pM3.Trace();
        
        float tmp1 = (tr_pM * tr_pM * tr_pM - 3.0f * tr_pM * tr_pM2 + 2.0f * tr_pM3) / 6.0f;
        float tmp2 = -(tr_pM * tr_pM - tr_pM2) / 2.0f;
        
        I.Identity();
        
        *pOut = (I * tmp1 + pM * tmp2 + pM2 * tr_pM - pM3) / det;
        
        return pOut;
    }
    
    /**
     * @brief Transpose transposes a matrix.
     * @param pOut
     * @return
     */
    MATRIX4 *Transpose(MATRIX4 *pOut) const
    {
    #ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new MATRIX4();
        }
    #endif
        
        pOut->data[0] = data[0];
        pOut->data[1] = data[4];
        pOut->data[2] = data[8];
        pOut->data[3] = data[12];
        
        pOut->data[4] = data[1];
        pOut->data[5] = data[5];
        pOut->data[6] = data[9];
        pOut->data[7] = data[13];
        
        pOut->data[8] = data[2];
        pOut->data[9] = data[6];
        pOut->data[10] = data[10];
        pOut->data[11] = data[14];
        
        pOut->data[12] = data[3];
        pOut->data[13] = data[7];
        pOut->data[14] = data[11];
        pOut->data[15] = data[15];
        
        return pOut;
    }
    
    /**
     * @brief TransformCoord applies a MATRIX4 to a vector; including division by w.
     * @param pOut
     * @param pV
     * @return
     */
    VECTOR3 * TransformCoord(VECTOR3 * pOut, const VECTOR3 * pV) const
    {
    #ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR3();
        }
    #endif
        
        pOut->x = pV->x * data[0] + pV->y * data[4] + pV->z * data[8]  + data[12];
        pOut->y = pV->x * data[1] + pV->y * data[5] + pV->z * data[9]  + data[13];
        pOut->z = pV->x * data[2] + pV->y * data[6] + pV->z * data[10] + data[14];
        float w = pV->x * data[3] + pV->y * data[7] + pV->z * data[11] + data[15];
        
        if (fabsf(w) > 0.0f) {
            pOut->x /= w;
            pOut->y /= w;
            pOut->z /= w;
        }
        
        return pOut;
    }
    
    /**
     * @brief Transform applies a MATRIX4 to a vector.
     * @param pOut
     * @param pV
     * @return
     */
    VECTOR4 * Transform(VECTOR4 * pOut, const VECTOR3 * pV) const
    {
    #ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR4();
        }
    #endif
        
        pOut->x = pV->x * data[0] + pV->y * data[4] + pV->z * data[8] + data[12];
        pOut->y = pV->x * data[1] + pV->y * data[5] + pV->z * data[9] + data[13];
        pOut->z = pV->x * data[2] + pV->y * data[6] + pV->z * data[10] + data[14];
        pOut->w = pV->x * data[3] + pV->y * data[7] + pV->z * data[11] + data[15];
        
        return pOut;
    }

    /**
     * @brief TransformNormal applies a MATRIX4 to a normal vector.
     * @param pOut
     * @param pV
     * @return
     */
    VECTOR3 *TransformNormal(VECTOR3 * pOut, const VECTOR3 * pV) const
    {
    #ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR3();
        }
    #endif
        
        pOut->x = pV->x * data[0] + pV->y * data[4] + pV->z * data[8];
        pOut->y = pV->x * data[1] + pV->y * data[5] + pV->z * data[9];
        pOut->z = pV->x * data[2] + pV->y * data[6] + pV->z * data[10];
        return pOut;
    }

    /**
     * @brief ToArray converts the MATRIX4 into an array format; compatible with OpenGL.
     * @param pOut
     * @param pM
     * @return
     */
    float *ToArray(float *pOut) const
    {
    #ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new float[16];
        }
    #endif
        
        memcpy(pOut, this->data, sizeof(float) * 16);
        
        return pOut;
    }

    /**
     * @brief FromArray converts an OpenGL format matrix into the MATRIX4 format.
     * @param pOut
     * @param pM
     * @return
     */
    void FromArray(float *pM)
    {
        memcpy(this->data, pM, sizeof(float) * 16);
    }

    /**
     * @brief ExtractPlanes extracts planes from a view matrix.
     * @param pOut a pointer to an array of six planes (PLANE).
     * @return
     */
    PLANE *ExtractPlanes(PLANE *pOut)
    {
    #ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new PLANE[6];
        }
    #endif
        
        //Left
        pOut[0].Init(data[3] + data[0], data[7] + data[4], data[11] + data[8], data[15] + data[12]);
        //Right
        pOut[1].Init(data[3] - data[0], data[7] - data[4], data[11] - data[8], data[15] - data[12]);
        
        //Bottom
        pOut[2].Init(data[3] + data[1], data[7] + data[5], data[11] + data[9], data[15] + data[13]);
        //Top
        pOut[3].Init(data[3] - data[1], data[7] - data[5], data[11] - data[9], data[15] - data[13]);
        
        //Near
        pOut[4].Init(data[2], data[6], data[10], data[14]);
        //Far
        pOut[5].Init(data[3] - data[2], data[7] - data[6], data[11] - data[10], data[15] - data[14]);
        
        return pOut;
    }
    
    /**
     * @brief Print prints the matrix.
     * @return
     */
    void Print()
    {
        std::printf("\n");
        std::printf("%3.3f %3.3f %3.3f %3.3f\n", data[0], data[1], data[2], data[3]);
        std::printf("%3.3f %3.3f %3.3f %3.3f\n", data[4], data[5], data[6], data[7]);
        std::printf("%3.3f %3.3f %3.3f %3.3f\n", data[8], data[9], data[10], data[11]);
        std::printf("%3.3f %3.3f %3.3f %3.3f\n", data[12], data[13], data[14], data[15]);
        std::printf("\n");

    }
};

}

#endif //BNT3D_MATRIX4_HPP
