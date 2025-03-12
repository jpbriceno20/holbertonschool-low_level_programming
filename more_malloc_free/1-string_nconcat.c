#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates s1 and first n bytes of s2
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes from s2 to include
 *
 * Return: Pointer to newly allocated space containing s1 + n bytes of s2
 *         NULL if function fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of s1 and s2 */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* If n >= len2, use entire s2 */
	if (n >= len2)
		n = len2;

	new_str = malloc(len1 + n + 1);
	if (new_str == NULL)
		return (NULL);

	/* Copy s1 into new_str */
	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	/* Copy up to n bytes of s2 */
	for (j = 0; j < n; j++)
		new_str[i + j] = s2[j];

	new_str[i + j] = '\0'; /* Null-terminate */

	return (new_str);
}
