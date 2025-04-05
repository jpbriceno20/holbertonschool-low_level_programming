#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - Agrega un nuevo nodo al inicio de una lista doblemente enlazada.
 * @head: Doble puntero a la cabeza de la lista.
 * @n: Entero a almacenar en el nuevo nodo.
 *
 * Return: Dirección del nuevo nodo, o NULL si falla.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}

