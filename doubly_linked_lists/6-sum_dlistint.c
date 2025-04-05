#include "lists.h"

/**
 * sum_dlistint - Retorna la suma de todos los enteros de una lista doblemente enlazada.
 * @head: Puntero a la cabeza de la lista.
 *
 * Return: La suma de todos los datos (n), o 0 si la lista está vacía.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

