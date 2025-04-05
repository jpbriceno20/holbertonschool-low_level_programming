#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - Agrega un nuevo nodo al final de una lista doblemente enlazada.
 * @head: Doble puntero a la cabeza de la lista.
 * @n: Entero a almacenar en el nuevo nodo.
 *
 * Return: Dirección del nuevo nodo, o NULL si falla.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
	return (new_node);
}

