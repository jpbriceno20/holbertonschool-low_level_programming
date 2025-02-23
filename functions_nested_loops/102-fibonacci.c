#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: 0
 */
int main(void)
{
	int count;
	unsigned long f1 = 1, f2 = 2, next;

	printf("%lu, %lu", f1, f2);
	for (count = 3; count <= 50; count++)
	{
		next = f1 + f2;
		printf(", %lu", next);
		f1 = f2;
		f2 = next;
	}
	printf("\n");
	return (0);
}
