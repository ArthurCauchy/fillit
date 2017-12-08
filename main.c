/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:43:53 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/04 15:51:46 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_tetri	*tab_tetri[27];
	t_grid	*grid;
	int		i;
	int		nb_tetri;

	if (argc != 2)
		exit_usage();
	nb_tetri = import(argv[1], tab_tetri);
	grid = init_grid(nb_tetri, tab_tetri);
	resolve(grid, tab_tetri);
	print_result(grid);
	i = 0;
	while (tab_tetri[i] != NULL)
	{
		free(tab_tetri[i]->code);
		free(tab_tetri[i]);
		++i;
	}
	free(grid->array);
	free(grid);
	return (0);
}
