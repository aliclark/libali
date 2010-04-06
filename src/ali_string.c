/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
 *  ali_string.c
 *
 *  Copyright (C) 2008  Ali Clark
 */

#include <string.h>

#include "ali_string.h"
#include "ali_macros.h"
#include "ali_memory.h"
#include "ali_io.h"

/*---------------------------------------------------------------------------*/

char *string_copy (      char   *dest,
                   const char   *src,
                   const size_t  dest_size)
{
	const size_t copy_len = strlen( src);

	string_ensure_space( copy_len, dest_size);

	strncpy( dest, src, copy_len);
	*(dest + copy_len) = '\0';
	return dest + copy_len;
}

/*---------------------------------------------------------------------------*/

char *string_clone (const char *src)
{
	const size_t src_len = strlen( src);
	TALLOCATED( char, copy, src_len + 1);
	strcpy( copy, src);
	return copy;
}

/*---------------------------------------------------------------------------*/

int string_compare_min (const char *a, const char *b)
{
	const size_t a_len = strlen( a);
	const size_t b_len = strlen( b);

	return strncmp( a, b, MIN( a_len, b_len));
}

/*---------------------------------------------------------------------------*/

void string_ensure_space (const size_t src_len, const size_t dest_size)
{
	if ((src_len + 1) > dest_size) {
		/* We ran out of space. */
		error_no_space();
	}
}

/*---------------------------------------------------------------------------*/

void string_overwrite (      char   *dest,
                       const char   *src,
                       const size_t  dest_size)
{
	char *dest_end = string_copy( dest, src, dest_size) + 1;

	/* THIS IS PROBABLY ILLEGAL FOR UTF8! */
	for (; *dest_end && (dest_end < (dest + dest_size)); ++dest_end) {
		*dest_end = '\0';
	}
}

/*---------------------------------------------------------------------------*/

void string_concatenate (      char   *dest,
                         const char   *src,
                         const size_t  dest_size)
{
	const size_t dest_len = strlen( dest);
	const size_t src_len = strlen( src);

	string_ensure_space( src_len + dest_len, dest_size);
	strcat( dest, src);
}

/*---------------------------------------------------------------------------*/

