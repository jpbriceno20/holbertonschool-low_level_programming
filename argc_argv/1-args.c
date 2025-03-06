#include "main.h"

/**
 * main - prints the number of arguments passed into it.
 * @argc: number of command line arguments.
 * @argv: array of command line arguments (unused).
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    (void)argv;
    /* Subtract 1 because argv[0] is the program name */
    printf("%d\n", argc - 1);
    return (0);
}
