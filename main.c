/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:43:53 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/01 10:49:33 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	fill_zero(t_tetri *tab_tetri)
{
	size_t y;

	y = 0;
	while (0 < 26)
	{
		tab_tetri[y].lettre = '9';
		tab_tetri[y].code = "999";
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_tetri	*tab_tetri[26];
	int		i;

	i = 0;
	if (argc != 2)
		exit_usage();
	import(argv[1], tab_tetri);
	while (i < 26)
	{
		ft_putchar(tab_tetri[i]->lettre);
		ft_putstr(tab_tetri[i]->code);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
