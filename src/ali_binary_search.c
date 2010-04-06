/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
 *  ali_binary_search.c
 *
 *  Copyright (C) 2008  Ali Clark
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "ali_binary_search.h"
#include "ali_memory.h"
#include "ali_typedefs.h"

static unsigned   int  mid_length (unsigned int length) __attribute__((const));
static __inline__ void redo_bounds (         int  diff,
                                    unsigned int *lower,
                                    unsigned int *upper,
                                    unsigned int  mid);

/*---------------------------------------------------------------------------*/

static unsigned int mid_length (unsigned int length)
{
	return floor( length / 2);
}

/*---------------------------------------------------------------------------*/

static __inline__ void redo_bounds (         int  diff,
                                    unsigned int *lower,
                                    unsigned int *upper,
                                    unsigned int  mid)
{
	unsigned int *bnd = NIL;

	if (diff) {
		bnd = (diff > 0) ? upper : lower;
		*bnd = (diff > 0) ? mid - 1 : mid + 1;
	}
}

/*---------------------------------------------------------------------------*/

int binary_search (   const int *list,
                            int  value,
                   unsigned int  lower,
                   unsigned int  upper)
{
	unsigned int mid = mid_length( upper - lower) + lower;
	int diff = list[mid] - value;

	/* recalculate bounds */
	redo_bounds( diff, &lower, &upper, mid);

	return (diff) ?
	  (((lower > upper) || (value < list[lower])) ?
	    -1 :
	    binary_search( list, value, lower, upper)) :
	  (int) mid;
}

/*---------------------------------------------------------------------------*/

