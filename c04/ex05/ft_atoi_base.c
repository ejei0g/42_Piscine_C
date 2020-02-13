/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:17:30 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/07 06:35:52 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		error_case(char *base)
{
	int i;
	int j;
	int len;

	len = 0;
	while (base[len])
		len++;
	i = 0;
	if (len < 2)
		return (1);
	while (base[i])
	{
		///space 처리
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

int		check_c(char c, char *base, int flag)
{
	int i;

	i = 0;
	if (flag == 0)
	{
		if (c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
				c == '\r' || c == ' ')
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

int		sum(char *str, int i, char *base)
{
	int num;
	int len;

	len = 0;
	num = 0;
	while (base[len])
		len++;
	while (check_c(str[i], base, 1))
	{
		num = num * len;
		num = num + check_c(str[i], base, 2);
		i++;
	}
	return (num);
}

int		chk_rtn(char *str, char *base)
{
	if (check_c(*str, base, 0) && (!check_c(*(str + 1), base, 1)
				&& !check_c(*(str + 1), base, 0) && *(str + 1) != '+'
				&& *(str + 1) != '-'))
		return (1);
	else if ((*str == '-' || *str == '+') && (!check_c(*(str + 1), base, 1)
				&& *(str + 1) != '-' && *(str + 1) != '+'))
		return (1);
	else if (*str != '-' && *str != '+' && !check_c(*str, base, 0) &&
				!check_c(*str, base, 1))
		return (1);
	else
		return (0);
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
	while (str[i])
	{
		if (chk_rtn(&str[i], base))
			return (0);
		if (check_c(str[i], base, 1) != 2 && str[i] == '-')
			sign *= -1;
		else if (check_c(str[i], base, 1))
		{
			num = sum(str, i, base);
			break ;
		}
		i++;
	}
	return (num * sign);
}
