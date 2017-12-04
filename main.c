/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:43:53 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/04 13:23:33 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_tetri	*tab_tetri[27];
	t_grid	*grille;
	int		i;
	int		nb_tetri;

	i = 0;
	if (argc != 2)
		exit_usage();
	nb_tetri = import(argv[1], tab_tetri);
	grille = init_grid(nb_tetri);
	resolve(grille, tab_tetri);
	print_result(grille);
	return (0);
}
