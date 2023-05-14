#include "main.h"
#include <stddef.h>

/**
 * _strncpy - Copies at most n characters from
 *	* the source string to the destination string.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: The destination string.
 */

char *_strncpy(char *dest, const char *src, size_t n)
{

	char *dest_start = dest;

	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (dest_start);
}
