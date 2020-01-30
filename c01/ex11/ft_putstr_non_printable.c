/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:18:31 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/29 21:52:32 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_wrt_hex(int dec)
{
	int num;

	num = dec;
	if (dec < 10)
	{
		num += 48;
		write(1, &num, 1);
	}
	else
	{
		num += 87;
		write(1, &num, 1);
	}
}

void	hex(int num)
{
	int quo;
	int rem;

	quo = num / 16;
	rem = num % 16;
	if (num < 16)
	{
		ft_wrt_hex(rem);
		return ;
	}
	hex(quo);
	ft_wrt_hex(rem);
}

int		ft_chkasc(char str)
{
	int ret;

	ret = 0;
	if (31 < str && str < 127)
		ret = 1;
	else
		ret = 0;
	return (ret);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_chkasc(str[i]) == 0)
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			hex(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return ;
}
