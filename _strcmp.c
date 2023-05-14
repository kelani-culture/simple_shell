#include "main.h"

/**
 * _strcmp - compare string together
 * @s1: string to compare
 * @s2: string from
 * Return: comparison beteween string
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
