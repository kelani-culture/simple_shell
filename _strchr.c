#include <stdio.h>
#include "main.h"


/**
 * _strchr - Locates the first occurrence of a character in a string.
 *
 * @str: The string to search.
 * @c: The character to locate.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);

		str++;
	}

	if (c == '\0')
		return ((char *)str);

	return (NULL);
}
