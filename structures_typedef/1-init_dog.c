#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Initializes a struct dog
 * @d: Pointer to struct dog to initialize
 * @name: The name to set
 * @age: The age to set
 * @owner: The owner to set
 *
 * Return: Nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
