#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;
	char ch;

	for (num = 48; num < 58; num++)  /* 0-9 */
		putchar(num);
	for (ch = 'a'; ch <= 'f'; ch++)  /* a-f */
		putchar(ch);
	putchar('\n');

	return (0);
}
