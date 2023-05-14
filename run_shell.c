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
 */

void run_shell (const char *program_name)
{
	char command[BUF_SIZE];
	pid_t pid;
	ssize_t read_size;
	int status;

	while (1)
	{
		write_string(STDOUT_FILENO, "$ ");
		read_size = read(STDIN_FILENO, command, BUF_SIZE);
		if (read_size == -1)
			handle_error("ERROR reading input ", program_name);
		else if (read_size == 0)
		{
			write_string(STDOUT_FILENO, "\n");
			break;
		}
		command[read_size - 1] = '\0';
		if (_strcmp(command, "exit") == 0)
			exit_shell();
		pid = fork();
		if (pid == -1)
			handle_error("Error forking ", program_name);
		else if (pid == 0)
		{
			/* child process */
			execute_command(command);
		}
		else
		{
			/* parent process */
			if (wait(&status) == -1)
				handle_error("Error waiting for child  process. ", program_name);
		}
	}
}
