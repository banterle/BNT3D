/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_VECTOR4_HPP
#define BNT3D_VECTOR4_HPP

#include <cmath>

namespace bnt3d{

/**
 * @brief The VECTOR4 class
 */
class VECTOR4 {
public:
    float x, y, z, w;

    VECTOR4()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }

    /**
     * @brief VECTOR4
     * @param a
     */
    VECTOR4(float a)
    {
        x = y = z = w = a;
    }

    /**
     * @brief VECTOR4
     * @param x
     * @param y
     * @param z
     * @param w
     */
    VECTOR4(float x, float y, float z, float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    /**
     * @brief operator -
     * @param v
     * @return
     */
    VECTOR4 operator -(const VECTOR4 &v) const
    {
        return VECTOR4(x - v.x, y - v.y, z - v.z, w - v.w);
    }

    /**
     * @brief operator -
     * @return
     */
    VECTOR4 operator -()const
    {
        return VECTOR4(-x, -y, -z, -w);
    }

    /**
     * @brief operator -=
     * @param v
     */
    void operator -=(const VECTOR4 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
    }

    /**
     * @brief operator +
     * @param v
     * @return
     */
    VECTOR4 operator +(const VECTOR4 &v) const
    {
        return VECTOR4(x + v.x, y + v.y, z + v.z, w + v.w);
    }

    /**
     * @brief operator +=
     * @param v
     */
    void operator +=(const VECTOR4 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }

    /**
     * @brief operator /
     * @param v
     * @return
     */
    VECTOR4 operator /(const VECTOR4 &v) const
    {
        return VECTOR4(x / v.x, y / v.y, z / v.z, w / v.w);
    }

    /**
     * @brief operator /=
     * @param v
     * @return
     */
    void operator /=(const VECTOR4 &v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        w /= v.w;
    }

    /**
     * @brief operator *
     * @param v
     * @return
     */
    VECTOR4 operator *(const VECTOR4 &v)const
    {
        return VECTOR4(x * v.x, y * v.y, z * v.z, w * v.w);
    }

    /**
     * @brief operator *
     * @param a
     * @return
     */
    VECTOR4 operator *(const float &a)const
    {
        return VECTOR4(x * a, y * a, z * a, w * a);
    }

    /**
     * @brief operator *=
     * @param a
     */
    void operator *=(const float &a)
    {
        x *= a;
        y *= a;
        z *= a;
        w *= a;
    }

    /**
     * @brief operator =
     * @param v
     * @return
     */
    VECTOR4& operator = (const float v[4])
    {
        x = v[0];
        y = v[1];
        z = v[2];
        w = v[3];
        return *this;
    }

    /**
     * @brief operator /
     * @param a
     * @return
     */
    VECTOR4 operator /(const float &a)const
    {
        if (a != 0.0f)
            return VECTOR4(x / a, y / a, z / a, w / a);
        else
            return VECTOR4(x, y, z, w);
    }

    /**
     * @brief operator /=
     * @param a
     */
    void operator /=(const float &a)
    {
        if (a != 0.0f) {
            x /= a;
            y /= a;
            z /= a;
            w /= a;
        }
    }

    /**
     * @brief operator []
     * @param i
     * @return
     */
    float operator [](int i) const
    {
        switch (i) {
        case 0:
            return x; break;
        case 1:
            return y; break;
        case 2:
            return z; break;
        case 3:
            return w; break;
        }
        return -1.0f;
    }

    /**
     * @brief operator []
     * @param i
     * @return
     */
    float &operator [](int i)
    {
        switch (i) {
        case 0:
            return x; break;
        case 1:
            return y; break;
        case 2:
            return z; break;
        case 3:
            return w; break;
        }
        return x;
    }
    
    /**
     * @brief LengthSq
     * @return
     */
    float LengthSq()
    {
        return (x * x + y * y + z * z + w * w);
    }

    /**
     * @brief Length
     * @return
     */
    float Length()
    {
        return sqrtf(x * x + y * y + z * z + w * w);
    }
    
    /**
     * @brief Normalize normalizes a VECTOR4.
     * @param pOut
     * @return
     */
    VECTOR4 *Normalize(VECTOR4 *pOut)
    {
        #ifdef POINTER_CHECK
            if (pOut == NULL) {
                pOut = new VECTOR4();
            }
        #endif
        pOut->x = x;
        pOut->y = y;
        pOut->z = z;
        pOut->w = w;

        pOut->Normalize();
        return pOut;
    }

    /**
     * @brief Normalize normalizes a VECTOR4.
     * @return
     */
    void Normalize()
    {
        float length = x * x + y * y + z * z + w * w;

        if (length > 0.0f) {
            length = sqrtf(length);
            x /= length;
            y /= length;
            z /= length;
            w /= length;
        }
        else {
    #ifdef DEBUG_POINER_CHECK
            printf("VECTOR4::Normalize(): Normalization Error!\n");
    #endif
        }
    }
    

    /**
     * @brief Dot
     * @param a
     * @param b
     * @return
     */
    static float Dot(const VECTOR4 *a, const VECTOR4 *b)
    {
        return (a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w);
    }
    
    /**
     * @brief Distance
     * @param a
     * @param b
     * @return
     */
    static float Distance(const VECTOR4 *a, const VECTOR4 *b)
    {
        VECTOR4 c;
        c.x = a->x - b->x;
        c.y = a->y - b->y;
        c.z = a->z - b->z;
        c.w = a->w - b->w;
        return c.Length();
    }
    
    /**
     * @brief DistanceSq
     * @param a
     * @param b
     * @return
     */
    static float DistanceSq(const VECTOR4 *a, const VECTOR4 *b)
    {
        VECTOR4 c;
        c.x = a->x - b->x;
        c.y = a->y - b->y;
        c.z = a->z - b->z;
        c.w = a->w - b->w;
        return c.LengthSq();
    }
};

}

#endif //BNT3D_VECTOR4_HPP
