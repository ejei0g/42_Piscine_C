/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 05:00:08 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/25 16:47:33 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int n)
{
	int a;

	a = n + 48;
	write(1, &a, 1);
}

void	ft_recul(int n)
{
	if (n == 0)
		return ;
	ft_recul(n / 10);
	ft_write(n % 10);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 0)
	{
		ft_recul(nbr);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_recul(nbr * -1);
	}
	else
		write(1, "0", 1);
}

int		main(void)
{
	ft_putnbr(123123123);
	return (0);
}
