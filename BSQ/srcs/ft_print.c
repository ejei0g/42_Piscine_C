/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:30:00 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 23:28:49 by dopark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_strc.h"
#include "main.h"
#include "ft_split.h"
#include "make_square.h"
#include "init.h"
#include "ft_string.h"
#include "error_test.h"
#include "ft_print.h"

void	print_map(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
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
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		print_arr(char **str)
{
	int		arr_len;
	int		key_len;
	int		**board;

	key_len = ft_strlen(str[0]);
	arr_len = mat_len(key_len, str);
	if (error_tcase(str, arr_len, key_len, -1) == -1)
	{
		cfree_malloc(str);
		return (-1);
	}
	if (arr_len == -1)
	{
		cfree_malloc(str);
		return (-1);
	}
	board = make_bord(arr_len);
	find_max_square(board, str, arr_len, key_len);
	print_map(str);
	cfree_malloc(str);
	return (0);
}
