/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 02:59:32 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/24 04:58:00 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_00_write(int a, int b)
{
	int digit_a1;
	int digit_a0;
	int digit_b1;
	int digit_b0;

	digit_a1 = a / 10 + 48;
	digit_a0 = a % 10 + 48;
	digit_b1 = b / 10 + 48;
	digit_b0 = b % 10 + 48;
	write(1, &digit_a1, 1);
	write(1, &digit_a0, 1);
	write(1, &digit_b1, 1);
	write(1, &digit_b0, 1);
	if (a != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		while (b <= 99)
		{
			ft_00_write(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}

int		main(void)
{
	ft_print_comb2();
	return (0);
}
