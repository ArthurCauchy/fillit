/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cap.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:06:22 by cpaquet           #+#    #+#             */
/*   Updated: 2017/11/30 17:07:30 by cpaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAP_H
# define CAP_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_tetri
{
	char lettre;
	char *id;
}				t_tetri;

void	error(void);
int		ouv(void);
void	lect(int fd, t_tetri *tab_tetri);
void	usage(void);
void	import(t_tetri *tab_tetri);
void	add_tetri(char *id, t_tetri tab_tetri);

#endif
