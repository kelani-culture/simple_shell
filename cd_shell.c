#include <unistd.h>
#include "main.h"
#include <limits.h>
#include <stdlib.h>
#define MAX_PATH_LENGTH PATH_MAX
/**
 * shell_cd - change shell directory
 * @program_name: name of the program
 * @command: command name
 */


void shell_cd(const char *program_name, char *command)
{
	char *arg = _strtok(command, " ");
	char previous_dir[PATH_MAX];
	char current_dir[PATH_MAX];

	getcwd(previous_dir, sizeof(previous_dir));
	arg = _strtok(NULL, " "); /* Get the directory argument */
	if (arg == NULL)
	{
		/* Handle "cd" */
		if (chdir(getenv("HOME")) == -1)
		{
			perror(program_name);
			return;
		}
	}
	else if (_strcmp(arg, "-") == 0)
	{
		/* Handle "cd -" */
		if (getenv("OLDPWD") != NULL)
		{
			/* Change to the previous directory */
			if (chdir(getenv("OLDPWD")) == -1)
			{
				perror(program_name);
				return;
			}
			getcwd(current_dir, sizeof(current_dir));
			write_string(STDOUT_FILENO, current_dir); /* Output the directory*/
			write_string(STDOUT_FILENO, "\n");
		}
		else
		{
			handle_error("No previous directory stored.");
			return;
		}
	}
	else
	{
		/* Handle "cd <directory>" */
		if (chdir(arg) == -1)
		{
			perror(program_name);
			return;
		}
	}
	getcwd(current_dir, sizeof(current_dir));
	/* Update PWD and OLDPWD environment variables */
	if (setenv("OLDPWD", previous_dir, 1) != 0 || setenv("PWD", current_dir, 1) != 0)
	{
		handle_error("Failed to update environment variables.");
		return;
	}
}
