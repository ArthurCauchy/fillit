//HEADER

#include "libft.h"
#include "fillit.h"

/*
** Print all the grid, blocked chars too.
*/

void	print_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (i < GRID_SIZE)
	{
		ft_putchar(grid->array[i]);
		if (i != 0 && ((i + 1) % GRID_SIDE) == 0)
			ft_putchar('\n');
		++i;
	}
}

/*
** Print only the best square containing all the tetri.
*/

void	print_result(t_grid *grid)
{
	int i;

	i = 0;
	while (i < GRID_SIZE)
	{
		ft_putchar(grid->array[i]);
		if (i != 0 && ((i + 1) % GRID_SIDE) == 0)
			ft_putchar('\n');
		++i;
	}
}
