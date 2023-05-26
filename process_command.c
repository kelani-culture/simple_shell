#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * process_command - Process a command and execute it in a child process
 * @program_name: The name of the shell program
 * @command: The command to process and execute
 * @interactive_mode: interactive mode of the shell
 */

int last_command_status = 0;

void process_command(const char *program_name, char *command, int interactive_mode)
{
	if (is_builtin_command(command))
	{
		handle_builtin_command(program_name, command, interactive_mode);
	}
	else
	{
		execute_external_command(program_name, command, interactive_mode);
	}
}

int get_last_command_status(const char *program_name, char *command, int interactive_mode)
{
	UNUSED(program_name);
	UNUSED(command);
	UNUSED(interactive_mode);

	return (last_command_status);
}
/**
 * execute_external_command - Executes an external command in a child process
 * @program_name: The name of the shell program
 * @command: The command to execute
 * interactive_mode: interactive mode of the shell
 */

void execute_external_command(const char *program_name, char *command, int interactive_mode)
{
	pid_t pid = fork();

	if (pid == -1)
		handle_error("Error forking.");

	else if (pid == 0)
	{
		/* Child process */
		if (!interactive_mode)
		{
			/* Redirect stdin from /dev/null in non-interactive mode */
			int dev_null = open("/dev/null", O_RDONLY);
			if (dev_null == -1)
			{
				handle_error("Error opening /dev/null.");
				_exit(EXIT_FAILURE);
			}
			dup2(dev_null, STDIN_FILENO);
			close(dev_null);
		}
		execute_command(command);
		_exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;
		if (wait(&status) == -1)
			perror(program_name);
		else
		{
			if (WIFEXITED(status))
					last_command_status = WEXITSTATUS(status);
				else
					last_command_status = -1;
		}
	}
}

/**
 * handle_builtin_command - Handles execution of built-in commands
 * @program_name: The name of the shell program
 * @command: The command to handle
 * @interactive_mode: interactive mode
 */

void handle_builtin_command(const char *program_name, char *command, int interactive_mode)
{
	if (_strcmp(command, "exit") == 0 || _strncmp(command,"exit ", 5) == 0)
	{
		int status = exit_status(command + 5);
		if (interactive_mode && (_strncmp(command, "exit ", 5) != 0))
			exit_shell(EXIT_SUCCESS);
		else if (interactive_mode && (_strncmp(command,"exit ", 5) == 0))
		{
			check_status(program_name, command, status);
		}
		check_status(program_name, command, status);
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
		execute_external_command(program_name, command, interactive_mode);
}

/**
 * handle_logical_operator - handle both shell logical operator && ||
 * @program_name: program_name
 * @command: command
 * @interactive_mode: shell mode
 */

void handle_logical_operator(const char *program_name, char *command, int interactive_mode)
{
	char *operator = strstr(command, "&&");

	if (operator != NULL)
	{
		*operator = '\0';
		operator += 2;  /* Move past the '&&' operator */
		process_command(program_name, command, interactive_mode);
		if (get_last_command_status(program_name, command, interactive_mode) == 0)
			handle_logical_operator(program_name, operator, interactive_mode);
	}
	else
	{
		operator = strstr(command, "||");
		if (operator != NULL)
	{
			*operator = '\0';
			operator += 2;  /* Move past the '||' operator */
			process_command(program_name, command, interactive_mode);
			if (get_last_command_status(program_name, command, interactive_mode) != 0)
				handle_logical_operator(program_name, operator, interactive_mode);
		}
	else
			process_command(program_name, command, interactive_mode);
	}
}


/*
 * handle_semicolon - for handling the semicolons command separator
 * @program_name: name of program
 * @command: command
 * @interactive_mode: mode of the shell
 */

void handle_semicolon_commands(const char *program_name, char *commands, int interactive_mode)
{
	const char *separator = ";";
	char *token;
	char *saveptr;

	token = strtok_r(commands, separator, &saveptr);
	while (token != NULL)
	{
		if (strlen(token) > 0)
			handle_logical_operator(program_name, token, interactive_mode);
		token = strtok_r(NULL, separator, &saveptr);
	}
}
