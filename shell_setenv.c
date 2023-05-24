#include "main.h"
#include <stdlib.h>

/**
 * shell_setenv - Initialize a new environment
 *	* variable or modify an existing one
 * @variable: Name of the environment variable
 * @value: Value to set for the environment variable
 */

void shell_setenv(const char *variable, const char *value)
{
	int result;

	if (variable == NULL || value == NULL)
	{
		handle_error("Usage: setenv Variable Value");
		return;
	}
	result = setenv(variable, value, 1);
	if (result != 0)
		handle_error("Failed to set environment variable");
}
