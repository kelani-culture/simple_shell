#include <stdio.h>
#include "main.h"


/**
 * _strncmp - Compare two strings up to n characters
 * @str1: The first string to compare
 * @str2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: Negative value if str1 is less than str2, positive value if str1 is
 * greater than str2, or 0 if both strings are equal up to n characters.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		else if (str1[i] == '\0')
			return (0);
	}

	return (0);
}
