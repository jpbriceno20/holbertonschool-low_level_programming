#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the minimum number of coins to make change for an amount of money.
 * @argc: The number of arguments.
 * @argv: An array of arguments.
 *
 * Description: If the number of arguments is not exactly 1, print "Error"
 * followed by a new line and return 1. Use atoi to convert the parameter to an int.
 * If the number is negative, print 0 followed by a new line.
 * The coins available are 25, 10, 5, 2, and 1 cent.
 *
 * Return: 0 on success, 1 if the argument count is wrong.
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;
	int coin_values[5] = {25, 10, 5, 2, 1};
	int i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < 5; i++)
	{
		coins += cents / coin_values[i];
		cents %= coin_values[i];
	}

	printf("%d\n", coins);
	return (0);
}
