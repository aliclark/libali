/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
 *  ali_clipboard.c
 *
 *  Copyright (C) 2008  Ali Clark
 */

#include <string.h>

#ifdef _WIN32
#  include <windows.h>
#endif /* _WIN32 */

#include "ali_clipboard.h"
#include "ali_string.h"
#include "ali_memory.h"

/*
 * I think GlobalLock() returns allocated mem which we need to freed,
 * though MicroSoft's docs are nice and vague.
 * In any case, you should assume that you need to free the pointer returned.
 */
static char *read_clipboard (void);

/*---------------------------------------------------------------------------*/

static char *read_clipboard (void)
{
	char *rv = NIL;

#ifdef _WIN32
	const int ok = OpenClipboard( NIL);
	if (ok) {
		HANDLE data = GetClipboardData( CF_TEXT);
		rv = (char *) GlobalLock( data);
		GlobalUnlock( data);
		CloseClipboard();
	}
#endif /* _WIN32 */

	return rv;
}

/*---------------------------------------------------------------------------*/

void clipboard_retrieve (char *addrptr, const size_t memlength)
{
	char *clipboardptr = read_clipboard();

	if (clipboardptr) {
		string_copy( addrptr, clipboardptr, memlength);
		FREE( clipboardptr);
	}
}

/*---------------------------------------------------------------------------*/

