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
 * run_shell - run the shell command
 * @program_name: name of the prog
 */

void run_shell(const char *program_name)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t read_size;
	int interactive_mode = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive_mode)
		{
			write_string(STDOUT_FILENO, "$ ");
		}

		read_size = _getline(&command, &bufsize, stdin);
		if (read_size == -1)
		{
			break;
		}
		command[read_size - 1] = '\0';
		handle_semicolon_commands(program_name, command, interactive_mode);
	}
	free(command);
}
