#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_error - Prints the error
 *	* message with program name and exits with failure.
 * @error_msg: The error message to print.
 * @program_name: The name of the program.
 */

void handle_error(const char *error_msg, const char *program_name)
{
	char error_buf[BUF_SIZE];

	snprintf(error_buf, BUF_SIZE, "%s%s", program_name, error_msg);
	perror(error_buf);
	exit(EXIT_FAILURE);
}
