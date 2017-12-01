/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:43:53 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/01 15:51:20 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_tetri	*tab_tetri[27];
	int		i;

	i = 0;
	if (argc != 2)
		exit_usage();
	import(argv[1], tab_tetri);
	while (tab_tetri[i])
	{
		ft_putstr("main:");
		ft_putchar(tab_tetri[i]->letter);
		ft_putchar(' ');
		ft_putstr(tab_tetri[i]->code);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
