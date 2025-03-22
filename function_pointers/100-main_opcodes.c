#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the program arguments.
 *
 * Description: This program prints the opcodes (in hexadecimal, lowercase)
 * of its own main function. It takes a single argument which is the number of
 * bytes to print. Each opcode is printed as two hexadecimal characters.
 * If the number of arguments is not exactly 1, the program prints "Error"
 * followed by a new line and exits with a status of 1. If the number of bytes
 * is negative, it prints "Error" followed by a new line and exits with a status
 * of 2.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;
	unsigned char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	ptr = (unsigned char *)main;
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", ptr[i]);
		if (i < num_bytes - 1)
			printf(" ");
	}
	printf("\n");
	return (0);
}
