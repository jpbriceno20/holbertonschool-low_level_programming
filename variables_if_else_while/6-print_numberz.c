#include <stdio.h>

/**
 * main - Prints numbers 0-9 using putchar (no char variable).
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 48; num < 58; num++)  /* ASCII values of '0' to '9' */
		putchar(num);
	putchar('\n');

	return (0);
}
