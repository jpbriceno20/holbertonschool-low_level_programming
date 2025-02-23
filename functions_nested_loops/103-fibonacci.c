#include <stdio.h>

/**
 * main - sums even-valued Fibonacci terms not exceeding 4,000,000
 *
 * Return: 0
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2, next;
	unsigned long sum_even = 0;

	while (f2 <= 4000000)
	{
		if (f2 % 2 == 0)
			sum_even += f2;

		next = f1 + f2;
		f1 = f2;
		f2 = next;
	}
	printf("%lu\n", sum_even);
	return (0);
}
