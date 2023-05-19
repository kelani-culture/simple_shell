#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * handle_error - Prints the error
 *	* message with program name and exits with failure.
 * @error_msg: The error message to print.
 */

void handle_error(const char *error_msg)
{
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
}
