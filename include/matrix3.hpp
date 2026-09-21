/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_MATRIX3_HPP
#define BNT3D_MATRIX3_HPP

#include <cstring>
#include <cstdio>

namespace bnt3d {

/**
 * @brief The MATRIX3 class
 */
class MATRIX3
{
public:
    float data[9];
    
    /**
     * @brief MATRIX3
     */
    MATRIX3()
    {
        Identity();
    }
    
    /**
     * @brief MATRIX3
     * @param data
     */
    MATRIX3(float *data)
    {
        if (data != NULL) {
            memcpy(this->data, data, 9 * sizeof(float));
        }
    }

    /**
     * @brief Zeros
     */
    void Zeros()
    {
        for (int i = 0; i < 9; i++) {
            data[i] = 0.0f;
        }
    }

    
    /**
     * @brief Identity
     */
    void Identity()
    {
        data[0] = 1.0f;
        data[1] = 0.0f;
        data[2] = 0.0f;
        
        data[3] = 0.0f;
        data[4] = 1.0f;
        data[5] = 0.0f;
        
        data[6] = 0.0f;
        data[7] = 0.0f;
        data[8] = 1.0f;
    }
    
    /**
     * @brief Mul
     * @param vec
     * @param ret
     * @return
     */
    float* Mul(float *vec, float *ret)
    {
        if (vec == NULL) {
            return ret;
        }
        
        if (ret == NULL) {
            ret = new float[3];
        }
        
        ret[0] = data[0] * vec[0] + data[1] * vec[1] + data[2] * vec[2];
        ret[1] = data[3] * vec[0] + data[4] * vec[1] + data[5] * vec[2];
        ret[2] = data[6] * vec[0] + data[7] * vec[1] + data[8] * vec[2];
        
        return ret;
    }
    
    /**
     * @brief Add
     * @param diag
     */
    void Add(float diag)
    {
        data[0] += diag;
        data[4] += diag;
        data[8] += diag;
    }
    
    /**
     * @brief Determinant
     * @return
     */
    float Determinant()
    {
        return  data[0] * (data[4] * data[8] - data[5] * data[7]) -
                data[1] * (data[8] * data[3] - data[5] * data[6]) +
                data[2] * (data[3] * data[7] - data[4] * data[6]);
    }
    
    /**
     * @brief Trace
     * @return
     */
    float Trace()
    {
        return  data[0] + data[4] + data[8];
    }
    
    /**
     * @brief Inverse
     * @param inv
     * @return
     */
    MATRIX3 *Inverse(MATRIX3 *pOut)
    {
        if (pOut == NULL) {
            pOut = new MATRIX3();
        }
        
        float det = Determinant();
        if (fabsf(det) <= 1e-9f) {
            std::printf("MATRIX3::Inverse -- Error: Near to zero determinant\n");
            return pOut;
        }
        
        pOut->data[0] = (data[4] * data[8] - data[5] * data[7]) / det;
        pOut->data[1] = -(data[1] * data[8] - data[2] * data[7]) / det;
        pOut->data[2] = (data[1] * data[5] - data[2] * data[4]) / det;
        
        pOut->data[3] = -(data[3] * data[8] - data[5] * data[6]) / det;
        pOut->data[4] = (data[0] * data[8] - data[2] * data[6]) / det;
        pOut->data[5] = -(data[0] * data[5] - data[2] * data[3]) / det;
        
        pOut->data[6] = (data[3] * data[7] - data[4] * data[6]) / det;
        pOut->data[7] = -(data[0] * data[7] - data[1] * data[6]) / det;
        pOut->data[8] = (data[0] * data[4] - data[1] * data[3]) / det;
        
        return pOut;
    }
    
    /**
     * @brief Print
     */
    void Print()
    {
        for (int i = 0; i < 9; i++) {
            if ((i % 3) == 0)
                std::printf("\n");
            
            std::printf("%f \t", data[i]);
        }
        std::printf("\n");
    }
};

}

#endif //BNT3D_MATRIX3_HPP
