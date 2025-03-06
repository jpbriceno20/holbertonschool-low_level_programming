#include "main.h"

/**
 * main - multiplies two numbers.
 * @argc: number of command line arguments.
 * @argv: array of command line arguments.
 *
 * Return: 0 on success, 1 if not exactly two arguments are provided.
 */
int main(int argc, char *argv[])
{
    int num1, num2;

    if (argc != 3)
    {
        printf("Error\n");
        return (1);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    printf("%d\n", num1 * num2);
    return (0);
}
