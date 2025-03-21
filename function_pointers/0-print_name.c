#include "function_pointers.h"

/**
 * print_name - prints a name using a given function pointer
 * @name: the name to print
 * @f: function pointer that takes a char pointer as argument
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
