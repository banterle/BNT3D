/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/
#ifndef BNT3D_VECTOR3_HPP
#define BNT3D_VECTOR3_HPP

#include <cstdio>

namespace bnt3d{

/**
 * @brief The VECTOR3 class
 */
class VECTOR3
{
public:
    float x, y, z;
    
    /**
     * @brief VECTOR3
     */
    VECTOR3()
    {
    }
    
    /**
     * @brief VECTOR3
     * @param a
     */
    VECTOR3(float a)
    {
        this->x = a;
        this->y = a;
        this->z = a;
    }
    
    /**
     * @brief VECTOR3
     * @param x
     * @param y
     * @param z
     */
    VECTOR3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    /**
     * @brief operator -
     * @param v
     * @return
     */
    VECTOR3 operator -(const VECTOR3 &v) const
    {
        return VECTOR3(x - v.x, y - v.y, z - v.z);
    }
    
    /**
     * @brief operator -
     * @return
     */
    VECTOR3 operator -()const
    {
        return VECTOR3(-x, -y, -z);
    }
    
    /**
     * @brief operator -=
     * @param v
     */
    void operator -=(const VECTOR3 &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }
    
    /**
     * @brief operator +
     * @param v
     * @return
     */
    VECTOR3 operator +(const VECTOR3 &v) const
    {
        return VECTOR3(x + v.x, y + v.y, z + v.z);
    }
    
    /**
     * @brief operator +=
     * @param v
     */
    void operator +=(const VECTOR3 &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }
    
    /**
     * @brief operator /
     * @param v
     * @return
     */
    VECTOR3 operator /(const VECTOR3 &v) const
    {
        return VECTOR3(x / v.x, y / v.y, z / v.z);
    }
    
    void operator /=(const VECTOR3 &v)
    {
        x /= v.x;
        y /= v.y;
        z /= v.z;
    }
    
    /**
     * @brief operator *
     * @param v
     * @return
     */
    VECTOR3 operator *(const VECTOR3 &v)const
    {
        return VECTOR3(x*v.x, y*v.y, z*v.z);
    }
    
    /**
     * @brief operator *
     * @param a
     * @return
     */
    VECTOR3 operator *(const float &a)const
    {
        return VECTOR3(x*a, y*a, z*a);
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
    }
    
    /**
     * @brief operator =
     * @param v
     * @return
     */
    VECTOR3& operator = (const float v[3])
    {
        x = v[0];
        y = v[1];
        z = v[2];
        return *this;
    }
    
    /**
     * @brief operator /
     * @param a
     * @return
     */
    VECTOR3 operator /(const float &a)const
    {
        if (a != 0.0f)
            return VECTOR3(x / a, y / a, z / a);
        else
            return VECTOR3(x, y, z);
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
        }
        return x;
    }
    
    /**
     * @brief LengthSq
     * @return
     */
    float LengthSq() const
    {
        return (x * x + y * y + z * z);
    }
    
    /**
     * @brief Length
     * @return
     */
    float Length() const
    {
        return sqrtf(x * x + y * y + z * z);
    }
    
    /**
     * @brief FromArray
     * @param vec
     * @return
     */
    void FromArray(float vec[3])
    {
        x = vec[0];
        y = vec[1];
        z = vec[2];
    }
    
    /**
     * @brief Normalize
     * @param pOut
     * @return
     */
    VECTOR3 *Normalize(VECTOR3 *pOut)
    {
#ifdef NORMALIZATIONPOINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR3();
        }
#endif
        pOut->x = x;
        pOut->y = y;
        pOut->z = z;
        
        pOut->Normalize();
        return pOut;
    }
    
    /**
     * @brief Normalize normalizes a VECTOR3.
     * @return
     */
    void Normalize()
    {
        float length = x * x + y * y + z * z;
        
        if (length > 0.0f) {
            length = sqrtf(length);
            x /= length;
            y /= length;
            z /= length;
        }
        else {
#ifdef DEBUG_POINER_CHECK
            printf("VECTOR3 *Normalize(VECTOR3 *pOut): Normalization Error!\n");
#endif
        }
    }
    
    /**
     * @brief Normalize2 normalizes a VECTOR3 and returns is magnitude.
     * @return
     */
    float Normalize2()
    {
        float length = x * x + y * y + z * z;
        
        if (length > 0.0f) {
            length = sqrtf(length);
            x /= length;
            y /= length;
            z /= length;
            return length;
        }
        else {
            return 0.0f;
        }
    }
    
    /**
     * @brief Cross computes the cross product (a x b)
     * @param pOut
     * @param a
     * @param b
     */
    static VECTOR3 *Cross(VECTOR3 *pOut, const VECTOR3 *a, const VECTOR3 *b)
    {
#ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR3();
        }
