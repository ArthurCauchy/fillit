/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <cpaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:54:17 by cpaquet           #+#    #+#             */
/*   Updated: 2017/12/04 15:18:18 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

static int	open_file(char *filename)
{
	int fd;

	fd = open(filename, 0);
	if (fd < 0)
		return (0);
	return (fd);
}

static void	add_tetri(char *code, t_tetri **tab_tetri)
{
	static char	letter = 'A';

	if (!(*tab_tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		exit_error(tab_tetri, NULL);
	(*tab_tetri)->letter = letter;
	(*tab_tetri)->code = code;
	++letter;
}

static int	lect(int fd, t_tetri **tab_tetri)
{
	char	buffer[20];
	int		read_size;
	int		really_read;
	int		t;
	char	*code;

	t = 0;
	read_size = 20;
	while ((really_read = read(fd, buffer, read_size)) > 0)
	{
		if (t == 26 || really_read != read_size
				|| (read_size == 1 && buffer[0] != '\n'))
			exit_error(tab_tetri, NULL);
		if (read_size == 20)
		{
			if (!(code = validate_tetri(buffer)))
				exit_error(tab_tetri, NULL);
			add_tetri(code, &tab_tetri[t++]);
		}
		read_size = (read_size == 20) ? 1 : 20;
	}
	tab_tetri[t] = NULL;
	if (really_read < 0 || read_size == 20)
		exit_error(tab_tetri, NULL);
	return (t);
}

int			import(char *filename, t_tetri **tab_tetri)
{
	int fd;

	fd = open_file(filename);
	return (lect(fd, tab_tetri));
}
