/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:38:30 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/10 17:41:05 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*i_arr;
	int i;
	int length;

	i = 0;
	if (min >= max || max - min > 2147483647)
		return (NULL);
	length = max - min;
	i_arr = (int *)malloc(sizeof(int) * (length + 1));
	if (!i_arr)
		return (NULL);
	while (i < length)
	{
		i_arr[i] = min + i;
		i++;
	}
	i_arr[length] = 0;
	return (i_arr);
}
