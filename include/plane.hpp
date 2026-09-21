/**
*     Copyright (C) 2025 Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_PLANE_HPP
#define BNT3D_PLANE_HPP

namespace bnt3d{

/**
 * @brief The D3DXPLANE class
 */
class PLANE
{
public:
    float a, b, c, d;
    
    /**
     * @brief PLANE
     */
    PLANE()
    {
        a = 0.0f;
        b = 1.0f;
        c = 0.0f;
        d = 0.0f;
    }
    
    /**
     * @brief Init
     * @param a
     * @param b
     * @param c
     * @param d
     */
    void Init(float a, float b, float c, float d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
};

}

#endif //BNT3D_PLANE_HPP
