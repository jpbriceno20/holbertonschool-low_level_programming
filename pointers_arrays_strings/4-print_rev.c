#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string
 */
void print_rev(char *s)
{
	int len = 0;

	/* find length */
	while (s[len] != '\0')
		len++;

	/* print in reverse */
	while (len > 0)
	{
		len--;
		_putchar(s[len]);
	}
	_putchar('\n');
}
