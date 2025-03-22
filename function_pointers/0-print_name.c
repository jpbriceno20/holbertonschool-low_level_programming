#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: pointer to the name to be printed
 * @f: pointer to the function used to print the name
 *
 * Description: This function takes a string and a pointer to a function.
 * It calls the function pointed to by @f with @name as argument.
 * If @name or @f is NULL, the function does nothing.
 */
void print_name(char *name, void (*f)(char *))
{
    if (name && f)
        f(name);
}


