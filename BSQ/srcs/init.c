/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:47:45 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 23:47:18 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int		**make_bord(int arr_len)
{
	int i;
	int **board;

	i = 0;
	board = (int **)malloc(sizeof(int *) * (arr_len));
	while (i < arr_len)
	{
		board[i] = (int *)malloc(sizeof(int) * (arr_len));
		i++;
	}
	return (board);
}

void	ifree_malloc(int **board, int arr_len)
{
	int i;

	i = 0;
	while (i < arr_len)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

void	cfree_malloc(char **board)
{
	int i;

	i = 0;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
}
