/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakkozluca <burakkozluca@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:48:39 by burakkozluc       #+#    #+#             */
/*   Updated: 2022/11/04 22:43:23 by burakkozluc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	turnleft(t_img *so_long);
void	turnup(t_img *so_long);
void	turndown(t_img *so_long);
void	turnright(t_img *so_long);

int buttons(int keycode, t_img *so_long)
{
	if (keycode == 53)
	{
		write(1, "Oyun kapatildi", 14);
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
		free(so_long->map);
		free(so_long);
		exit(0);
	}
	else if (keycode == 0)
		turnleft(so_long);
	else if (keycode == 13)
		turnup(so_long);
	else if (keycode == 1)
		turndown(so_long);
	else if (keycode == 2)
		turnright(so_long);
	ft_makestr(so_long->g_move);
	write(1, "\n", 1);
	return (0);
}

void	turnleft(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == '0')
	{
		so_long->map[so_long->y_kord][so_long->x_kord] = '0';
		so_long->map[so_long->y_kord][so_long->x_kord - 1] = 'P';
		so_long->g_move++;
		xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == 'C')
		leftcoin(so_long);
	else if (so_long->map[so_long->y_kord][so_long->x_kord - 1] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1, "Tebrikler!", 10);
			free(so_long->map);
			free(so_long);
			exit(0);
		}
		else
			write(1, "Lütfen bütün coinleri toplayın!\n", 36);
	}
}

void	turnup(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == '0')
	{
		so_long->map[so_long->y_kord][so_long->x_kord] = '0';
		so_long->map[so_long->y_kord - 1][so_long->x_kord] = 'P';
		so_long->g_move++;
		xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == 'C')
		topcoin(so_long);
	else if (so_long->map[so_long->y_kord - 1][so_long->x_kord] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1, "Tebrikler!", 10);
			free(so_long->map);
			free(so_long);
			exit(0);
		}
		else
			write(1, "Lütfen bütün coinleri toplayın!\n", 36);
	}
}

void	turndown(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord + 1][so_long->x_kord] == '0')
	{
		so_long->map[so_long->y_kord][so_long->x_kord] = '0';
		so_long->map[so_long->y_kord + 1][so_long->x_kord] = 'P';
		so_long->g_move++;
		xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord + 1][so_long->x_kord] == 'C')
		downcoin(so_long);
	else if (so_long->map[so_long->y_kord + 1][so_long->x_kord] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1, "Tebrikler!", 10);
			free(so_long->map);
			free(so_long);
			exit(0);
		}
		else
			write(1, "Lütfen bütün coinleri toplayın!\n", 36);
	}
}

void	turnright(t_img *so_long)
{
	player(so_long);
	if (so_long->map[so_long->y_kord][so_long->x_kord + 1] == '0')
	{
		so_long->map[so_long->y_kord][so_long->x_kord] = '0';
		so_long->map[so_long->y_kord][so_long->x_kord + 1] = 'P';
		so_long->g_move++;
		xpm(so_long);
	}
	else if (so_long->map[so_long->y_kord][so_long->x_kord + 1] == 'C')
		rightcoin(so_long);
	else if (so_long->map[so_long->y_kord][so_long->x_kord + 1] == 'E')
	{
		if (so_long->coin == so_long->g_coin)
		{
			write(1, "Tebrikler!", 10);
			free(so_long->map);
			free(so_long);
			exit(0);
		}
		else
			write(1, "Lütfen bütün coinleri toplayın!\n", 36);
	}
}