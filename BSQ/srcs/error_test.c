/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:03:14 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 23:51:16 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_test.h"
#include "ft_string.h"
#include "main.h"
#include <unistd.h>
#include <string.h>

void	printerror(void)
{
	char	*err;

	err = "map error";
	write(2, err, ft_strlen(err));
}

int		key_tcase(char *str)
{
	int	len;
	int	key_len;

	key_len = ft_strlen(str);
	len = key_len;
	if (key_len < 4)
	{
		return (-1);
	}
	if (str[len - 1] == str[len - 2] ||
		str[len - 2] == str[len - 3] ||
		str[len - 3] == str[len - 1])
	{
		return (-1);
	}
	return (0);
}

int		error_tcase(char **str, int arr_len, int key_len, int obstacle_check)
{
	int	i;
	int	j;
	int	row_check;

	i = 0;
	row_check = arr_len;
	while (str[i])
	{
		if (i == 0)
		{
			i++;
			continue;
		}
		j = 0;
		while (str[i][j])
		{
			j++;
			if (str[0][key_len - 2] != str[i][j] && str[i][j] != '\0')
				obstacle_check = 0;
		}
		if (j != row_check)
			return (-1);
		i++;
	}
	return (obstacle_check);
}
