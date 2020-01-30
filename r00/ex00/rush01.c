/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 10:23:02 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/26 20:57:08 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush_if(int a, int b, int x, int y)
{
	if (a == 1 && b == 1)
		ft_putchar('/');
	else if (a == 1 && b == x)
		ft_putchar('\\');
	else if (a == y && b == 1)
		ft_putchar('\\');
	else if (a == y && b == x)
		ft_putchar('/');
	else if (a == 1 || a == y)
		ft_putchar('*');
	else if (b == 1 || b == x)
		ft_putchar('*');
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
