/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 23:07:44 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/26 00:09:24 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putcomma(void)
{
	char a;
	char b;

	a = ',';
	b = ' ';
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_putint(int nbr)
{
	int num;

	num = nbr + 48;
	write(1, &num, 1);
}

void	ft_rec(int n, int numlist, int *arr, int digit)
{
	int i;

	i = 0;
	if (n == digit)
		return ;
	while (numlist < 10)
	{
		arr[n] = numlist;
		if (n == digit - 1)
		{
			while (i < digit)
			{
				ft_putint(arr[i]);
				i++;
			}
			i = 0;
			if (arr[0] == digit + 4)
				return ;
			else
				ft_putcomma();
		}
		ft_rec(n + 1, numlist + 1, arr, digit);
		numlist++;
	}
}

void	ft_print_combn(int n)
{
	int startnum;
	int selected[n];
	int numlist;

	startnum = 0;
	numlist = 0;
	ft_rec(startnum, numlist, selected, n);
}

int		main(void)
{
	int n;

	n = 6;
	ft_print_combn(n);
}
