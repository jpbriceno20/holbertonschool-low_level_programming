#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - Imprime todos los elementos de una lista doblemente enlazada.
 * @h: Puntero a la cabeza de la lista.
 *
 * Return: Número de nodos impresos.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}

