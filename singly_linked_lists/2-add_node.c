#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: Double pointer to the head of the list.
 * @str: String to be duplicated and stored in the node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;
    unsigned int len = 0;
    char *dup_str;

    if (str == NULL)
        return (NULL);

    while (str[len])
        len++;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    dup_str = strdup(str);
    if (dup_str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->str = dup_str;
    new_node->len = len;
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}
