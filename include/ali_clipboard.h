
/*
 *  ali_clipboard.h
 *
 *  Copyright (C) 2008  Ali Clark
 */

#ifndef _ALI_CLIPBOARD_H
#define _ALI_CLIPBOARD_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

void clipboard_retrieve (char *dest, const size_t dest_size);

#ifdef __cplusplus
}
#endif

#endif /* _ALI_CLIPBOARD_H */

