
/*
 *  ali_macros.h
 *
 *  Copyright (C) 2008  Ali Clark
 */

#ifndef _ALI_MACROS_H
#define _ALI_MACROS_H

#define INT_MAX              ((int)(~0U>>1))
#define INT_MIN              (-INT_MAX - 1)
#define UINT_MAX             (~0U)
#define LONG_MAX             ((long)(~0UL>>1))
#define LONG_MIN             (-LONG_MAX - 1)
#define ULONG_MAX            (~0UL)
#define LLONG_MAX            ((long long)(~0ULL>>1))
#define LLONG_MIN            (-LLONG_MAX - 1)
#define ULLONG_MAX           (~0ULL)

#define __ALIGN_MASK(x,mask) (((x)+(mask))&~(mask))

#define FIELD_SIZEOF(t, f)   (sizeof(((t*)0)->f))
#define DIV_ROUND_UP(n,d)    (((n) + (d) - 1) / (d))
#define ROUNDUP(x,y)         ((((x) + ((y) - 1)) / (y)) * (y))

#define UPPER_32_BITS(n)     ((u32)(((n) >> 16) >> 16))

#define ABS(x) (((x) < 0) ? -(x) : (x))

#define MIN(x,y) (((x) < (y)) ? (x) : (y))

#define MAX(x,y) (((x) > (y)) ? (x) : (y))

#endif /* _ALI_MACROS_H */

