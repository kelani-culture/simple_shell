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
	char previous_dir[MAX_PATH_LENGTH];

	arg = _strtok(NULL, " "); /* Get the directory argument */
	if (arg == NULL || _strcmp(arg, "-") == 0)
	{
		if (chdir(_getenv("OLDPWD")) == -1)
		{
			perror(program_name);
			return;
		}
		getcwd(previous_dir, sizeof(previous_dir));
		if (arg != NULL)
		{
			write_string(STDOUT_FILENO, previous_dir);
			write_string(STDOUT_FILENO, "\n");
		}
		else
		{
			handle_error("No previous directory stored");
			return;
		}
	}
	else
	{
		if (chdir(arg) == -1)
		{
			perror(program_name);
			return;
		}
		getcwd(previous_dir, sizeof(previous_dir));
	}
	if (setenv("OLDPWD", _getenv("PWD"), 1) != 0 ||
		setenv("PWD", previous_dir, 1) != 0)
	{
		handle_error("Failed to update environment variables");
		return;
	}
}
