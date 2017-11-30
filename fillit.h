/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:28:22 by acauchy           #+#    #+#             */
/*   Updated: 2017/11/30 14:01:44 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_grid_s
{
	unsigned char	*grid;
	int				gridsize;
}				t_grid;

typedef struct	s_tetridata
{
	char	*filecode;
	char	*code;
}				t_tetridata;

const t_tetridata g_tetridatas[] =
{
	{
		.filecode = "#...#...#...#",
		.code = "BBB"
	},
	{
		.filecode = "#...#...##",
		.code = "BBD"
	},
	{
		.filecode = "#...###",
		.code = "BDD"
	},
	{
		.filecode = "##..#...#",
		.code = "DGBB"
	},
	{
		.filecode = "###.#",
		.code = "BHDD"
	},
	{
		.filecode = ".#...#..##",
		.code = "BBG"
	},
	{
		.filecode = "..#.###",
		.code = "BGG"
	},
	{
		.filecode = "###",
		.code = "DDD"
	},
	{
		.filecode = "##...#...#",
		.code = "DBB"
	},
	{
		.filecode = "###...#",
		.code = "DDB"
	},
	{
		.filecode = "##...##",
		.code = "DBD"
	},
	{
		.filecode = ".##.##",
		.code = "DGBG"
	},
	{
		.filecode = ".#..##..#",
		.code = "BGB"
	},
	{
		.filecode = "#...##...#",
		.code = "BDB"
	},
	{
		.filecode = "#...##..#",
		.code = "BDGB"
	},
	{
		.filecode = ".#..##...#",
		.code = "BGDB"
	},
	{
		.filecode = ".#..###",
		.code = "BGDD"
	},
	{
		.filecode = "###..#",
		.code = "DDGB"
	},
	{
		.filecode = "##..##",
		.code = "DBG"
	}
};

#endif
