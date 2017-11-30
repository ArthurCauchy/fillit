/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:43:53 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/30 17:17:06 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cap.h"

void	error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	usage(void)
{
	ft_putstr("usage : fillit <file.>\n");
	exit(0);
}

void	fill_zero(t_tetri *tab_tetri)
{
	size_t y;

	y = 0;
	while (0 < 26)
	{
		tab_tetri[y].lettre = '9';
		tab_tetri[y].id = "999";
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_tetri tab_tetri[26];
	size_t h;

	h = 0;
	argv[0] = NULL;
	if (argc != 2)
		usage();
	import(tab_tetri);
	while (h < 26)
	{
		ft_putchar(tab_tetri[h].lettre);
		ft_putstr(tab_tetri[h].id);
		ft_putchar('\n');
		h++;
	}
	return (0);
}
