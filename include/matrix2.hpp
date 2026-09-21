/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_MATRIX2_HPP
#define BNT3D_MATRIX2_HPP

#include <cstdio>
#include "vector2.hpp"

namespace bnt3d{

/**
 * @brief The MATRIX2 class
 */
class MATRIX2
{
public:
    float data[4];
    
    /**
     * @brief MATRIX2
     */
    MATRIX2()
    {
    }
    
    /**
     * @brief MATRIX2 creates and sets the matrix to (a00, a01; a10, a11).
     * @param a00
     * @param a01
     * @param a10
     * @param a11
     */
    MATRIX2(float a00, float a01, float a10, float a11)
    {
        Init(a00, a01, a10, a11);
    }
    
    /**
     * @brief Init sets the matrix to (a00, a01; a10, a11).
     * @param a00
     * @param a01
     * @param a10
     * @param a11
     */
    void Init(float a00, float a01, float a10, float a11) {
        data[0] = a00;
        data[2] = a10;
        data[1] = a01;
        data[3] = a11;
    }
    
    /**
     * @brief Identity sets the matrix to identity.
     */
    void Identity()
    {
        data[0] = 1.0f;
        data[1] = 0.0f;
        data[2] = 0.0f;
        data[3] = 1.0f;
    }
    
    /** + operator*/
    
    /**
     * @brief operator +=
     * @param pM
     */
    void operator += (const MATRIX2 &pM)
    {
        for (int i = 0; i < 4; i++) {
            data[i] += pM.data[i];
        }
    }
    
    /**
     * @brief operator +
     * @param pM
     * @return
     */
    MATRIX2 operator +(const MATRIX2 &pM) const
    {
        MATRIX2 pOut;
        
        for (int i = 0; i < 4; i++) {
            pOut.data[i] = data[i] + pM.data[i];
        }
        
        return pOut;
    }
    
    /** - operator*/
    
    /**
     * @brief operator -=
     * @param pM
     */
    void operator -= (const MATRIX2 &pM)
    {
        for (int i = 0; i < 4; i++) {
            data[i] -= pM.data[i];
        }
    }
    
    /**
     * @brief operator -
     * @param pM
     * @return
     */
    MATRIX2 operator -(const MATRIX2 &pM) const
    {
        MATRIX2 pOut;
        
        for (int i = 0; i < 4; i++) {
            pOut.data[i] = data[i] - pM.data[i];
        }
        
        return pOut;
    }
    
    /**
     * @brief operator -
     * @return
     */
    MATRIX2 operator -()const
    {
        return MATRIX2(-data[0], -data[1], -data[2], -data[3]);
    }
    
    /** * operator */
    
    /**
     * @brief Multiply
     * @param pOut
     * @param mA
     * @param mB
     * @return
     */
    static MATRIX2 *Multiply(MATRIX2 *pOut, const MATRIX2 &mA, const MATRIX2 &mB)
    {
        #ifdef POINTER_CHECK
            if (pOut == NULL) {
                pOut = new MATRIX2();
            }
        #endif
        
        pOut->data[0] = mA.data[0] * mB.data[0] + mA.data[1] * mB.data[2];
        pOut->data[1] = mA.data[0] * mB.data[1] + mA.data[1] * mB.data[3];
        
        pOut->data[2] = mA.data[2] * mB.data[0] + mA.data[3] * mB.data[2];
        pOut->data[3] = mA.data[2] * mB.data[1] + mA.data[3] * mB.data[3];
        
        return pOut;
    }
    
    /**
     * @brief operator *=
     * @param pM
     */
    void operator *= (const MATRIX2 &pM)
    {
        MATRIX2 pOut;
        Multiply(&pOut, *this, pM);
        
        for (int i = 0; i < 4; i++) {
            data[i] = pOut.data[i];
        }
    }
    
    /**
     * @brief operator *=
     * @param v
     */
    void operator *= (float v)
    {
        for (int i = 0; i < 4; i++) {
            data[i] *= v;
        }
    }
    
    /**
     * @brief operator *
     * @param pM
     * @return
     */
    MATRIX2 operator *(const MATRIX2 &pM) const
    {
        MATRIX2 pOut;
        Multiply(&pOut, *this, pM);
        return pOut;
    }
    
    /**
     * @brief operator *
     * @param pM
     * @return
     */
    VECTOR2 operator *(const VECTOR2 &pV) const
    {
        VECTOR2 pOut;
        
        pOut.x = data[0] * pV.x + data[1] * pV.y;
        pOut.y = data[2] * pV.x + data[3] * pV.y;
        
        return pOut;
    }
    
    /**
     * @brief operator /=
     * @param v
     */
    void operator /= (float v)
    {
        for (int i = 0; i < 4; i++) {
            data[i] /= v;
        }
    }
    
    /**
     * @brief Determinant computes the determinant of the matrix.
     * @return
     */
    float Determinant() const
    {
        return data[0] * data[3] - data[2] * data[1];
    }
    
    /**
     * @brief Inverse computes the inverse of the matrix.
     * @param out
     * @return
     */
    MATRIX2 *Inverse(MATRIX2 *out = NULL)
    {
#ifdef POINTER_CHECK
        if (out == NULL) {
            out = new MATRIX2();
        }
#endif
        
        float det = Determinant();
        
        if (fabsf(det) < 1e-9f) {
            std::printf("MATRIX2::Inverse -- Error: Determinant is near zero.\n");
            out->data[0] = 0.0f;
            out->data[1] = 0.0f;
            out->data[2] = 0.0f;
            out->data[3] = 0.0f;
            return out;
        }
        
        out->Init(data[3] / det, -data[1] / det, -data[2] / det, data[0] / det);
        return out;
    }
    
    /**
     * @brief getRow returns a row of the matrix.
     * @return
     */
    VECTOR2 *getRow(VECTOR2 *pOut, unsigned int row)
    {
        row = row % 2;
        
#ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR2();
        }
#endif
        
        pOut->x = data[row * 2];
        pOut->y = data[row * 2 + 1];
        
        return pOut;
    }
    
    /**
     * @brief Print prints the matrix.
     */
    void Print()
    {
        std::printf("\n%3.5f %3.5f \n %3.5f %3.5f\n\n", data[0], data[1], data[2], data[3]);
    }
};

}

#endif //BNT3D_MATRIX2_HPP
