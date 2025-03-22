#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Prints anything based on the format.
 * @format: A list of types of arguments passed to the function.
 *          c: char, i: integer, f: float, s: char *.
 *
 * Description: Any other character in format is ignored.
 * If a string is NULL, (nil) is printed instead.
 * Prints a new line at the end.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *s;
	char *sep = "";

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(args, int));
				sep = ", ";
				break;
			case 'i':
				printf("%s%d", sep, va_arg(args, int));
				sep = ", ";
				break;
			case 'f':
				printf("%s%f", sep, va_arg(args, double));
				sep = ", ";
				break;
			case 's':
				s = va_arg(args, char *);
				if (!s)
					s = "(nil)";
				printf("%s%s", sep, s);
				sep = ", ";
				break;
			default:
				break;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
