/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcontroller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkozluca <bkozluca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:48:49 by burakkozluc       #+#    #+#             */
/*   Updated: 2022/12/05 13:54:07 by bkozluca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pathfindrec(t_img *so_long, int y, int x, int **mapint)
{
	if (so_long->map[y][x] == 'P' || so_long->isway == 1)
	{
		so_long->isway = 1;
		return ;
	}
	if (so_long->map[y - 1][x] != '1' && mapint[y - 1][x] < 1)
	{
		mapint[y - 1][x] = mapint[y][x] + 1;
		pathfindrec(so_long, y - 1, x, mapint);
	}
	if (so_long->map[y + 1][x] != '1' && mapint[y + 1][x] < 1)
	{
		mapint[y + 1][x] = mapint[y][x] + 1;
		pathfindrec(so_long, y + 1, x, mapint);
	}
	if (so_long->map[y][x + 1] != '1' && mapint[y][x + 1] < 1)
	{
		mapint[y][x + 1] = mapint[y][x] + 1;
		pathfindrec(so_long, y, x + 1, mapint);
	}
	if (so_long->map[y][x - 1] != '1' && mapint[y][x - 1] < 1)
	{
		mapint[y][x - 1] = mapint[y][x] + 1;
		pathfindrec(so_long, y, x - 1, mapint);
	}
}

void	pathnumber(t_img *so_long, int y, int x)
{
	int	**mapint;
	int	i;
	int	j;

	i = -1;
	mapint = (int **)malloc(sizeof(int *) * so_long->len_x);
	while (++i < so_long->len_x)
	{
		mapint[i] = (int *)malloc(sizeof(int) * so_long->len_y);
		j = -1;
		while (++j < so_long->len_y)
			mapint[i][j] = 0;
	}
	mapint[y][x] = 1;
	pathfindrec(so_long, y, x, mapint);
	i = -1;
	while (++i < so_long->len_x)
	{
		free(mapint[i]);
	}
	free(mapint);
}

void	pathfind(t_img *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (so_long->map[++i])
	{
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'E' || so_long->map[i][j] == 'C')
			{
				so_long->isway = 0;
				pathnumber(so_long, i, j);
				if (so_long->isway != 1)
				{
					if (so_long->map[i][j] == 'E')
						error_printf("No valid path to exit!", so_long);
					if (so_long->map[i][j] == 'C')
						error_printf("No valid path to coin!", so_long);
				}
			}
		}
	}
}
