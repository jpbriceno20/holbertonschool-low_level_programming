#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Pointer to new concatenated string, or NULL if allocation fails
 */
char *str_concat(char *s1, char *s2)
{
    char *concat;
    unsigned int i, j, len1 = 0, len2 = 0;

    if (s1 != NULL)
        while (s1[len1] != '\0')
            len1++;
    if (s2 != NULL)
        while (s2[len2] != '\0')
            len2++;

    concat = malloc((len1 + len2 + 1) * sizeof(char));
    if (concat == NULL)
        return (NULL);

    for (i = 0; i < len1; i++)
        concat[i] = s1[i];

    for (j = 0; j < len2; j++, i++)
        concat[i] = s2[j];

    concat[i] = '\0';

    return (concat);
}
