#include "main.h"
#include <stdlib.h>

/**
 * shell_unsetenv - Unset an environment variable.
 * @variable: The name of the variable to unset.
 */

void shell_unsetenv(const char *variable)
{
	int result;

	if (variable == NULL)
	{
		handle_error("Usage: unsetenv VARIABLE");
		return;
	}
	if ((result = unsetenv(variable)) != 0)
		handle_error("Failed to unset environment variable");
}
