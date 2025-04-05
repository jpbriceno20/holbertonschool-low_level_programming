#include "lists.h"

/**
 * get_dnodeint_at_index - Retorna el nodo en un índice dado de una lista.
 * @head: Puntero a la cabeza de la lista.
 * @index: Índice del nodo, comenzando en 0.
 *
 * Return: El nodo en el índice indicado, o NULL si no existe.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL && i < index)
	{
		head = head->next;
		i++;
	}
	return (head);
}

