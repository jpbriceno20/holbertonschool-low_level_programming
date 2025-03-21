#include "function_pointers.h"

/**
 * array_iterator - executes a function given as a parameter on each
 *                  element of an array
 * @array: pointer to the integer array
 * @size: number of elements in the array
 * @action: pointer to the function to be used on each element
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
