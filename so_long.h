/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkozluca <bkozluca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:34:50 by bkozluca          #+#    #+#             */
/*   Updated: 2022/12/05 14:42:46 by bkozluca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/include/ft_printf.h"

typedef struct s_img
{
	void	*mlx;
	void	*mlx_win;
	char	**map_input;
	char	**map;
	int		*w;
	int		*h;
	void	*wall;
	void	*player;
	void	*background;
	void	*co;
	void	*exit;
	int		coin;
	int		index;
	int		g_move;
	int		g_coin;
	int		len_x;
	int		len_y;
	int		y_kord;
	int		x_kord;
	int		isway;
}		t_img;

//MAIN
int		closescreen(t_img *so_long);
void	map_print(t_img *so_long);

//MAPCONTROLLER
void	arg_control(t_img *so_long);
void	isrectangular(t_img *so_long);
void	ismaptrue(t_img *so_long);
void	iswalltrue(t_img *so_long);
void	isduplicate(t_img *so_long);

//MAPCONTROLLER2
void	iscollectible(t_img *so_long);
void	mapfilecontrol(t_img *so_long);
void	allfunc(t_img *so_long);

//UTILS
int		column_len(t_img *so_long);
int		line_len(t_img *so_long);
void	definevariable(t_img *so_long);
void	player(t_img *so_long);
void	counter_coin(t_img *so_long);

//UTILS2
void	ft_makestr(int nbr);
void	error_printf(char *str, t_img *so_long);

//IMAGE
void	img_draw(t_img *so_long, void *image, int x, int y);
void	addimage(t_img *so_long);
void	xpm(t_img *so_long);

//BUTTONS
int		buttons(int keycode, t_img *so_long);
void	turnleft(t_img *so_long);
void	turnup(t_img *so_long);
void	turndown(t_img *so_long);
void	turnright(t_img *so_long);

//COINCOLLECT
void	topcoin(t_img *so_long);
void	leftcoin(t_img *so_long);
void	downcoin(t_img *so_long);
void	rightcoin(t_img *so_long);

//PATHCONTROLLER
void	pathfindrec(t_img *so_long, int y, int x, int **mapint);
void	pathnumber(t_img *so_long, int y, int x);
void	pathfind(t_img *so_long);

#endif
