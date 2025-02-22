#include <stdio.h>

/**
 * main - Prints all possible different combinations of three digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i, j, k;

	for (i = 0; i < 8; i++) /* First digit */
	{
		for (j = i + 1; j < 9; j++) /* Second digit */
		{
			for (k = j + 1; k < 10; k++) /* Third digit */
			{
				putchar(i + '0'); /* Convert digit to ASCII */
				putchar(j + '0');
				putchar(k + '0');

				if (i != 7 || j != 8 || k != 9) /* Avoid last comma */
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');

	return (0);
}
