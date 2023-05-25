#include "main.h"
#include <stdlib.h>

/**
 * check_status - checks the exit status
 * @program_name: programe name
 * @command: name of command
 * @status: int  status
 */

void check_status(const char *program_name, char *command, int status)
{
	if (status > -1)
	{
		free(command);
		exit_shell(status);
	}
	else
	{
		handle_exit_error(program_name, command + 5);
		free(command);
		exit_shell(EXIT_FAILURE);
	}
}
