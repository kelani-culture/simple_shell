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
 * @full_path: The buffer to store the full path.
 * @path_size: The size of the buffer.
 *
 * Return: 1 if the command is found otherwise  0
 */

int find_command(const char *command, char *full_path, size_t path_size)
{
	char *path, *path_copy, *token;

	path = getenv("PATH");
	if (path == NULL)
		return (-1);
	path_copy = malloc(strlen(path) + 1);
	if (path_copy == NULL)
		return (-1);

	_strncpy(path_copy, path, strlen(path) + 1);

	token = _strtok(path_copy, ":");
	while (token != NULL)
	{
		_strncpy(full_path, token, path_size - 1);
		_strncat(full_path, "/", path_size - strlen(full_path) - 1);
		_strncat(full_path, command, path_size - strlen(full_path) - 1);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (1);
		}
		token = _strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}

