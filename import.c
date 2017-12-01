/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <cpaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:54:17 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/01 11:03:21 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	open_file(char *filename)
{	
	int fd;

	fd = open(filename, 0);
	if (fd < 2)
		return (0);
	return (fd);
}

static void	lect(int fd, t_tetri *tab_tetri)
{
	char	buffer[20];
	int		ret1;
	int		ret2;
	char	c;
	size_t	t;

	ret1 = 0;
	ret2 = 0;
	t = 0;
	while (ret1 != 0 && ret2 != 0)
	{
		c = '0';
		ret1 = read(fd, buffer, 20);
		ret2 = read(fd, &c, 1);
		if ((ret1 != 0 && ret1 != 20) || (ret2 != 0 && ret2 != 1) || c != '\n')
			error();
		if (validate_tetri(buffer) == NULL)
			add_tetri(validate_tetri(buffer), tab_tetri[t]);
		t++;
	}
	if (c != 0)
		error();
}

static void	add_tetri(char *code, t_tetri tab_tetri)
{
	tab_tetri->letter = 'a';
	tab_tetri->code = code;
}

void		import(char *filename, t_tetri *tab_tetri)
{
	int fd;

	fd = open_file();
	lect(fd, tab_tetri);
}
