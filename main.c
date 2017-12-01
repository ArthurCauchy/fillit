/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:43:53 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/01 11:42:02 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

void	fill_zero(t_tetri **tab_tetri)
{	
	int i;

	i = 0;
	while (i < 26)
	{
		tab_tetri[i] = (t_tetri*)malloc(sizeof(t_tetri));
		tab_tetri[i]->letter = '9';
		tab_tetri[i]->code = "999";
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_tetri	*tab_tetri[26];
	int		i;

	i = 0;
	if (argc != 2)
		exit_usage();
	fill_zero(tab_tetri);
	import(argv[1], tab_tetri);
	while (i < 26)
	{
		ft_putchar(tab_tetri[i]->letter);
		ft_putchar(' ');
		ft_putstr(tab_tetri[i]->code);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
