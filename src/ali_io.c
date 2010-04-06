/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/*
 *  ali_io.c
 *
 *  Copyright (C) 2008  Ali Clark
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ali_io.h"

/*---------------------------------------------------------------------------*/

void get_string (char *puts, const size_t num)
{
	size_t len = 0;
	puts = fgets( puts, (int) num, stdin);

	if (!puts) {
		exit( EXIT_SUCCESS);
	}
	len = strlen( puts);

        /* We ran out of space. */
	if (len == (num - 1)) {
		error_no_space();
	}
	if (len != 0) {
		/* Remove new line from input. */
		*(puts + (len - 1)) = '\0';
	}
	*(puts + len) = 0;
}

/*---------------------------------------------------------------------------*/

void error_no_space (void)
{
	perror( "The inputted text was too long");
	exit( EXIT_FAILURE);
}

/*---------------------------------------------------------------------------*/

void prompt_get (const char *str, char *into, const size_t num)
{
	printf( "\n%s\n\n", str);
	get_string( into, num);
}

/*---------------------------------------------------------------------------*/

void printn (const char *str)
{
	printf( "%s\n", str);
}

/*---------------------------------------------------------------------------*/

