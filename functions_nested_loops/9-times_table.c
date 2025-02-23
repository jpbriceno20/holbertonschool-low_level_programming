#include "main.h"

void times_table(void)
{
    int row, col, product;

    for (row = 0; row <= 9; row++)
    {
        for (col = 0; col <= 9; col++)
        {
            product = row * col;
            /* Handle formatting: comma-space except for col=0, etc. */
            if (col > 0)
            {
                _putchar(',');
                _putchar(' ');
            }
            if (product < 10 && col > 0)
            {
                _putchar(' ');
                _putchar(product + '0');
            }
            else
            {
                /* product >= 10 or col == 0 */
                if (product >= 10)
                    _putchar((product / 10) + '0');
                _putchar((product % 10) + '0');
            }
        }
        _putchar('\n');
    }
}
