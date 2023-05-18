#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * exit_shell - Exits the shell program.
 * @status: integer
 */

void exit_shell(int status)
{
	exit(status);
}
