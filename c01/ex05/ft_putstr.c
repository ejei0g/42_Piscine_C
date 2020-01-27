/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:21:53 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/27 17:12:13 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_charlen(char *str)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while (str[i] != '\0')
	{
		i++;
		temp++;
	}
	return (temp);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_charlen(str));
}
