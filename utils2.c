/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkozluca <bkozluca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:57:44 by bkozluca          #+#    #+#             */
/*   Updated: 2022/12/05 14:40:03 by bkozluca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_printf(char *str, t_img *so_long)
{
	ft_printf("Error: %s\n", str);
	free(so_long->map);
	free(so_long);
	exit (EXIT_FAILURE);
}

void	ft_makestr(int nbr)
{
	char	c;

	if (nbr >= 10)
		ft_makestr(nbr / 10);
	c = (nbr % 10) + 48;
	write(1, &c, 1);
}
