/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkozluca <bkozluca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:34:36 by bkozluca          #+#    #+#             */
/*   Updated: 2022/12/05 14:37:27 by bkozluca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_print(t_img *so_long)
{
	int		fd;
	int		i;
	int		uz_y;

	i = 0;
	uz_y = -1;
	fd = open(so_long->map_input[1], O_RDONLY);
	so_long->y_kord = 0;
	so_long->map = malloc((line_len(so_long) + 1) * sizeof(char *));
	while (++uz_y < line_len(so_long))
	{
		so_long->map[uz_y] = get_next_line(fd);
		write(1, so_long->map[uz_y], ft_strlen(so_long->map[uz_y]));
	}
	so_long->map[uz_y] = NULL;
	close(fd);
}

int	closescreen(t_img *so_long)
{
	write(1, "Oyun kapatildi", 14);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	exit(0);
}

int	main(int argc, char **map_input)
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;

	if (argc != 2)
		return (write(1, "Argüman sayisi hatali!\n", 23));
	img = (t_img *)malloc(sizeof(t_img));
	mlx = mlx_init();
	img->mlx = mlx;
	img->map_input = map_input;
	mapfilecontrol(img);
	arg_control(img);
	definevariable(img);
	mlx_win = mlx_new_window(mlx, column_len(img) * 32,
			line_len(img) * 32, "burakkozluca");
	img->mlx_win = mlx_win;
	map_print(img);
	xpm(img);
	allfunc(img);
	counter_coin(img);
	mlx_hook(img->mlx_win, 17, 1L << 0, closescreen, &img->mlx);
	mlx_hook(img->mlx_win, 2, 1L << 0, buttons, &img->mlx);
	mlx_loop(img);
	free(img->map);
	free(img);
}
