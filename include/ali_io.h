
/*
 *  ali_io.h
 *
 *  Copyright (C) 2008  Ali Clark
 */

#ifndef _ALI_IO_H
#define _ALI_IO_H

#ifdef __cplusplus
extern "C" {
#endif

void error_no_space (void);
void printn         (const char *line);
void get_string     (char *destination, const size_t max_size);
void prompt_get     (const char *prompt_txt, char *dest,
                                                        const size_t max_size);

#ifdef __cplusplus
}
#endif

#endif /* _ALI_IO_H */
