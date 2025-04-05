#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - Libera una lista doblemente enlazada.
 * @head: Puntero a la cabeza de la lista.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

