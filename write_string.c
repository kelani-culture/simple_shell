#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * write_string - Writes a string to the specified file descriptor.
 * @fd: The file descriptor to write to.
 * @str: The string to write.
 */

void write_string(int fd, const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;
	write(fd, str, len);
}
