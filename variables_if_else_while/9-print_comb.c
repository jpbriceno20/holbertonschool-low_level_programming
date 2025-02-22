#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 48; num < 58; num++)
	{
		putchar(num);
		if (num != 57)  /* Do not print comma and space after last digit */
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
