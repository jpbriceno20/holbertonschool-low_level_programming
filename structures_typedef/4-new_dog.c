#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @str: The string to duplicate
 *
 * Return: Pointer to duplicated string, or NULL if str is NULL or memory fails
 */
static char *_strdup(char *str)
{
	char *dup;
	int i = 0, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}

/**
 * new_dog - Creates a new dog_t
 * @name: The name to copy
 * @age: The age to set
 * @owner: The owner to copy
 *
 * Return: Pointer to newly created dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_d;

	new_d = malloc(sizeof(dog_t));
	if (new_d == NULL)
		return (NULL);

	/* Duplicate name */
	new_d->name = _strdup(name);
	if (new_d->name == NULL)
	{
		free(new_d);
		return (NULL);
	}

	/* Duplicate owner */
	new_d->owner = _strdup(owner);
	if (new_d->owner == NULL)
	{
		free(new_d->name);
		free(new_d);
		return (NULL);
	}

	new_d->age = age;

	return (new_d);
}
