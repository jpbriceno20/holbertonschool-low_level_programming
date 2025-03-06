#include "main.h"

/**
 * main - adds positive numbers.
 * @argc: number of command line arguments.
 * @argv: array of command line arguments.
 *
 * Return: 0 on success, 1 if any argument contains non-digit characters.
 */
int main(int argc, char *argv[])
{
    int sum = 0, i, j;
    char *arg;

    for (i = 1; i < argc; i++)
    {
        arg = argv[i];
        for (j = 0; arg[j] != '\0'; j++)
        {
            if (arg[j] < '0' || arg[j] > '9')
            {
                printf("Error\n");
                return (1);
            }
        }
        sum += atoi(arg);
    }
    printf("%d\n", sum);
    return (0);
}
