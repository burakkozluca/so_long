/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkozluca <bkozluca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:59:35 by bkozluca          #+#    #+#             */
/*   Updated: 2022/06/09 15:11:59 by bkozluca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (ft_print_str("(null)"));
	else
	{
		while (str[++i] != '\0')
			write(1, &str[i], 1);
		return (i);
	}
}
