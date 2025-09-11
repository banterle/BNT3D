/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_VECTOR2_HPP
#define BNT3D_VECTOR2_HPP

namespace bnt3d{

/**
 * @brief The VECTOR2 class
 */
class VECTOR2
{
public:
    float x, y;

    /**
     * @brief VECTOR2
     */
    VECTOR2()
    {
    }

    /**
     * @brief VECTOR2
     */
    VECTOR2(float a)
    {
        this->x = a;
        this->y = a;
    }


    /**
     * @brief VECTOR2
     * @param x
     * @param y
     */
    VECTOR2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    /**
     * @brief operator -
     * @param v
     * @return
     */
    VECTOR2 operator -(const VECTOR2 &v)
    {
        return VECTOR2(x - v.x, y - v.y);
    }

    /**
     * @brief operator -=
     * @param v
     */
    void operator -=(const VECTOR2 &v)
    {
        x -= v.x;
        y -= v.y;
    }

    /**
     * @brief operator +
     * @param v
     * @return
     */
    VECTOR2 operator +(const VECTOR2 &v)
    {
        return VECTOR2(x + v.x, y + v.y);
    }

    /**
     * @brief operator +=
     * @param v
     */
    void operator +=(const VECTOR2 &v)
    {
        x += v.x;
        y += v.y;
    }

    /**
     * @brief operator *
     * @param v
     * @return
     */
    VECTOR2 operator *(const VECTOR2 &v)
    {
        return VECTOR2(x * v.x, y * v.y);
    }

    /**
     * @brief operator *
     * @param a
     * @return
     */
    VECTOR2 operator *(const float &a)
    {
        return VECTOR2(x * a, y * a);
    }

    /**
     * @brief operator *=
     * @param a
     * @return
     */
    VECTOR2 operator *=(const float &a)
    {
        return VECTOR2(x * a, y * a);
    }

    /**
     * @brief operator /
     * @param a
     * @return
     */
    VECTOR2 operator /(const float &a)
    {
        if (x != 0.0f) {
            return VECTOR2(x / a, y / a);
        }
        else {
            return VECTOR2(x, y);
        }
    }

    /**
     * @brief operator /=
     * @param v
     */
    void operator /=(const VECTOR2 &v)
    {
        x /= v.x;
        y /= v.y;
    }

    /**
    * @brief operator /=
    * @param v
    */
    void operator /=(const float &a)
    {
        x /= a;
        y /= a;
    }

    /**
     * @brief operator ==
     * @param v
     * @return
     */
    bool operator ==(const VECTOR2 &v)
    {
        return (v.x == x) && (v.y == y);
    }
    
    /**
     * @brief LengthSq
     * @return
     */
    float LengthSq()
    {
        return x * x + y * y;
    }

    /**
     * @brief Length
     * @return
     */
    float Length()
    {
        return sqrtf(x * x + y * y);
    }

    /**
     * @brief Normalize
     * @param pOut
     * @return
     */
    VECTOR2 *Normalize(VECTOR2 *pOut)
    {
    #ifdef _NORMALIZATIONPOINTER_CHECK
        if (pOut == NULL) {
            pOut = new VECTOR2(x, y);
        }
    #endif
        pOut->x = x;
        pOut->y = y;

        pOut->Normalize();
        return pOut;
    }

    /**
     * @brief Normalize
     * @return
     */
    void Normalize()
    {
        float length = x * x + y * y;

        if (length > 0.0f) {
            length = sqrtf(length);
            x /= length;
            y /= length;
        }
        else {
    #ifdef _DEBUG_POINER_CHECK
            printf("VECTOR2::Normalize(): Normalization Error!\n");
    #endif
        }
    }
    
    /**
     * @brief Dot
     * @param a
     * @param b
     * @return
     */
    static float Dot(const VECTOR2 *a, const VECTOR2 *b)
    {
        return (a->x * b->x + a->y * b->y);
    }
    
    /**
     * @brief Distance
     * @param a
     * @param b
     * @return
     */
    static float Distance(const VECTOR2 *a, const VECTOR2 *b)
    {
        VECTOR2 c;
        c.x = a->x - b->x;
        c.y = a->y - b->y;
        return sqrtf(c.x * c.x + c.y * c.y);
    }
    
    /**
     * @brief DistanceSq
     * @param a
     * @param b
     * @return
     */
    static float DistanceSq(const VECTOR2 *a, const VECTOR2 *b)
    {
        VECTOR2 c;
        c.x = a->x - b->x;
        c.y = a->y - b->y;
        return c.x * c.x + c.y * c.y;
    }

    /**
    * @brief Print prints the vector.
    * @param vec
    * @return
    */
    void Print() const
    {
        std::printf(" %f %f\n", x, y);
    }


    /**
     * @brief fscanf for a VECTOR2.
     * @param file
     * @param vet
     */
    void Filescanf(FILE* file)
    {
        auto retx = std::fscanf(file, "%f", &x);
        auto rety = std::fscanf(file, "%f", &y);
    }
};

//Zeros VECTOR3
const VECTOR2 Vec2Zero = VECTOR2(0.0f);

//Ones VECTOR3
const VECTOR2 Vec2One = VECTOR2(1.0f);

}

#endif //BNT3D_VECTOR2_HPP
