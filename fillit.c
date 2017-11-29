/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:53:46 by acauchy           #+#    #+#             */
/*   Updated: 2017/11/29 17:24:39 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage : fillit <file>\n");
		return (0);
	}
	argv[0] = NULL;
	return (0);
}
