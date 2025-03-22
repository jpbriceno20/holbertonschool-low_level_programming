#include "3-calc.h"

/**
 * get_op_func - selects the correct function to perform the operation asked by the user
 * @s: operator passed as argument
 *
 * Return: pointer to the function corresponding to the operator, or NULL if not found
 */
int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i = 0;

    while (ops[i].op)
    {
        /* Compare the operator; since s is expected to be a one-character string */
        if (s[0] == ops[i].op[0] && s[1] == '\0')
            break;
        i++;
    }
    return (ops[i].f);
}
