/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:18:54 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/26 20:58:19 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush_if(int a, int b, int x, int y)
{
	if (a == 1 && b == 1)
		ft_putchar('A');
	else if (a == 1 && b == x)
		ft_putchar('C');
	else if (a == y && b == 1)
		ft_putchar('A');
	else if (a == y && b == x)
		ft_putchar('C');
	else if (a == 1 || a == y)
		ft_putchar('B');
	else if (b == 1 || b == x)
		ft_putchar('B');
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
