/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:30:31 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/06 11:33:58 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_arr[10];
int		g_answer;

void	print_int(int num)
{
	char temp;

	temp = num + '0';
	write(1, &temp, 1);
}

void	print_puzzle(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		print_int(g_arr[i]);
		i++;
	}
	write(1, "\n", 1);
}

int		is_valid(int col)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (g_arr[i] == g_arr[col] || g_arr[col] - g_arr[i] ==
				col - i || g_arr[i] - g_arr[col] == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve_puzzle(int col)
{
	int row;

	row = 0;
	if (col == 10)
	{
		print_puzzle();
		g_answer++;
	}
	while (row < 10)
	{
		g_arr[col] = row;
		if (is_valid(col))
			solve_puzzle(col + 1);
		row++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;

	i = 0;
	g_answer = 0;
	while (i < 10)
	{
		g_arr[i] = 0;
		i++;
	}
	solve_puzzle(0);
	return (g_answer);
}
