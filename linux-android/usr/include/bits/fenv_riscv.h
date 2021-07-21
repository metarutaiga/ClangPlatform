/*-
 * Copyright (c) 2004-2005 David Schultz <das@FreeBSD.ORG>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD: src/lib/msun/riscv/fenv.h,v 1.5 2005/03/16 19:03:45 das Exp $
 */

#pragma once

#include <sys/types.h>

__BEGIN_DECLS

enum
  {
    FE_INEXACT   =
#define FE_INEXACT	(0x01)
      FE_INEXACT,
    FE_UNDERFLOW =
#define FE_UNDERFLOW	(0x02)
      FE_UNDERFLOW,
    FE_OVERFLOW  =
#define FE_OVERFLOW	(0x04)
      FE_OVERFLOW,
    FE_DIVBYZERO =
#define FE_DIVBYZERO	(0x08)
      FE_DIVBYZERO,
    FE_INVALID   =
#define FE_INVALID	(0x10)
      FE_INVALID
  };

#define FE_ALL_EXCEPT \
	(FE_INEXACT | FE_DIVBYZERO | FE_UNDERFLOW | FE_OVERFLOW | FE_INVALID)

enum
  {
    FE_TONEAREST  =
#define FE_TONEAREST	(0x0)
      FE_TONEAREST,
    FE_TOWARDZERO =
#define FE_TOWARDZERO	(0x1)
      FE_TOWARDZERO,
    FE_DOWNWARD   =
#define FE_DOWNWARD	(0x2)
      FE_DOWNWARD,
    FE_UPWARD     =
#define FE_UPWARD	(0x3)
      FE_UPWARD
  };

typedef unsigned int fexcept_t;
typedef unsigned int fenv_t;

__END_DECLS
