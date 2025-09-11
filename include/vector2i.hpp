/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_VECTOR2I_HPP
#define BNT3D_VECTOR2I_HPP

namespace bnt3d {

/**
 * @brief The VECTOR2I class
 */
class VECTOR2I
{
public:
    int x, y;
    
    /**
     * @brief VECTOR2I
     */
    VECTOR2I()
    {
        x = 0;
        y = 0;
    }
    
    /**
     * @brief VECTOR2I
     * @param x
     * @param y
     */
    VECTOR2I(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    /**
     * @brief isTheSame
     * @param a
     * @return
     */
    bool isTheSame(const VECTOR2I &a)
    {
        return ((a.x == x) && (a.y == y));
    }
    
    /**
     * @brief Clip cipls the vector in the bounding box [0, width - 1] x [0, height - 1]
     * @param width
     * @param height
     */
    void clip(int width, int height)
    {
        //X clipping
        x = x > (width - 1) ? (width - 1) : x;
        x = x < 0 ? 0 : x;
        
        //Y clipping
        y = y > (height - 1) ? (height - 1) : y;
        y = y < 0 ? 0 : x;
    }
};

}

#endif //BNT3D_VECTOR2I_HPP
