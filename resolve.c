/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:52:12 by acauchy           #+#    #+#             */
/*   Updated: 2017/12/02 22:24:28 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	try_place(t_grid *grid, t_tetri *tetri, int i, int pos)
{
	int		new_pos;
	char	old_char;

	new_pos = -1;
	if (grid->array[pos] != EMPTY_CHAR && grid->array[pos] != tetri->letter)
		return (0);
	old_char = grid->array[pos];
	grid->array[pos] = tetri->letter;
	++i;
	if (!tetri->code[i])
		return (1);
	if (tetri->code[i] == 'D')
		new_pos = pos + 1;
	else if (tetri->code[i] == 'B')
		new_pos = pos + GRID_SIDE;
	else if (tetri->code[i] == 'H')
		new_pos = pos - GRID_SIDE;
	else if (pos % GRID_SIDE != 0)
		new_pos = pos - 1;
	if (new_pos == -1 || !(try_place(grid, tetri, i, new_pos)))
	{
		grid->array[pos] = old_char;
		return (0);
	}
	return (1);
}

static int	search_solution(t_grid *grid, t_tetri **tab_tetri)
{
	int	i;
	int	pos;
	int	y;

	i = 0;
	pos = 0;
	y = 0;
	while (y < grid->square_side && pos < GRID_SIZE)
	{
		if (try_place(grid, tab_tetri[i], -1, pos))
		{
			++i;
			if (!tab_tetri[i])
				return (1);
		}
		if (pos != 0 && (pos - (y * GRID_SIDE) == grid->square_side - 1))
		{
			++y;
			pos += GRID_SIDE - grid->square_side;
		}
		++pos;
	}
	return (0);
}

static void	swap_tetri(t_tetri **a, t_tetri **b)
{
	t_tetri	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	backtracking(t_grid *grid, t_tetri **tab_tetri, int i, int n)
{
	int	j;

	if (i == n)
	{
		if (search_solution(grid, tab_tetri))
			return (1);
		clear_square(grid);
	}
	else
	{
		j = i;
		while (j <= n)
		{
			swap_tetri(tab_tetri + i, tab_tetri + j);
			if (backtracking(grid, tab_tetri, i + 1, n))
				return (1);
			swap_tetri(tab_tetri + i, tab_tetri + j);
			++j;
		}
	}
	return (0);
}

void		resolve(t_grid *grid, t_tetri **tab_tetri, int nb_tetri)
{
	backtracking(grid, tab_tetri, 0, nb_tetri - 1);
	while (grid->square_side <= GRID_SIDE
			&& !(backtracking(grid, tab_tetri, 0, nb_tetri - 1)))
	{
		clear_square(grid);
		widen_square(grid);
	}
	if (grid->square_side == GRID_SIDE)
		exit_error();
}
