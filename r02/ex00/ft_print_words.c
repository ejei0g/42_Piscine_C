/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:31:38 by sohpark           #+#    #+#             */
/*   Updated: 2020/02/09 22:32:59 by sohpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str != 0)
	{
		str++;
		i++;
	}
	return (i);
}

void	print_output(char **output, int w_count)
{
	int i;

	i = 0;
	while (i < w_count)
	{
		if (output[i] == 0)
		{
			ft_putstr("Dict Error\n");
			return ;
		}
		i++;
	}
	i = 1;
	while (i <= w_count)
	{
		ft_putstr(output[w_count - i]);
		if (i == w_count)
			break ;
		write(1, " ", 1);
		i++;
	}
}
