#include "main.h"

/**
 * is_divisible - checks recursively if n is divisible by i.
 * @n: the number to check.
 * @i: the current divisor.
 *
 * Return: 1 if n is divisible by i, 0 otherwise.
 */
int is_divisible(int n, int i)
{
	if (i * i > n)
		return (0);
	if (n % i == 0)
		return (1);
	return (is_divisible(n, i + 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number,
 * and 0 otherwise.
 * @n: the number to check.
 *
 * Return: 1 if n is prime, 0 if not.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (is_divisible(n, 2) == 0 ? 1 : 0);
}
