#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars and initializes it with a char
 * @size: The size of the array
 * @c: The character to initialize the array with
 *
 * Return: Pointer to the array, or NULL if size is 0 or memory allocation fails
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	/* Check if size is 0, return NULL */
	if (size == 0)
		return (NULL);

	/* Allocate memory */
	arr = malloc(size * sizeof(char));
	if (arr == NULL)
		return (NULL);

	/* Initialize array with character c */
	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}


