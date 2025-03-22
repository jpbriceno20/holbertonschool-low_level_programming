#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h> /* for size_t */

/* _putchar is allowed (provided by the school), prototype can be declared */
int _putchar(char c);

/**
 * print_name - prints a name using a passed-in function pointer
 * array_iterator - executes a function on each element of an array
 * int_index - searches for an integer in an array using a comparison function
 */
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif /* FUNCTION_POINTERS_H */
