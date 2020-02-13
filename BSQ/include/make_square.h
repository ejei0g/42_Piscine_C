/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:52:19 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 17:13:59 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_SQUARE_H
# define MAKE_SQUARE_H

# include <stdlib.h>
# include "main.h"

int		get_min(int l_up, int up, int left);
int		mat_len(int key_len, char **str);
void	make_square(int **board, int *max_p, int i, int j);
void	put_square(char **str, int *max_p, int key_len);
void	find_max_square(int **board, char **str, int arr_len, char key_len);
void	ifree_malloc(int **board, int arr_len);
void	cfree_malloc(char **board);
#endif
