/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 01:51:44 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/25 02:05:25 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int a, int b, int c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, ",", 1);
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	while (a <= 9)
	{
		while (b <= 9)
		{
			while (c <= 9)
			{
				if (a < b && b < c)
					ft_write(a + 48, b + 48, c + 48);
				c++;
			}
			c = 1;
			b++;
		}
		b = 1;
		a++;
	}
}

int		main(void)
{
	ft_print_comb();
	return (0);
}
