
/*
 *  ali_binary_search.h
 *
 *  Copyright (C) 2008  Ali Clark
 */

#ifndef _ALI_BINARY_SEARCH_H
#define _ALI_BINARY_SEARCH_H

#ifdef __cplusplus
extern "C" {
#endif

/* lower starts at 0, upper is n - 1. They are inclusive. */
int binary_search (   const int *list,
                            int  value,
                   unsigned int  lower,
                   unsigned int  upper);

#ifdef __cplusplus
}
#endif

#endif /* _ALI_BINARY_SEARCH_H */

