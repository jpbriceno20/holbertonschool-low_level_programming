#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j;

	for (i = 0; i < 9; i++) /* First digit */
	{
		for (j = i + 1; j < 10; j++) /* Second digit (must be greater than i) */
		{
			putchar(i + '0'); /* Convert digit to ASCII */
			putchar(j + '0');

			if (i != 8 || j != 9) /* Avoid printing last comma */
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
