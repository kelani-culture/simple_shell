#include <stddef.h>
#include "main.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable if found, or NULL otherwise.
 */

char *_getenv(const char *name)
{
	

	for (; *env != NULL; ++env)
	{
		env_var = *env;
		env_var_len = _strlen(env_var);
		/* check if the variable name matches */

		if (nameLen <= env_var_len)
		{
			for (i = 0; i < nameLen; ++i)
			{
				if (name[i] != env_var[i])
					break;
			}
			if (i == nameLen && env_var[i] == '=')
			{
				/* return the value after the '=' */
				return (&env_var[i + 1]);
			}
		}
	}
	return (NULL); /* variable not found */
}
