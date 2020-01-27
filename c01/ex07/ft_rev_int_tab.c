/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:20:18 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/27 17:14:14 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp_arr[size];
	int i;

	i = 0;
	while (i < size)
	{
		temp_arr[i] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = temp_arr[size - i - 1];
		i++;
	}
}
