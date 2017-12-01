/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:22:17 by acauchy           #+#    #+#             */
/*   Updated: 2017/12/01 17:01:08 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

/*
** Print 'error' then exit with EXIT_FAILURE.
*/

void	exit_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

/*
** Print the usage of the then exit with EXIT_SUCCESS.
*/

void	exit_usage(void)
{
	ft_putendl("usage : fillit <file.fillit>");
	exit(EXIT_SUCCESS);
}

/*
** Compute the minimal square side size for nb_tetri 
*/

int		min_square(int nb_tetri)
{
	int square_size;
	
	square_size = 0;
	while (ft_sqrt(square_size) != 1)
		square_size = nb_tetri * 4;
		nb_tetri++;
	return (ft_sqrt(square_size));
}

/*
** Create a grid and intitialize it with an optimized minimal
** square size depending on the parameter nb_tetri.
** The parameter grid_size is the wanted size of the grid.
** grid_size of 9 creates a 3*3 grid.
*/

t_grid	*init_grid(int nb_tetri)
{
	t_grid grid;
   
	if (!(grid = (t_grid*)malloc(sizeof(t_grid))
				|| !(grid->grid = (char*)malloc(GRID_SIZE))))
		exit_error();
	grid->square_size = min_square(nb_tetri);
	while (i < GRID_SIZE)
	{
		if ()
			//insert BLOCKED char
		else
			grid[i == ];
	}
	return (grid);
}
