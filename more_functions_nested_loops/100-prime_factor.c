#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor of 612852475143
 *
 * Return: 0 on success
 */
int main(void)
{
	unsigned long n = 612852475143;
	unsigned long factor = 2;
	unsigned long largest = 0;

	/* Factor out all the 2's first */
	while (n % 2 == 0)
	{
		largest = 2;
		n /= 2;
	}

	/* Now factor out odd factors from 3 onwards */
	for (factor = 3; factor * factor <= n; factor += 2)
	{
		while (n % factor == 0)
		{
			largest = factor;
			n /= factor;
		}
	}

	/*
	 * If n is still greater than 2, it means n itself is prime
	 * and is the largest prime factor.
	 */
	if (n > 2)
		largest = n;

	printf("%lu\n", largest);
	return (0);
}
