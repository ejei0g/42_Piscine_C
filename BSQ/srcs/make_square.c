/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 17:19:30 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/12 18:14:34 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_split.h"
#include "ft_string.h"
#include "make_square.h"
#include "ft_split.h"
#include "error_test.h"

int		get_min(int l_up, int up, int left)
{
	int min;
	int up_left_min;
	int l_up_left_min;

	min = 0;
	up_left_min = 0;
	l_up_left_min = 0;
	up_left_min = (up > left) ? left : up;
	l_up_left_min = (l_up > left) ? left : l_up;
	min = (l_up > up) ? up_left_min : l_up_left_min;
	return (min);
}

int		mat_len(int key_len, char **str)
{
	int		cnt;
	int		len;
	int		arr_len;

	arr_len = 0;
	cnt = 0;
	len = key_len;
	if (key_tcase(str[0]) == -1)
		return (-1);
	while ((len - 4) >= 0)
	{
		if (!(str[0][len - 4] >= '0' && str[0][len - 4] <= '9'))
		{
			return (-1);
		}
		arr_len = arr_len + ten_multiply((str[0][cnt] - 48), (len - 3));
		len--;
		cnt++;
	}
	return (arr_len);
}

void	make_square(int **board, int *max_p, int i, int j)
{
	max_p[3] = 1;
	if (!(i == 0 || j == 0))
		board[i][j] = get_min(board[i - 1][j - 1],
			board[i - 1][j], board[i][j - 1]) + 1;
	if (board[i][j] > max_p[2])
	{
		max_p[2] = board[i][j];
		max_p[0] = i;
		max_p[1] = j;
	}
}

void	put_square(char **str, int *max_p, int key_len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	i = max_p[0] - max_p[2] + 1;
	j = max_p[1] - max_p[2] + 1;
	while (i <= max_p[0])
	{
		j = max_p[1] - max_p[2] + 1;
		while (j <= max_p[1])
		{
			str[i][j] = str[0][key_len - 1];
			j++;
		}
		i++;
	}
}

void	find_max_square(int **board, char **str, int arr_len, char key_len)
{
	int	max_p[4];
	int	i;
	int	j;

	max_p[2] = 0;
	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{
			board[i][j] = (str[i + 1][j] == str[0][key_len - 2]) ? 0 : 1;
			if (board[i][j] == 1)
				make_square(board, max_p, i, j);
			j++;
		}
		i++;
	}
	max_p[0] = max_p[0] + 1;
	max_p[1] = max_p[1];
	ifree_malloc(board, arr_len);
	put_square(str, max_p, key_len);
}
