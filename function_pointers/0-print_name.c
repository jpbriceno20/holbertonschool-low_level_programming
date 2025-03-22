#include "function_pointers.h"

/**
 * print_name - prints a name using a given function
 * @name: the name to print
 * @f: pointer to the function to use to print the name
 */
void print_name(char *name, void (*f)(char *))
{
    if (f != NULL)
        f(name);
}
