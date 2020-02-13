/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:37:02 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/11 01:06:33 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		chk_flag(char c, char *base, int flag)
{
	int i;

	i = 0;
	if (flag == 0)
	{
		if (c == ' ' || (8 < c && c < 14))
			return (1);
	}
	if (flag == 1 || flag == 2)
	{
		while (base[i])
		{
			if (c == base[i] && flag == 1)
				return (1);
			else if (c == base[i] && flag == 2)
				return (i);
			i++;
		}
		return (0);
	}
	return (0);
}

int		error_case(char *base)
{
	int	i;
	int j;
	int len;

	i = 0;
	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (1);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || chk_flag(base[i], base, 0))
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

int		sum(char *str, int i, char *base)
{
	int num;
	int len;

	len = 0;
	num = 0;
	while (base[len])
		len++;
	while (chk_flag(str[i], base, 1))
	{
		num = num * len;
		num = num + chk_flag(str[i], base, 2);
		i++;
	}
	return (num);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int num;

	i = 0;
	sign = 1;
	num = 0;
	if (error_case(base))
		return (0);
	while (chk_flag(str[i], base, 0))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (chk_flag(str[i], base, 1))
		num = sum(str, i, base);
	else
		return (0);
	return (num * sign);
}
