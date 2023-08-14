#include "holberton.h"
/**
 * free_custom_grid - Free the allocated memory used for a custom grid.
 * @grid: Pointer to the grid.
 * @height: Height of the grid.
 */


void free_custom_grid(char **grid, int height)
{
	int i = 0;


	if (grid == NULL)
	{
		return;
	}


	while (i < height)
	{
		free(grid[i]);
		i++;
	}
}
