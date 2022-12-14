/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontroller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkozluca <bkozluca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:02:06 by bkozluca          #+#    #+#             */
/*   Updated: 2022/12/08 20:46:01 by bkozluca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_control(t_img *so_long)
{
	int	len;

	len = ft_strlen(so_long->map_input[1]);
	if (so_long->map_input[1][len - 1] != 'r'
	|| so_long->map_input[1][len - 2] != 'e')
	{
		write(1, "Harita Uzantisi Hatali\n", 23);
		exit(1);
	}
	if (so_long->map_input[1][len - 3] != 'b'
	|| so_long->map_input[1][len - 4] != '.')
	{
		write(1, "Harita Uzantisi Hatali\n", 23);
		exit(1);
	}
}

void	isrectangular(t_img *so_long)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
			j++;
		if (i != 0 && j != temp)
		{
			write(1, "Error(Harita dikdörtgen değil!)\n", 34);
			free(so_long->map);
			free(so_long);
			exit(1);
		}
		temp = j;
		i++;
	}
}

void	ismaptrue(t_img *so_long)
{
	int		i;
	int		j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E' || so_long->map[i][j] == 'C'
				|| so_long->map[i][j] == 'P' || so_long->map[i][j] == '1'
				|| so_long->map[i][j] == '0' || so_long->map[i][j] == '\n'
				|| so_long->map[i][j] == 'D')
				j++;
			else
			{
				write(1, "Error(Haritada farkli harf var)\n", 32);
				free(so_long->map);
				free(so_long);
				exit(1);
			}
		}
		i++;
	}
}

void	iswalltrue(t_img *so_long)
{
	int	i;
	int	j;

	i = -1;
	so_long->len_x = line_len(so_long);
	so_long->len_y = column_len(so_long);
	while (so_long->map[++i])
	{
		j = 0;
		while (j < so_long->len_y - 1)
		{
			if (so_long->map[0][j] != '1' || so_long->map[i][0] != '1')
			{
				write(1, "Error(Duvar hatası)\n", 20);
				exit(1);
			}
			if (so_long->map[so_long->len_x - 1][j] != '1'
				|| so_long->map[i][so_long->len_y - 1] != '1')
			{
				write(1, "Error(Duvar hatası)\n", 20);
				exit(1);
			}
			j++;
		}
	}
}

void	isduplicate(t_img *so_long)
{
	int	i;
	int	j;
	int	p_counter;
	int	e_counter;

	i = -1;
	p_counter = 0;
	e_counter = 0;
	while (so_long->map[++i])
	{
		j = -1;
		while (so_long->map[i][++j])
		{
			if (so_long->map[i][j] == 'P')
				p_counter++;
			if (so_long->map[i][j] == 'E')
				e_counter++;
		}
	}
	if (p_counter <= 0 || p_counter >= 2 || (e_counter <= 0))
	{
		write(1, "Error(Oyuncu veya kapı hatası!)\n", 32);
		exit(1);
	}
}
