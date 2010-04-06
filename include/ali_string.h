
/*
 *  ali_string.h
 *
 *  Copyright (C) 2008  Ali Clark
 */

#ifndef _ALI_STRING_H
#define _ALI_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

void  string_ensure_space (const size_t src_len, const size_t dest_size);

/* WARNING: Users of this function must free the ptr when finished. */
char *string_clone       (const char *src);

/* Compare the whole of the smaller with same length of bigger string. */
int   string_compare_min (const char *a, const char *b);

/* Makes sure any previous chars in dest past src's length are set null. */
void  string_overwrite   (char *dest, const char *src, const size_t dest_size);
void  string_concatenate (char *dest, const char *src, const size_t dest_size);

/*
 * Does not fill null bytes past the copied string.
 * Returns position of the NUL char at end of destination.
 */
char *string_copy        (char *dest, const char *src, const size_t dest_size);

#ifdef __cplusplus
}
#endif

#endif /* _ALI_STRING_H */

