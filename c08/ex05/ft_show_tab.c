/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 01:03:40 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/13 02:18:43 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_int(int nbr)
{
	char tmp;

	if (nbr < 10)
	{
		tmp = nbr + '0';
		write(1, &tmp, 1);
	}
	else
	{
		tmp = nbr % 10 + '0';
		ft_print_int(nbr / 10);
		write(1, &tmp, 1);
	}
}

int		ft_stocks_len(struct s_stock_str *par)
{
	int res;

	res = 0;
	while (par[res].str)
		res++;
	return (res);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;
	int stock_len;

	i = 0;
	stock_len = ft_stocks_len(par);
	while (i < stock_len)
	{
		ft_print_str(par[i].str);
		write(1, "\n", 1);
		ft_print_int(par[i].size);
		write(1, "\n", 1);
		ft_print_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