#endif
        
        pOut->x = a->y * b->z - b->y * a->z;
        pOut->y = a->z * b->x - b->z * a->x;
        pOut->z = a->x * b->y - b->x * a->y;
        return pOut;
    }
    
    /**
     * @brief Dot
     * @param a
     * @param b
     * @return
     */
    static float Dot(const VECTOR3 *a, const VECTOR3 *b)
    {
        return (a->x * b->x + a->y * b->y + a->z * b->z);
    }
    
    /**
     * @brief Distance
     * @param a
     * @param b
     * @return
     */
    static float Distance(const VECTOR3 *a, const VECTOR3 *b)
    {
        VECTOR3 c;
        c.x = a->x - b->x;
        c.y = a->y - b->y;
        c.z = a->z - b->z;
        
        return sqrtf(c.x * c.x + c.y * c.y + c.z * c.z);
    }
    
    /**
     * @brief DistanceSq
     * @param a
     * @param b
     * @return
     */
    static float DistanceSq(const VECTOR3 *a, const VECTOR3 *b)
    {
        VECTOR3 c;
        c.x = a->x - b->x;
        c.y = a->y - b->y;
        c.z = a->z - b->z;
        return c.x * c.x + c.y * c.y + c.z * c.z;
    }
    
    /**
     * @brief Similar checks if two VECTOR3 are similar.
     * @param a
     * @param b
     * @return
     */
    static bool Similar(const VECTOR3 *a, const VECTOR3 *b)
    {
        VECTOR3 tmp = *a - *b;
        return sqrtf(MAX(Dot(&tmp, &tmp), 0.0f)) < 1e-12f;
    }
    
    /**
     * @brief ToThetaPhi converts a VECTOR3 direction into a (theta, phi) direction.
     * @param pOut
     * @return
     */
    VECTOR2* ToThetaPhi(VECTOR2 *pOut) const
    {
#ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR2();
        }
#endif
        
        pOut->x = acosf(y);
        pOut->y = atan2f(z, x);
        
        return pOut;
    }
    
    /**
     * @brief FromThetaPhi converts a (theta, phi) direction into a VECTOR3 direction.
     * @param dir
     * @param out
     * @return
     */
    void FromThetaPhi(VECTOR2 *dir)
    {       
        float sinTheta = sinf(dir->x);
        this->x = cosf(dir->y) * sinTheta;
        this->y = cosf(dir->x);
        this->z = sinf(dir->y) * sinTheta;
    }
    
    /**
     * @brief ToTexcoord converts a VECTOR3 direction into texture coordinates.
     * @param pOut
     * @param dir
     * @return
     */
    VECTOR2 *ToTexcoord(VECTOR2 *pOut) const
    {
#ifdef POINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR2();
        }
#endif
        
        //(theta,phi)->(y,x)
        pOut->x = 1.0f - ((atan2f(z, -x) * C_INV_PI) * 0.5f + 0.5f);
        pOut->y = (acosf(y) * C_INV_PI);
        
        return pOut;
    }
        
    /**
     * @brief FromTexcoord converts from a pixel position (x,y) to a VECTOR3 direction.
     * @param x
     * @param y
     * @return
     */
    void FromTexcoord(float x, float y)
    {
        float phi   = (C_PI_2 * x);
        float theta = (C_PI   * y);
        
        float sinTheta = sinf(theta);
        
        this->x = sinTheta * cosf(phi);
        this->y = cosf(theta);
        this->z = sinTheta * sinf(phi);
    }

    /**
    * @brief Vec2ToVec3 converts a VECTOR2 into a VECTOR3
    * @param vec
    * @return
    */
    void fromVec2(VECTOR2* vec)
    {
        x = vec->x;
        y = 0.0f;
        z = vec->y;
    }

    /**
    * @brief Print prints the vector.
    * @param vec
    * @return
    */
    void Print()
    {
        std::printf(" %f %f %f\n", x, y, z);
    }

    /**
     * @brief fscanf for a VECTOR3.
     * @param file
     * @param vet
     */
    void Filescanf(FILE* file)
    {
        auto retx = std::fscanf(file, "%f", &x);
        auto rety = std::fscanf(file, "%f", &y);
        auto retz = std::fscanf(file, "%f", &z);
    }
};

//Zeros VECTOR3
const VECTOR3 Vec3Zero = VECTOR3(0.0f);

//Halfs VECTOR3
const VECTOR3 Vec3Half = VECTOR3(0.5f);

//Ones VECTOR3
const VECTOR3 Vec3One = VECTOR3(1.0f);

//Space Axis
const VECTOR3 E0 = VECTOR3(1.0f, 0.0f, 0.0f);
const VECTOR3 E1 = VECTOR3(0.0f, 1.0f, 0.0f);
const VECTOR3 E2 = VECTOR3(0.0f, 0.0f, 1.0f);

}

#endif //BNT3D_VECTOR3_HPP
