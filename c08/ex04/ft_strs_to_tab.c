/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:51:15 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/13 02:14:21 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_str_len(char *str)
{
	int	length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

char				*ft_str_copy(char *origin)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = ft_str_len(origin);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		copy[i] = origin[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *tab;
	int			i;

	i = 0;
	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return ((void *)0);
	while (i < ac)
	{
		tab[i].size = ft_str_len(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_str_copy(av[i]);
		i++;
	}
	tab[ac].size = 0;
	tab[ac].str = (void *)0;
	tab[ac].copy = (void *)0;
	return (tab);
}
