/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <cpaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:54:17 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/30 18:08:51 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cap.h"

int		ouv(void)
{	
	int fd;
	
	fd = open("sample.fillit", 0);
	if (fd < 2)
		return (0);
	return (fd);
}

void		lect(int fd, t_tetri *tab_tetri)
{
	char buffer[20];
	int ret1;
	int ret2;
	char c;
	size_t t;

	ret1 = 0;
	ret2 = 0;
	t = 0;
	while (ret1 != 0 && ret2 != 0)
	{
		c = '0';
		ret1 = read (fd, buffer, 20);
		ret2 = read (fd, &c, 1);
		if ((ret1 != 0 && ret1 != 20) || (ret2 != 0 && ret2 != 1) || c != '\n')
			error();
		if (validate_tetri(buffer) == NULL)
			add_tetri(validate_tetri(buffer), tab_tetri[t]);
		t++;
	}
	if (c != 0)
		error();
}

void	add_tetri(char* id, t_tetri tab_tetri)
{

	tab_tetri.lettre = 'a';
	tab_tetri.id = id;
}

void	import(t_tetri *tab_tetri)
{
	int fd;

	fd = (int)ouv;
	lect(fd, tab_tetri);
}
