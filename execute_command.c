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
		handle_error("Command execution failed.", "$");
	}
	else
	{
		write_string(STDERR_FILENO, "command not found\n");
		_exit(EXIT_FAILURE);
	}
}
