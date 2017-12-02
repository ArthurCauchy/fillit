/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:28:22 by acauchy           #+#    #+#             */
/*   Updated: 2017/12/02 14:07:47 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define GRID_SIDE 13
# define GRID_SIZE (GRID_SIDE * GRID_SIDE)

# define EMPTY_CHAR '.'
# define BLOCKED_CHAR '@'

typedef struct	s_grid_s
{
	char			*array;
	int				square_side;
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

int				import(char *filename, t_tetri **tab_tetri);

/*
** utils.c
*/

void			exit_error(void);
void			exit_usage(void);
t_grid			*init_grid(int nb_tetri);

/*
** output.c
*/

void			print_grid(t_grid *grid);
void			print_result(t_grid *grid);

#endif
