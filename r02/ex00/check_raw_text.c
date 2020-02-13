/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_raw_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:25:44 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/09 23:17:37 by sohpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	[DESCRIPTION]
**	This function checks if the string only has numbers.
*/

int		is_all_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(47 < str[i] && str[i] < 58))
			return (0);
		i++;
	}
	return (1);
}

int		count_zero(char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '0')
			count++;
		i++;
	}
	return (count);
}

/*
**	[DESCRIPTION]
**	This function checks if the given string is all zeroes.
*/

int		is_all_zero(char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result = result * 10;
		result = result + *str++ - 48;
	}
	return (result);
}

/*
**	[DESCRIPTION]
**	This function takes the structure data and put the values
**	in the right array's right place.
**	ex) if the key is "10", we store the value of that structure
**		in that array's index.
**	ex) if the key is "1000", we divide 3/3, thus get integer '1'
**		and assign the value in hundreds[1].
*/

void	ft_stack_data(t_dict_data *dict_, int line_count)
{
	int i;

	i = 0;
	while (i < line_count)
	{
		if (ft_strlen(dict_[i].key) < 3 && is_all_numeric(dict_[i].key))
		{
			g_numbers[ft_atoi(dict_[i].key)] = dict_[i].value;
		}
		if (dict_[i].key[0] == '1' && is_all_zero(dict_[i].key))
		{
			if (count_zero(dict_[i].key) == 2)
				g_hundreds[0] = dict_[i].value;
			else if (count_zero(dict_[i].key) % 3 == 0)
				g_hundreds[count_zero(dict_[i].key) / 3] = dict_[i].value;
		}
		i++;
	}
}
