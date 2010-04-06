
/*
 *  ali_utf8.h
 *
 */

#ifndef _ALI_UTF8_H
#define _ALI_UTF8_H

#include <stdarg.h>
#include <sys/types.h>

#include "../include/ali_typedefs.h"

/* is c the start of a utf8 sequence? */
#define IS_UTF(c) (((c)&0xC0)!=0x80)

#ifdef __cplusplus
extern "C" {
#endif

/* convert UTF-8 data to wide character */
int u8_toucs (u_int32_t *dest, const size_t sz, const char *src, int srcsz);

/* the opposite conversion */
int u8_toutf8 (char *dest, const size_t sz, const u_int32_t *src, int srcsz);

/* single character to UTF-8 */
int u8_wc_toutf8 (char *dest, const u_int32_t ch);

/* character number to byte offset */
int u8_offset (const char *str, int charnum);

/* byte offset to character number */
int u8_charnum (const char *s, const int offset);

/* return next character, updating an index variable */
u_int32_t u8_nextchar (const char *s, int *i);

/* move to next character */
void u8_inc (const char *s, int *i);

/* move to previous character */
void u8_dec (const char *s, int *i);

/* returns length of next utf-8 sequence */
size_t u8_seqlen (const char *s);

/* assuming src points to the character after a backslash, read an
   escape sequence, storing the result in dest and returning the number of
   input characters processed */
int u8_read_escape_sequence (const char *src, u_int32_t *dest);

/* given a wide character, convert it to an ASCII escape sequence stored in
   buf, where buf is "sz" bytes. returns the number of characters output. */
int u8_escape_wchar (char *buf, const size_t sz, const u_int32_t ch);

/* convert a string "src" containing escape sequences to UTF-8 */
int u8_unescape (char *buf, const size_t sz, const char *src);

/* convert UTF-8 "src" to ASCII with escape sequences.
   if escape_quotes is nonzero, quote characters will be preceded by
   backslashes as well. */
int u8_escape (char *buf, const size_t sz, const char *src,
                                                      const int escape_quotes);

/* utility predicates used by the above */
bool octal_digit (const char c);
bool hex_digit (const char c);

/* return a pointer to the first occurrence of ch in s, or NULL if not
   found. character index of found character returned in *charn. */
char *u8_strchr (char *s, const u_int32_t ch, int *charn);

/* same as the above, but searches a buffer of a given size instead of
   a NUL-terminated string. */
char *u8_memchr (char *s, u_int32_t ch, size_t sz, int *charn);

/* count the number of characters in a UTF-8 string */
int u8_strlen (const char *s);

bool u8_is_locale_utf8 (const char *locale);

/* printf where the format string and arguments may be in UTF-8.
   you can avoid this function and just use ordinary printf() if the current
   locale is UTF-8. */
int u8_vprintf (const char *fmt, va_list ap);
int u8_printf (const char *fmt, ...);

char *get_utf8_input (const size_t len);

#ifdef __cplusplus
}
#endif

#endif /* _ALI_UTF8_H */

