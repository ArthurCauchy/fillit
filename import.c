/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <cpaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:54:17 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/01 12:13:57 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"


static int	open_file(char *filename)
{	
	int fd;

	fd = open(filename, 0);
	if (fd < 0)
		return (0);
	return (fd);
}

static void	add_tetri(char *code, t_tetri *tab_tetri)
{
	static char	letter = 'A';
	tab_tetri->letter = letter;
	tab_tetri->code = code;
	++letter;
}

static void	lect(int fd, t_tetri **tab_tetri)
{
	char	buffer[20];
	int		ret1;
	int		ret2;
	char	c;
	size_t	t;
	char	*code;

	ret1 = -1;
	ret2 = -1;
	t = 0;
	while (ret1 != 0 && ret2 != 0)
	{
		c = '0';
		ret1 = read(fd, buffer, 20);
		ret2 = read(fd, &c, 1);
		if ((ret1 != 0 && ret1 != 20) || (ret2 != 0 && ret2 != 1) || (c != '\n' 
					&& c != '0'))
		{
			ft_putchar(c);
			ft_putstr("error lect 1\n");
			exit_error();
		}
		code = validate_tetri(buffer);
		if (code != NULL)
		{
			add_tetri(code, tab_tetri[t]);
			t++;
			ft_putnbr(ret1);
			ft_putchar('\n');
			ft_putnbr(ret2);
			ft_putchar('\n');
			ft_putnstr(buffer, 20);
			ft_putendl("\n==========");
		}
	}
		if (c != '0')
		{
			ft_putchar(c);
			ft_putstr("error lect2\n");
			exit_error();
		}
}

	void		import(char *filename, t_tetri **tab_tetri)
	{
		int fd;

		fd = open_file(filename);
		lect(fd, tab_tetri);
	}
