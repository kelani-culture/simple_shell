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
	pid_t pid = fork();
	int status;

	if (_strcmp(command, "exit") == 0)
		exit_shell();

	if (pid == -1)
		handle_error("Error forking.", program_name);

	else if (pid == 0)
	{
		/* child process */
		execute_command(command);
	}
	else
	{
		if ((wait(&status) == -1))
			handle_error("Error waiting for child process.", program_name);
	}
}
