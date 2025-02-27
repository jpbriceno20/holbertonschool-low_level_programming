#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string
 */
void rev_string(char *s)
{
	int i = 0, j;
	char temp;

	/* find length */
	while (s[i] != '\0')
		i++;

	j = 0;
	i = i - 1;

	/* swap characters moving inwards */
	while (j < i)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		j++;
		i--;
	}
}
