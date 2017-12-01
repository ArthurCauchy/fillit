/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:22:17 by acauchy           #+#    #+#             */
/*   Updated: 2017/12/01 10:40:03 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft.h"

/*
** Print 'error' then exit with EXIT_FAILURE.
*/

void	exit_error(void)
{
	ft_putend("error");
	exit (EXIT_FAILURE);
}

/*
** Print the usage of the then exit with EXIT_SUCCESS.
*/

void    exit_usage(void)
{
	ft_putendl("usage : fillit <file.fillit>");
	exit(EXIT_SUCCESS);
}
