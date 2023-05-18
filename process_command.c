#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "main.h"

/**
 * process_command - Process a command and execute it in a child process
 * @program_name: The name of the shell program
 * @command: The command to process and execute
 */

void process_command(const char *program_name, char *command)
{
	pid_t pid;
	int status;

	if (_strcmp(command, "exit") == 0)
		exit_shell(EXIT_SUCCESS);
	else if (_strncmp(command, "exit ", 5) == 0)
	{
		status = exit_status(command + 5);
		if (status != -1)
			exit_shell(status);
		else
		{
			write_string(STDERR_FILENO, "Invalid exit status: ");
			write_string(STDERR_FILENO, command + 5);
			write_string(STDERR_FILENO, "\n");
		}
	}
	pid = fork();
	if (pid == -1)
	{
		perror(program_name);
	}
	else if (pid == 0)
	{
		/* Child process */
		execute_command(command);
	}
	else
	{
		/* Parent process */
		if (wait(&status) == -1)
		{
			perror(program_name);
		}
	}
}
