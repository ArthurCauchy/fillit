/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:28:22 by acauchy           #+#    #+#             */
/*   Updated: 2017/12/01 10:15:22 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_grid_s
{
	unsigned char	*grid;
	int				gridsize;
}				t_grid;

typedef struct	s_tetri
{
	char	letter;
	char	*code;
}				t_tetri;

typedef struct	s_tetridata
{
	char	*filecode;
	char	*code;
}				t_tetridata;

/*
** validate_tetri.c
*/

char			*validate_tetri(char *buff);

/*
** import.c
*/

void			error(void);
void			lect(int fd, t_tetri *tab_tetri);
void			usage(void);
void			import(t_tetri *tab_tetri);
int				add_tetri(char *id, t_tetri);

#endif
