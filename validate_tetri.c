/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:16:10 by acauchy           #+#    #+#             */
/*   Updated: 2017/11/30 16:17:56 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Un genre de strcmp. Verifie que le code de tetri passe dans buff
** commencant a l'index 'start' est valide. Saute les '\n'.
*/

static char	*detect_tetri(char *buff, int start, t_tetridata tetri)
{
	int	i;
	int	j;

	i = 0;
	j = start;
	while (tetri.filecode != '\0')
	{
		if (buff[j] == '\n')
			--i;
		else if (tetri.filecode[i] != buff[j])
			return (NULL);
		++j;
		++i;
	}
	return (tetri.code);
}

/*
** Compare le tetrimino trouve avec ceux possibles.
** Renvoie le code du tetrimino trouve avec celui possible
** NULL = error
**
** 19 = nombre de tetri possibles renseignes dans le tableau statique
*/

static char	*compare_code(int start, char *buff)
{
	char	*ret;
	int		i;

	i = 0;
	while (i < 19)
	{
		if ((ret = detect_tetri(buff, start, g_tetridatas[i])))
			return (ret);
		++i;
	}
	return (NULL);
}

/*
** Return the pos of the 1st # in the buffer.
** -1 = error.
*/

static int	find_start(char *buff)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
			return (i);
		if (buff[i] != '.' && (buff[i] != '\n' ||
					i == 4 || i == 9 || i == 14 || i == 19))
			return (-1);
		++i;
	}
	return (-1);
}

/*
** Return the pos of the 4th (hopefully last) # in the buffer.
** -1 = error.
*/

static int	find_end(char *buff, int start)
{
	int	i;
	int	count;
	int	end;

	i = start;
	count = 0;
	end = -1;
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			++count;
			if (count > 4)
				return (-1);
			if (count == 4)
				end = i;
		}
		else if (buff[i] != '.' && (buff[i] != '\n' ||
					i == 4 || i == 9 || i == 14 || i == 19))
			return (-1);
		++i;
	}
	return (end);
}

/*
** If the tetri in buff is valid, returns his code.
** buff is expected to be of size 20.
*/

char		*validate_tetri(char *buff)
{
	int	i;
	int	start;

	i = 0;
	if (buff[4] != '\n'
			|| buff[9] != '\n'
			|| buff[14] != '\n'
			|| buff[19] != '\n'
			|| (start = find_start(buff)) == -1
			|| find_end(buff, start) == -1)
		return (NULL);
	return (compare_code(start, buff));
}
