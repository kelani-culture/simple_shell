#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
/**
 * command_args - Tokenizes a command into arguments.
 * @command: The command to tokenize.
 * @args: The array to store the arguments.
 * @max_args: The maximum number of arguments.
 *
 * Return: The number of arguments.
 */

int command_args(char *command, char *args[], int max_args)
{
	int arg_count = 0;
	char *arg =  strtok(command, " ");

	while (arg != NULL && arg_count < max_args - 1)
	{
		args[arg_count] = arg;
		arg_count++;
		arg = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	return (arg_count);
}
