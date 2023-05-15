#include "main.h"
#include <stdlib.h>

/**
 * custom_realloc - Reallocates a memory block with a new size.
 * @ptr: Pointer to the previously allocated memory block.
 * @size: New size for the memory block.
 *
 * Return: Pointer to the reallocated memory block,
 *	* or NULL if size is 0 and ptr is not NULL,
 *	* or NULL if the allocation fails.
 */

char *custom_realloc(char *ptr, size_t size)
{
	char *new_ptr = malloc(size);
	size_t i;

	if (new_ptr == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		for (i = 0; i < size; i++)
		{
			new_ptr[i] = ptr[i];
			if (ptr[i] == '\0')
				break;
		}
		free(ptr);
	}
	return (new_ptr);
}
