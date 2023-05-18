#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * _strtok - Tokenizes a string by a delimiter.
 *
 * @str: The string to tokenize.
 * @delim: The delimiter to use for tokenization.
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token = NULL;
	int i, j;

	if (str == NULL)
		str = last_token;
	/* Skip leading delimiter characters */
	for (i = 0; str[i] && _strchr(delim, str[i]); i++)
		;
	/* No more tokens */
	if (!str[i])
		return (NULL);
	/* Find the end of the token */
	for (j = i; str[j] && !_strchr(delim, str[j]); j++)
		;
	if (str[j])
	{
		/* Null-terminate the token */
		str[j] = '\0';
		last_token = &str[j + 1];
	}
	else
	{
		/* No more tokens after this one */
		last_token = NULL;
	}

	return (&str[i]);
}
