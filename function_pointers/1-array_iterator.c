#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array.
 * @array: the array of integers
 * @size: number of elements in the array
 * @action: pointer to the function to be used on each element
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t i;

    if (array == NULL || action == NULL)
        return;

    for (i = 0; i < size; i++)
        action(array[i]);
}
