#include "main.h"
#include <stdlib.h>

/**
 * _puts - Prints a string using _putchar, then a newline
 * @str: The string to print
 */
static void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
static int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * is_digit_str - Checks if every character of s is a digit
 * @s: The string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
static int is_digit_str(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_error_and_exit - Prints "Error" and exits with status 98
 */
static void print_error_and_exit(void)
{
	_puts("Error");
	exit(98);
}

/**
 * main - Multiplies two positive numbers (given as CLI arguments)
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 if successful, 98 on error
 */
int main(int argc, char **argv)
{
	char *num1, *num2;
	int len1, len2, i, j, carry, n1, n2, sum;
	int *result;
	int total_len, start;

	if (argc != 3)
		print_error_and_exit();

	num1 = argv[1];
	num2 = argv[2];
	if (!is_digit_str(num1) || !is_digit_str(num2))
		print_error_and_exit();

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result = malloc((len1 + len2) * sizeof(int));
	if (result == NULL)
		return (1);

	/* Initialize result array to 0 */
	for (i = 0; i < (len1 + len2); i++)
		result[i] = 0;

	/* Perform multiplication (classic "long multiplication") */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = result[i + j + 1] + (n1 * n2) + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i + j + 1] += carry;
	}

	/* Skip leading zeros in result */
	total_len = len1 + len2;
	start = 0;
	while (start < (total_len - 1) && result[start] == 0)
		start++;

	/* Print result */
	for (i = start; i < total_len; i++)
		_putchar(result[i] + '0');
	_putchar('\n');

	free(result);
	return (0);
}
