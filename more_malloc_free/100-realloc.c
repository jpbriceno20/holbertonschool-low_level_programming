#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block
 * @ptr: Pointer to previously allocated memory
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the memory block
 *
 * Return: Pointer to newly allocated memory block
 *         If new_size == old_size, return ptr
 *         If ptr == NULL, call malloc(new_size)
 *         If new_size == 0 and ptr != NULL, free(ptr) and return NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old_ptr;
	unsigned int i, limit;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_ptr = ptr;
	limit = (old_size < new_size) ? old_size : new_size;

	for (i = 0; i < limit; i++)
		new_ptr[i] = old_ptr[i];

	free(ptr);
	return (new_ptr);
}
