/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:28:22 by acauchy           #+#    #+#             */
/*   Updated: 2017/12/01 16:52:46 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define GRID_SIDE 13
# define GRID_SIZE (GRID_SIDE * GRID_SIDE)

typedef struct	s_grid_s
{
	char			*grid;
	int				square_size;
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

void			import(char *filename, t_tetri **tab_tetri);

/*
** utils.c
*/

void			exit_error(void);
void			exit_usage(void);

#endif
