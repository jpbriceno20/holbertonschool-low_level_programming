#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of chars and initializes it with a specific char
 * @size: Size of the array
 * @c: Character to initialize the array
 *
 * Return: Pointer to the array, or NULL if size is 0 or memory allocation fails
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0) /* Return NULL if size is 0 */
		return (NULL);

	arr = malloc(size * sizeof(char)); /* Allocate memory */
	if (arr == NULL) /* Return NULL if malloc fails */
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c; /* Initialize array with char 'c' */

	return (arr);
}
