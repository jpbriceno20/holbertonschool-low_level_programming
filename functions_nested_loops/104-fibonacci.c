#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Description: Use separate variables to handle overflow after 92nd fib.
 * Return: 0
 */
int main(void)
{
	int count;
	unsigned long f1_part1 = 0, f1_part2 = 1;
	unsigned long f2_part1 = 0, f2_part2 = 2;
	unsigned long carry, sum_part1, sum_part2;

	printf("%lu, %lu", f1_part2, f2_part2);

	for (count = 3; count <= 98; count++)
	{
		/* Add the low parts */
		sum_part2 = f1_part2 + f2_part2;
		/* Add the high parts + possible carry from the low */
		carry = sum_part2 / 1000000000;
		sum_part2 = sum_part2 % 1000000000;
		sum_part1 = f1_part1 + f2_part1 + carry;

		/* Print the next fibonacci number */
		if (sum_part1 > 0)
			printf(", %lu%09lu", sum_part1, sum_part2);
		else
			printf(", %lu", sum_part2);

		/* Update for next loop */
		f1_part1 = f2_part1;
		f1_part2 = f2_part2;
		f2_part1 = sum_part1;
		f2_part2 = sum_part2;
	}
	printf("\n");
	return (0);
}
