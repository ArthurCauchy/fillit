/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:43:53 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/01 17:47:19 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_tetri	*tab_tetri[27];

	t_grid *grille;
	int		i;
	int nb_tetri;

	i = 0;

	if (argc != 2)
		exit_usage();
	nb_tetri = import(argv[1], tab_tetri);
	grille = init_grid(nb_tetri);
ft_putstr("test");
	while (tab_tetri[i])
	{
		ft_putstr("main:");
		ft_putchar(tab_tetri[i]->letter);
		ft_putchar(' ');
		ft_putstr(tab_tetri[i]->code);
		ft_putchar('\n');
		i++;
	}

	ft_putnstr(grille->array, GRID_SIZE);
	return (0);
}
