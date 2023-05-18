#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * exit_status - an integer used to exit the shell
 * @status_str: integer
 * Return: status
 */

int exit_status(const char *status_str)
{
	int status = 0;
	int i = 0;

	while (status_str[i])
	{
		if (status_str[i] < '0' || status_str[i] > '9')
		{
			return (-1);
		}
		status = (status * 10) + (status_str[i] - '0');
		i++;
	}
	return (status);
}
