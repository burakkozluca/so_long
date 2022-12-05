/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkozluca <bkozluca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:50:06 by bkozluca          #+#    #+#             */
/*   Updated: 2022/06/09 15:12:02 by bkozluca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_nbr(int n)
{
	int	digit;
	int	sayi;

	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	sayi = n;
	digit = 0;
	if (!n)
	{
		ft_print_char(48);
		return (1);
	}
	while (sayi != 0 && ++digit)
		sayi /= 10;
	if (n < 0 && ++digit)
	{
		ft_print_char('-');
		n *= -1;
	}
	if (n > 9)
		ft_print_nbr(n / 10);
	ft_print_char((n % 10) + 48);
	return (digit);
}

int	ft_print_char_hex(unsigned int x, char format)
{
	static int	i;
	char		c;

	i = 0;
	c = (x % 16) + 48;
	if (x)
		if ((x / 16) != 0)
			ft_print_char_hex(x / 16, format);
	if ((x % 16) < 10 && ++i)
		write(1, &c, 1);
	else
	{
		c += 39;
		if (format == 'X')
			c -= 32;
		write(1, &c, 1);
		++i;
	}
	return (i);
}

int	ft_print_unsigned_char(unsigned int u)
{
	static int	i;
	char		c;

	c = (u % 10) + 48;
	i = 0;
	if (u)
		if ((u / 10) != 0)
			ft_print_unsigned_char(u / 10);
	write(1, &c, 1);
	return (++i);
}
