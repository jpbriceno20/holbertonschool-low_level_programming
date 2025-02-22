#include <stdio.h>

/**
 * main - Prints all possible combinations of two two-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num1, num2;

	for (num1 = 0; num1 < 99; num1++) /* First two-digit number */
	{
		for (num2 = num1 + 1; num2 < 100; num2++) /* Second two-digit number */
		{
			putchar((num1 / 10) + '0'); /* Print first digit of num1 */
			putchar((num1 % 10) + '0'); /* Print second digit of num1 */
			putchar(' '); /* Space between numbers */
			putchar((num2 / 10) + '0'); /* Print first digit of num2 */
			putchar((num2 % 10) + '0'); /* Print second digit of num2 */

			if (num1 != 98 || num2 != 99) /* Avoid last comma */
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
