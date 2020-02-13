/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:48:36 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 23:51:37 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE 1000000

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "file_strc.h"
#include "main.h"
#include "ft_split.h"
#include "make_square.h"
#include "init.h"
#include "ft_string.h"
#include "error_test.h"
#include "ft_print.h"

int		is_enter(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		chk_map_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		set_map(void)
{
	char *buf_str;

	buf_str = malloc(sizeof(char) * SIZE);
	read(0, buf_str, SIZE);
	if (is_enter(buf_str) < 2 || chk_map_len(buf_str) < 4)
	{
		write(2, "map error\n", 10);
		free(buf_str);
		return (1);
	}
	if (print_arr(ft_split(buf_str, "\n")) == -1)
		write(2, "map error\n", 10);
	free(buf_str);
	return (0);
}

void	set_maps(char *argv, int argc, int cnt)
{
	int fd;

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		write(2, "map error\n", 10);
		close(fd);
	}
	else
	{
		if (print_arr(create_map(argv)) == -1)
			write(2, "map error\n", 10);
	}
	if (cnt < argc - 1)
		ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int	cnt;

	cnt = 1;
	if (argc == 1)
	{
		if (set_map())
			return (0);
	}
	while (cnt < argc)
	{
		set_maps(argv[cnt], argc, cnt);
		cnt++;
	}
	return (0);
}
