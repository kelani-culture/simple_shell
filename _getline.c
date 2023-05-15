#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
/**
 * _getline - Reads a line from the specified stream.
 * @line: Pointer to the buffer that will store the line.
 * @n: Pointer to the size of the buffer.
 * @stream: The stream to read from.
 *
 * Return: The number of characters read.
 */

ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;
	char *newLine;

	if (*line == NULL || *n == 0)
	{
		*n = BUF_SIZE;
		*line = malloc(*n);
		if (*line == NULL)
			return (-1);
	}
	while (1)
	{
		if (pos >= *n)
		{
			*n += BUF_SIZE;
			newLine = custom_realloc(*line, *n);
			if (newLine == NULL)
				return (-1);
			*line = newLine;
		}
		c = getc(stream);
		if (c == EOF)
		{
			if (pos == 0)
				return (-1);
			break;
		}
		(*line)[pos] = c;
		pos++;
		if (c == '\n')
			break;
	}
	(*line)[pos] = '\0';
	return (pos);
}
