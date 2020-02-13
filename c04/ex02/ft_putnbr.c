/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:57:58 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/03 20:57:18 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(unsigned int mod)
{
	unsigned int temp;

	if (mod < 10)
		temp = mod + '0';
	else
		temp = mod + 'a';
	write(1, &temp, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int div;
	unsigned int mod;
	unsigned int uns_int;

	if (nb < 0)
	{
		write(1, "-", 1);
		uns_int = (unsigned int)(nb * -1);
	}
	else
		uns_int = (unsigned int)nb;
	div = uns_int / 10;
	mod = uns_int % 10;
	if (div == 0)
	{
		ft_print(mod);
		return ;
	}
	ft_putnbr(div);
	ft_print(mod);
}
