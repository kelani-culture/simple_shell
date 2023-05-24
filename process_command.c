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
void execute_external_command(const char *program_name, char *command);
void handle_builtin_command(const char *program_name, char *command);

void process_command(const char *program_name, char *command)
{
	if (is_builtin_command(command))
		handle_builtin_command(program_name, command);
	else
		execute_external_command(program_name, command);
}

/**
 * execute_external_command - Executes an external command in a child process
 * @program_name: The name of the shell program
 * @command: The command to execute
 */

void execute_external_command(const char *program_name, char *command)
{
	pid_t pid = fork();

	if (pid == -1)
		handle_error("Error forking.");
	else if (pid == 0)
	{
		/* Child process */
		execute_command(command);
		_exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;

		if (wait(&status) == -1)
		{
			perror(program_name);
		}
	}
}

/**
 * handle_builtin_command - Handles execution of built-in commands
 * @program_name: The name of the shell program
 * @command: The command to handle
 */

void handle_builtin_command(const char *program_name, char *command)
{
	if (_strcmp(command, "exit") == 0)
		exit_shell(EXIT_SUCCESS);
	else if (_strncmp(command, "exit ", 5) == 0)
	{
		int status = exit_status(command + 5);

		if (status != -1)
			exit_shell(status);
		else
			handle_error("Invalid exit status.");
	}
	else if (_strncmp(command, "setenv ", 7) == 0)
	{
		char *variable = _strtok(command + 7, " ");
		char *value = _strtok(NULL, " ");

		shell_setenv(variable, value);
	}
	else if (_strncmp(command, "unsetenv ", 9) == 0)
	{
		char *variable = _strtok(command + 9, " ");

		shell_unsetenv(variable);
	}
	else if (_strncmp(command, "cd ", 3) == 0 || _strncmp(command, "cd", 2) == 0)
		shell_cd(program_name, command);
	else
		execute_external_command(program_name, command);
}
