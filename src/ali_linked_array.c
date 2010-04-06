/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 *  ali_linked_array.c
 *
 *  Copyright (C) 2009  Ali Clark
 */

#include <stdlib.h> /* EXIT_FAILURE */
#include <stdio.h> /* perror */

#include "ali_linked_array.h"
#include "ali_memory.h"
#include "ali_typedefs.h"

/*
 * Initialises the members on the head of the structure.
 * size is the size of each element, and max is the number
 * of items we want to allocate for this head.
 */
static __inline__ void linked_array_initialise (struct linked_array *list,
						size_t size,
						size_t max);

/*
 * Frees the top half of the link_array array memory
 * and the structure of the linked_array head.
 */
static __inline__ void linked_array_free_head (struct linked_array *list);

/*---------------------------------------------------------------------------*/

static __inline__ void linked_array_initialise (struct linked_array *list,
						size_t size,
						size_t max)
{
	list->array = MALLOCATE( size * max);
	list->size = size;
	list->max = max;
	list->rest = NIL;
}

/*---------------------------------------------------------------------------*/

static __inline__ void linked_array_free_head (struct linked_array *list)
{
	FREE( list->array);
	FREE( list);
}

/*---------------------------------------------------------------------------*/

struct linked_array *linked_array_allocate (size_t size, unsigned int length)
{
	size_t max;
	STALLOCATED( struct linked_array, a);
	STALLOCATED( struct linked_array, b);

	length = (size_t) ceil_base2( length);
	max = (size_t) ((length == 1) ? 1 : (length / 2));
	
	linked_array_initialise( a, size, max);
	linked_array_initialise( b, size, max);

	b->rest = a;
	return b;
}

/*---------------------------------------------------------------------------*/

void linked_array_free (struct linked_array *list)
{
	if (list->rest) {
		linked_array_free( list->rest);
	}
	linked_array_free_head( list);
}

/*---------------------------------------------------------------------------*/

void *linked_array_get (const struct linked_array *list, unsigned int index)
{
	if (index >= (list->max * 2)) {
		perror( "Error: index outside of linked_array bounds.");
		exit( EXIT_FAILURE);
	}
	return (void *) ((index < list->max) ?
			 (list->rest ?
			  linked_array_get( list->rest, index) :
			  (((char *) list->array) + (index * list->size))) :
			 (((char *) list->array) +
			  ((index - list->max) * list->size)));
}

/*---------------------------------------------------------------------------*/

struct linked_array *linked_array_grow (const struct linked_array *list,
					size_t size)
{
	STALLOCATED( struct linked_array, a);

	linked_array_initialise( a, size, (list->max * 2));
	a->rest = list;
	return a;
}

/*---------------------------------------------------------------------------*/

struct linked_array *linked_array_shrink (struct linked_array *list)
{
	struct linked_array *rest = list->rest;

	if (!rest || !rest->rest) {
		perror( "Error: Tried to shrink linked_array "
			"beyond initial size.");
		exit( EXIT_FAILURE);
	}

	linked_array_free_head( list);
	return rest;
}

/*---------------------------------------------------------------------------*/

