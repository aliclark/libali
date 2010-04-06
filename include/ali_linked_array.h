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
 *  ali_linked_array.h
 *
 *  Copyright (C) 2009  Ali Clark
 */

#ifndef _ALI_LINKED_ARRAY_H
#define _ALI_LINKED_ARRAY_H

#include <stdlib.h> /* size_t */

#define LINKED_ARRAY_GET( type, list, index) \
  *((type *) linked_array_get( list, index))

#define LINKED_ARRAY_SET( type, list, index, value) \
  LINKED_ARRAY_GET( type, list, index) = value

#define LINKED_ARRAY_GROW( list, size) \
  list = linked_array_grow( list, size)

#define LINKED_ARRAY_SHRINK( list) \
  list = linked_array_shrink( list)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Please do not allocate one of these yourself;
 * use linked_array_allocate if you want one.
 */
struct linked_array {
	void *array; /* The block of allocated memory for array contents. */
	size_t size; /* The size in bytes of each element in the array. */
	size_t max; /* The max capacity of the array memory for this head. */
	struct linked_array *rest; /* The other half of the linked_array. */
};

/*
 * Will return a pointer to the index of the linked_list in O(log n) time.
 * This pointer can then be used with a cast to read or write its contents.
 */
void *linked_array_get (const struct linked_array *list, unsigned int index);

/*
 * Allocates another head for the linked_array with twice the capacity of
 * the head of the supplied linked_array. The new head has elements
 * each of size "size". Returns the newly allocated linked_array.
 */
struct linked_array *linked_array_grow (const struct linked_array *list,
				        size_t size);

/*
 * If you have dynamically grown the linked_array using linked_array_grow,
 * you can use this procedure to free the top half of the linked_array again,
 * effectively reversing the last growth.
 * This will halve the size of your linked_array.
 * The return value is the rest of the linked_array.
 */
struct linked_array *linked_array_shrink (struct linked_array *list);

/*
 * Create a new linked_array with "start" being the
 * number of elements in the array, and "size" being the number of bytes
 * used to store each element.
 * You must use this procedure if you want a new linked_array, you cannot
 * simply allocate one from the struct.
 */
struct linked_array *linked_array_allocate (size_t size, unsigned int start);

/*
 * If you were using the linked_array to hold pointers to objects
 * you allocated yourself, you must free them yourself;
 * linked_array_free will only free the memory it has allocated itself.
 */
void linked_array_free (struct linked_array *list);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _ALI_LINKED_ARRAY_H */

