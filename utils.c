/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:22:17 by acauchy           #+#    #+#             */
/*   Updated: 2017/12/01 19:34:41 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

/*
** Print 'error' then exit with EXIT_FAILURE.
*/

void		exit_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

/*
** Print the usage of the then exit with EXIT_SUCCESS.
*/

void		exit_usage(void)
{
	ft_putendl("usage : fillit <file.fillit>");
	exit(EXIT_SUCCESS);
}

/*
** Compute the minimal square side size for nb_tetri.
*/

static int	min_square(int nb_tetri)
{
	int square_size;

	square_size = nb_tetri * 4;
	while (ft_sqrt(square_size) == 0)
		square_size++;
	return (ft_sqrt(square_size));
}

/*
** Create a grid and intitialize it with an optimized minimal
** square size depending on the parameter nb_tetri.
** The parameter grid_size is the wanted size of the grid.
** grid_size of 9 creates a 3*3 grid.
*/

t_grid		*init_grid(int nb_tetri)
{
	t_grid	*grid;
	int		i;
	int		y;

	if (!(grid = (t_grid*)malloc(sizeof(t_grid)))
				|| !(grid->array = (char*)malloc(GRID_SIZE)))
		exit_error();
	grid->square_size = min_square(nb_tetri);
	printf("sqrt : %d\n", grid->square_size);
	i = 0;
	y = 0;
	while (i < GRID_SIZE)
	{
		if (y > grid->square_size - 1
				|| (i - (y * GRID_SIDE)) >= grid->square_size)
			grid->array[i] = BLOCKED_CHAR;
		else
			grid->array[i] = EMPTY_CHAR;
		if (i != 0 && (i - (y * GRID_SIDE) == GRID_SIDE - 1))
			++y;
		++i;
	}
	return (grid);
}
