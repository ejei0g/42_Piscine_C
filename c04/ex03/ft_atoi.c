/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:32:06 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/03 21:53:21 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char *str)
{
	if (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' ||
			*str == '\r' || *str == ' ')
	{
		return (1);
	}
	else
		return (0);
}

int		is_numeric(char c)
{
	if (47 < c && c < 58)
		return (1);
	else
		return (0);
}

int		sum(char *str, int i)
{
	int num;

	num = 0;
	while (is_numeric(str[i]))
	{
		num = num * 10;
		num = num + str[i] - 48;
		i++;
	}
	return (num);
}

int		chk_rtn(char *str)
{
	if (is_space(str) && (!is_numeric(*(str + 1)) && *(str + 1)
				!= '-' && *(str + 1) != '+' && !is_space(str + 1)))
		return (1);
	else if ((*str == '-' || *str == '+') && (!is_numeric(*(str + 1))
				&& *(str + 1) != '-' && *(str + 1) != '+'))
		return (1);
	else if (!is_space(str) && *str != '-' &&
			*str != '+' && !is_numeric(*str))
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int sign;
	int i;
	int num;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i])
	{
		if (chk_rtn(&str[i]))
			return (0);
		if (!is_space(&str[i]) && str[i] == '-')
			sign *= -1;
		else if (is_numeric(str[i]))
		{
			num = sum(str, i);
			break ;
		}
		i++;
	}
	return (num * sign);
}
