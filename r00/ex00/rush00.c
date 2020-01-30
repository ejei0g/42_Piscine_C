/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:21:56 by pkim              #+#    #+#             */
/*   Updated: 2020/01/26 20:55:36 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush_if(int a, int b, int x, int y)
{
	if ((a == 1 && b == 1) || (a == 1 && b == x))
		ft_putchar('o');
	else if ((a == y && b == 1) || (a == y && b == x))
		ft_putchar('o');
	else if (a == 1 || a == y)
		ft_putchar('-');
	else if (b == 1 || b == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int a;
	int b;

	a = 1;
	b = 1;
	while (a <= y)
	{
		while (b <= x)
		{
			rush_if(a, b, x, y);
			b++;
		}
		ft_putchar('\n');
		a++;
		b = 1;
	}
}
