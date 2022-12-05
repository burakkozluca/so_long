/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coincollect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkozluca <bkozluca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:47:33 by burakkozluc       #+#    #+#             */
/*   Updated: 2022/12/05 13:53:18 by bkozluca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	topcoin(t_img *so_long)
{
	so_long->map[so_long->y_kord][so_long->x_kord] = '0';
	so_long->map[so_long->y_kord - 1][so_long->x_kord] = 'P';
	so_long->g_move++;
	xpm(so_long);
	so_long->coin += 1;
}

void	leftcoin(t_img *so_long)
{
	so_long->map[so_long->y_kord][so_long->x_kord] = '0';
	so_long->map[so_long->y_kord][so_long->x_kord - 1] = 'P';
	so_long->g_move++;
	xpm(so_long);
	so_long->coin += 1;
}

void	downcoin(t_img *so_long)
{
	so_long->map[so_long->y_kord][so_long->x_kord] = '0';
	so_long->map[so_long->y_kord + 1][so_long->x_kord] = 'P';
	so_long->g_move++;
	xpm(so_long);
	so_long->coin += 1;
}

void	rightcoin(t_img *so_long)
{
	so_long->map[so_long->y_kord][so_long->x_kord] = '0';
	so_long->map[so_long->y_kord][so_long->x_kord + 1] = 'P';
	so_long->g_move++;
	xpm(so_long);
	so_long->coin += 1;
}
