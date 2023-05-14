#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * find_command - Finds the full path of the command
 *	* using the PATH environment variable.
 * @command: The command to find.
 * @fullPath: The buffer to store the full path.
 * @buffer_size: The size of the buffer.
 *
 * Return: 1 if the command is found, 0 otherwise.
 */

int find_command(char *command, char *fullPath, int buffer_size)
{
	char *path, *path_copy, *dir;
	int access_result;

	path = getenv("PATH");
	if (path == NULL)
		return (0);

	path_copy = malloc(BUF_SIZE);
	if (path_copy == NULL)
		handle_error("Memory allocation error", "find_command");
	_strncpy(path_copy, path, BUF_SIZE);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(fullPath, buffer_size, "%s/%s", dir, command);
		access_result = access(fullPath, X_OK);
		if (access_result != -1)
		{
			free(path_copy);
			return (1);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}
