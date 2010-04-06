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
 *  ali_typedefs.h
 */

#ifndef _ALI_TYPEDEFS_H
#define _ALI_TYPEDEFS_H

#ifndef __GNUC__
#  define __inline__        inline
#  define __attribute__(x)  /*0*/
#endif /* !__GNUC__ */

#ifndef __cplusplus
typedef enum {false, true} bool;
#endif /* !__cplusplus */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   char  s8;
typedef signed   short s16;
typedef signed   int   s32;

#endif /* _ALI_TYPEDEFS_H */

