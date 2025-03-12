#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - Prints the elements of a struct dog
 * @d: Pointer to struct dog
 *
 * Description:
 * If an element of d is NULL, this function prints (nil) in its place.
 * If d is NULL, it prints nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	/* Print dog's name */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	/* Print dog's age */
	printf("Age: %f\n", d->age);

	/* Print dog's owner */
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
