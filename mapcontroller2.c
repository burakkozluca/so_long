/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontroller2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakkozluca <burakkozluca@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:48:45 by burakkozluc       #+#    #+#             */
/*   Updated: 2022/11/29 09:49:40 by burakkozluc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	iscollectible(t_img *so_long)
{
	int		i;
	int		j;
	int		c_counter;

	i = 0;
	c_counter = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'C')
				c_counter++;
			j++;
		}
		i++;
	}
	if (c_counter <= 0)
	{
		write(1, "Error(Haritada coin yok!)\n", 26);
		exit(1);
	}
}

void	allfunc(t_img *so_long)
{
	isrectangular(so_long);
	ismaptrue(so_long);
	iswalltrue(so_long);
	arg_control(so_long);
	isduplicate(so_long);
	iscollectible(so_long);
}