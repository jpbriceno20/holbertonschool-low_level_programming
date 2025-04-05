#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserta un nuevo nodo en una posición dada.
 * @head: Doble puntero a la cabeza de la lista.
 * @idx: Índice donde se debe insertar el nuevo nodo (comienza en 0).
 * @n: Entero a almacenar en el nuevo nodo.
 *
 * Return: Dirección del nuevo nodo, o NULL si falla o no es posible insertar.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(head, n));
	temp = *head;
	for (i = 0; temp != NULL && i < idx - 1; i++)
		temp = temp->next;
	if (temp == NULL)
		return (NULL);
	if (temp->next == NULL)
		return (add_dnodeint_end(head, n));
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;
	return (new_node);
}

