#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry points of the simpple shell program
 * @argv: argument command
 * Return: 0 success
 */


int main(int argc, char *argv[])
{
	char command[BUF_SIZE], *args[BUF_SIZE];
	ssize_t read_size;
	pid_t pid;
	int status;
	extern char **environ;

	UNUSED(argc);
	while (1)
	{
		write_string(STDOUT_FILENO, "$ "); /*Display the prompt*/
		read_size = read(STDIN_FILENO, command, BUF_SIZE);
		if (read_size == -1)
			handle_error("Error reading input.", argv[0]);
		else if (read_size == 0)
		{
			write_string(STDOUT_FILENO, "\n"); /* Handle Ctrl+D */
			break;
		}
		command[read_size - 1] = '\0'; /* Remove trailing newline */
		if (_strlen(command) == 0)
			continue;  /* Empty command continue to iteration */

		pid = fork();
		if (pid == -1)
			handle_error("Error forking. ", argv[0]);
		else if (pid == 0)
		{
			/* child process */
			command_args(command, args, BUF_SIZE);
			if (execve(args[0], args, environ) == -1)	
				handle_error("", argv[0]);
		}
		else
		{
			if (wait(&status) == -1)
				handle_error("Error waiting for child process ",  argv[0]);
		}
	}
	return (0);
}
