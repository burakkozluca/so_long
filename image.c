/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakkozluca <burakkozluca@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:51:33 by burakkozluc       #+#    #+#             */
/*   Updated: 2022/11/03 09:04:28 by burakkozluc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_img *so_long, void *image, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx,
		so_long->mlx_win, image, x * 32, y * 32);
}

void	addimage(t_img *so_long)
{
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/wall.xpm", so_long->w, so_long->h);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/door.xpm", so_long->w, so_long->h);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/player.xpm", so_long->w, so_long->h);
	so_long->co = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/coin.xpm", so_long->w, so_long->h);
	so_long->background = mlx_xpm_file_to_image(so_long->mlx,
			"./xpm/background.xpm", so_long->w, so_long->h);
}

void    xpm(t_img *so_long)
{
	int	x;
	int	y;

	addimage(so_long);
	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == '1')
				img_draw(so_long, so_long->wall, x, y);
			else if (so_long->map[y][x] == '0')
				img_draw(so_long, so_long->background, x, y);
			else if (so_long->map[y][x] == 'P')
				img_draw(so_long, so_long->player, x, y);
			else if (so_long->map[y][x] == 'E')
				img_draw(so_long, so_long->exit, x, y);
			else if (so_long->map[y][x] == 'C')
				img_draw(so_long, so_long->co, x, y);
			x++;
		}
		y++;
	}
}