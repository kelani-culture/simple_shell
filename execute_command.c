#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include <sys/wait.h>

/**
 * execute_command - execture command
 * @command: command
 */


void execute_command(char *command)
{
	char *args[BUF_SIZE];
	char full_path[BUF_SIZE];

	command_args(command, args, BUF_SIZE);
	if (find_command(args[0], full_path, BUF_SIZE))
	{
		execve(full_path, args, environ);
		handle_error("command execution failed.");
	}
	else
	{
		perror(command);
		_exit(EXIT_FAILURE);
	}
}

/**
 * is_builtin_command - check for a builtin command
 * @command: command
 * Return: 1 on success 0 on failure
 */
int is_builtin_command(const char *command)
{
	if (_strcmp(command, "exit") == 0 ||
		_strncmp(command, "exit ", 5) == 0 ||
		_strncmp(command, "setenv ", 7) == 0 ||
		_strncmp(command, "unsetenv ", 9) == 0)
	{
		return (1);
	}
	return (0);
}
