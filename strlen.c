#include <stdio.h>

/**
 * _strlen - countlength of string
 * @str: string to count
 * Return: lenght of char
 */



unsigned int _strlen(char *str)
{
	unsigned  int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
