#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the dimension of the times table
 *
 * Description: If n > 15 or n < 0, nothing is printed.
 * Otherwise, it prints the (n+1) x (n+1) multiplication table.
 */
void print_times_table(int n)
{
	int row, col, product;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		for (col = 0; col <= n; col++)
		{
			product = row * col;
			if (col != 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (product < 10)
			{
				/* Print 3 spaces if not first column, then digit */
				if (col != 0)
				{
					_putchar(' ');
					_putchar(' ');
				}
				_putchar(product + '0');
			}
			else if (product < 100)
			{
				/* Print 2 spaces, then 2-digit number */
				_putchar(' ');
				_putchar((product / 10) + '0');
				_putchar((product % 10) + '0');
			}
			else
			{
				/* Up to 225 => 3-digit number => 1 space */
				_putchar((product / 100) + '0');
				_putchar(((product / 10) % 10) + '0');
				_putchar((product % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
