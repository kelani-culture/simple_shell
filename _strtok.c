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
unsigned int is_delim(char str, char *delim);

char *_strtok(char *str, char *delim)
{
	static char *strBackup;
	char *ret;

	if (!str)
		str = strBackup;
	if (!str)
		return (NULL);
	while (1)
	{
		if (is_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}
	ret = str;
	while (1)
	{
		if (*str == '\0')
		{
			strBackup = str;
			return (ret);
		}
		if (is_delim(*str, delim))
		{
			*str = '\0';
			strBackup = str + 1;
			return (ret);
		}
		str++;
	}
}

/**
 * is_delim - checks if the delimeter exists
 * @str: string to check from
 * @delim: the delimeter to use to split
 * Return: 0 if the delim does not match
 * 	* else 1 if it exists
 */

unsigned int is_delim(char str, char *delim)
{
	while (*delim != '\0')
	{
		if (str  == *delim)
			return (1);
		delim++;
	}
	return (0);
}
