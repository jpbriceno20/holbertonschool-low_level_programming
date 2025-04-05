#include <stdio.h>

void __attribute__((constructor)) print_before_main(void)
{
    printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
