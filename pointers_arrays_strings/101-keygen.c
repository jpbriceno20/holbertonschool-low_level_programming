#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a random valid password for the 101-crackme program.
 *
 * Return: Always 0.
 */
int main(void)
{
    int i;
    int password_length = 7;
    char password[8]; /* 7 characters + null terminator */

    srand(time(NULL));
    for (i = 0; i < password_length; i++)
    {
        password[i] = (rand() % 94) + 33; /* Generate a printable character (ASCII 33-126) */
    }
    password[password_length] = '\0';
    printf("%s", password);
    return (0);
}
