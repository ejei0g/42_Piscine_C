/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:21:25 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/12 03:46:55 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	*i_arr;
	int	size;
	int	i;

	i = 0;
	if (min >= max || max - min > 2147483647)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	if (!(i_arr = (int *)malloc(sizeof(int) * size + 1)))
	{
		*range = 0;
		return (-1);
	}
	while (i < size)
	{
		i_arr[i] = min + i;
		i++;
	}
	i_arr[size] = 0;
	*range = i_arr;
	return (size);
}
