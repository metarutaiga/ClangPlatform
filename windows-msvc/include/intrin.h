/* ===-------- intrin.h ---------------------------------------------------===
 *
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 *===-----------------------------------------------------------------------===
 */
#pragma once

#include_next <intrin.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__arm__) || defined(__aarch64__)
__inline double _CopyDoubleFromInt64(__int64 v)
{
    return *(double*)&v;
}
__inline float _CopyFloatFromInt32(__int32 v)
{
    return *(float*)&v;
}
__inline __int32 _CopyInt32FromFloat(float v)
{
    return *(__int32*)&v;
}
__inline __int64 _CopyInt64FromDouble(double v)
{
    return *(__int64*)&v;
}
#endif

#ifdef __cplusplus
}
#endif
