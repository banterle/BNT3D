/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_VECTOR3I_HPP
#define BNT3D_VECTOR3I_HPP

namespace bnt3d{

/**
 * @brief The VECTOR3I class
 */
class VECTOR3I
{
public:
    int x, y, z;

    /**
     * @brief VECTOR3I
     */
    VECTOR3I()
    {
        x = y = z = 0;
    }

    /**
     * @brief VECTOR3I
     * @param x
     * @param y
     * @param z
     */
    VECTOR3I(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /**
     * @brief checkSame chekcs if two vectors are the same.
     * @param a
     * @return
     */
    bool checkSame(const VECTOR3I &a)
    {
        return ((a.x == x) && (a.y == y) && (a.z == z));
    }

    /**
     * @brief operator []
     * @param i
     * @return
     */
    int operator [](int i) const
    {
        switch (i) {
        case 0:
            return x; break;
        case 1:
            return y; break;
        case 2:
            return z; break;
        }
        return -1;
    }

    /**
     * @brief operator []
     * @param i
     * @return
     */
    int &operator [](int i)
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
};

}

#endif //BNT3D_VECTOR3I_HPP
