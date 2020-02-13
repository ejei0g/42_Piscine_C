/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:59:03 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/11 02:00:35 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	ft_atoi_base(char *str, char *base);
extern int	error_case(char *base);

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void		ft_itoi_base(int nbr, char *base_to, char *result)
{
	int	div;
	int	mod;
	int	length;

	length = ft_strlen(base_to);
	div = nbr / length;
	mod = nbr % length;
	if (div == 0)
	{
		*result = base_to[mod];
		return ;
	}
	ft_itoi_base(div, base_to, result + 1);
	*result = base_to[mod];
}

int			check_digit(int nbr, char *base_to)
{
	int	digit;
	int div;
	int base;

	base = ft_strlen(base_to);
	div = nbr / base;
	digit = 0;
	while (div)
	{
		div = div / base;
		digit++;
	}
	return (digit + 1);
}

void		rev_tab(char *str, int size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		temp[i] = str[size - 1 - i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		str[i] = temp[i];
		i++;
	}
	free(temp);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;
	int		digit;

	if (error_case(base_from) || error_case(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	digit = check_digit(num, base_to);
	if (num < 0)
	{
		result = (char *)malloc(sizeof(char) * (digit + 2));
		*result = '-';
		num *= -1;
		ft_itoi_base(num, base_to, result + 1);
		rev_tab(result + 1, digit);
		result[digit + 1] = '\0';
	}
	else
	{
		result = (char *)malloc(sizeof(char) * (digit + 1));
		ft_itoi_base(num, base_to, result);
		rev_tab(result, digit);
		result[digit] = '\0';
	}
	return (result);
}
