#include "lists.h"

/**
 * dlistint_len - Retorna el número de elementos en una lista doblemente enlazada.
 * @h: Puntero a la cabeza de la lista.
 *
 * Return: Número de nodos.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}

