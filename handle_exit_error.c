#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/*
 * handle_exit_error - handle negative exit error
 * @program_name: name of the program
 * @status: negative stause
 */


void handle_exit_error(const char *program_name, char *status)
 {
	write_string(STDERR_FILENO, program_name);
	write_string(STDERR_FILENO, ": 1: exit: Illegal number: ");
	write_string(STDERR_FILENO, status);
	write_string(STDERR_FILENO, "\n");
 }
