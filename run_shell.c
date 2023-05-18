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

	while (1)
	{
		write_string(STDOUT_FILENO, "$ ");
		read_size = _getline(&command, &bufsize, stdin);
		if (read_size == -1)
		{
			if (feof(stdin))
			{
				write_string(STDOUT_FILENO, "\n");
				break;
			}
			else
			{
				handle_error("Error reading input.", program_name);
			}
		}

		command[read_size - 1] = '\0';
		process_command(program_name, command);
	}
	free(command);
}
