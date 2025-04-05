#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Elimina el nodo en el índice dado de una lista.
 * @head: Doble puntero a la cabeza de la lista.
 * @index: Índice del nodo a eliminar (comienza en 0).
 *
 * Return: 1 si se eliminó correctamente, -1 si falló.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	temp = *head;
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	for (i = 0; temp != NULL && i < index; i++)
		temp = temp->next;
	if (temp == NULL)
		return (-1);
	if (temp->next != NULL)
		temp->next->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = temp->next;
	free(temp);
	return (1);
}

