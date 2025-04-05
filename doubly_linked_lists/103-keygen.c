#include <stdio.h>
#include <stdlib.h>

/**
 * main - Genera una clave válida para crackme5.
 * @argc: Número de argumentos.
 * @argv: Arreglo de argumentos.
 *
 * Return: 0 si es exitoso, 1 si falla.
 */
int main(int argc, char **argv)
{
	unsigned long key = 0;
	int i;

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}
	for (i = 0; argv[1][i] != '\0'; i++)
	{
		key += argv[1][i] * (i + 1);
	}
	printf("%lu", key);
	return (0);
}

