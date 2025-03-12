#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of your program
 * @ac: Argument count
 * @av: Argument vector (array of strings)
 *
 * Return: Pointer to a new string with all args, each followed by a newline,
 *         or NULL if ac == 0, av == NULL, or if memory allocation fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, len, total_len = 0, index = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Calculate total length = sum of each arg + newline + null terminator */
	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len] != '\0')
			len++;
		total_len += len + 1; /* +1 for the newline */
	}
	total_len += 1; /* +1 for the final null terminator */

	/* Allocate memory for the concatenated string */
	str = malloc(total_len * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* Copy each argument and add a newline */
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			str[index] = av[i][j];
			index++;
			j++;
		}
		str[index] = '\n';
		index++;
	}

	/* Null-terminate the resulting string */
	str[index] = '\0';

	return (str);
}
