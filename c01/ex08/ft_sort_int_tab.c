/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:09:43 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/27 17:15:00 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;

	i = 0;
	if (size == 1)
		return ;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			ft_swap_int((tab + i), (tab + i + 1));
		i++;
	}
	ft_sort_int_tab(tab, size - 1);
}
