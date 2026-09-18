/**
*     BNT3D
*     A Computer Graphics math library
*     Copyright (C) 2025  Francesco Banterle
*
*     This Source Code Form is subject to the terms of the Mozilla Public
*     License, v. 2.0. If a copy of the MPL was not distributed with this
*     file, You can obtain one at http://mozilla.org/MPL/2.0/.
**/

#ifndef BNT3D_MACROS_HPP
#define BNT3D_MACROS_HPP

#include <math.h>

namespace bnt3d{

#define INLINE inline

#ifndef MIN
    #define MIN(a, b)       (a < b ? a : b)
#endif

#ifndef MAX
    #define MAX(a, b)       (a > b ? a : b)
#endif

#ifndef ABS
    #define ABS(a)          (a > 0 ? a : -a)
#endif

#ifndef CLAMP
    #define CLAMP(x, a)     ( x >= a ? (a-1) : (x < 0 ? 0 : x))
#endif

#ifndef CLAMPi
    #define CLAMPi(x, a, b) (x < a ? a : (x > b ? b : x))
#endif

/**
 * @log_base logarithm given a base
 * @param x
 * @param base
 * @return log_{base}(x)
 */
inline float log_base(float x, float base)
{
    return logf(x) / logf(base);
}

/**
 * @brief madfrac computes the fractional part of a * b
 * @param a
 * @param b
 * @return the fractional part
 */
inline float madfrac(float a, float b)
{
    float tmp = a * b;
    return float(tmp - floorf(tmp));
}

/**
 * @sinacos computes sinf(acosf(x) efficiently
 * @param x
 * @return sinf(acosf(x)) using trigonometry
 */
inline float sinacos(float x)
{
    return sqrtf(MAX(1.0f - x * x, 0.0f));
}

/**
 * @sinc computes sinc(x) = sin(x)/x function
 * @param x
 * @return sin(x)/x
 */
inline static float sinc(float x)
{
    return (fabs(x) < 1e-6f) ? 1.0f : sinf(x) / x;
}

}
#endif //BNT3D_MACROS_HPP
