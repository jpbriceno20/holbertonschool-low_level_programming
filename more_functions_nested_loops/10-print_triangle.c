#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a newline.
 * @size: the size of the triangle
 */
void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0; i < size; i++)
	{
		/* Print spaces */
		for (j = 0; j < size - i - 1; j++)
			_putchar(' ');
		/* Print # characters */
		for (k = 0; k < i + 1; k++)
			_putchar('#');
		_putchar('\n');
	}
}
