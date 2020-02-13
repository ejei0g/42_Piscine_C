/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 01:10:08 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/03 16:52:44 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void			print_num(unsigned int nbr, int base, char *arr)
{
	unsigned int div;
	unsigned int mod;

	div = nbr / base;
	mod = nbr % base;
	if (div == 0)
	{
		write(1, &arr[mod], 1);
		return ;
	}
	print_num(div, base, arr);
	write(1, &arr[mod], 1);
}

int				error_case(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	num;

	len = ft_strlen(base);
	if (error_case(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = (unsigned int)nbr * -1;
	}
	else
		num = (unsigned int)nbr;
	print_num(num, len, base);
}
