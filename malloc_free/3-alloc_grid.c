#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Creates a 2D array of integers initialized to 0
 * @width: Width of grid
 * @height: Height of grid
 *
 * Return: Pointer to the 2D array, or NULL if failure
 */
int **alloc_grid(int width, int height)
{
    int **grid;
    int i, j;

    if (width <= 0 || height <= 0)
        return (NULL);

    grid = malloc(height * sizeof(int *));
    if (grid == NULL)
        return (NULL);

    for (i = 0; i < height; i++)
    {
        grid[i] = malloc(width * sizeof(int));
        if (grid[i] == NULL)
        {
            while (i >= 0)
            {
                free(grid[i]);
                i--;
            }
            free(grid);
            return (NULL);
        }

        for (j = 0; j < width; j++)
            grid[i][j] = 0;
    }

    return (grid);
}
