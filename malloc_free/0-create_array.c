include "main.h"
#include <stdlib.h>

/**                                                                                                                                                                                                                
 * create_array - Creates an array of chars, initializes it with a specific char                                                                                                                                   
 * @size: The size of the array                                                                                                                                                                                    
 * @c: The char to initialize the array with                                                                                                                                                                       
 *                                                                                                                                                                                                                 
 * Return: Pointer to the array, or NULL if size is 0 or memory allocation fails                                                                                                                                   
 */
char *create_array(unsigned int size, char c)
{
    char *arr;
    unsigned int i;

    if (size == 0)
        return (NULL);

    arr = malloc(size);
    if (arr == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        arr[i] = c;

    return (arr);
}
