#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: integer value of the string
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;
	int found_digit = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			found_digit = 1;
			num = num * 10 + (*s - '0');
		}
		else if (found_digit == 1)
		{
			/* once we have digits and hit a non-digit, break */
			break;
		}
		s++;
	}
	return (num * sign);
}
