/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_strc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:46:54 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 17:40:23 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_split.h"
#include "ft_string.h"
#include "main.h"
#include "file_strc.h"

int		ft_open_file(char *filename)
{
	int		fd;
	char	buf_str;
	int		file_len;

	file_len = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("FILE ERROR : OPEN FAIL\n");
		return (fd);
	}
	while (read(fd, &buf_str, 1))
		file_len++;
	close(fd);
	return (file_len);
}

void	ft_read_file(char *filename, char *raw_txt)
{
	int		fd;
	int		i;
	char	buf_str;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &buf_str, 1))
	{
		raw_txt[i] = buf_str;
		i++;
	}
	close(fd);
	raw_txt[i] = '\0';
}

char	**create_map(char *filename)
{
	char	*raw_txt;
	char	**split_txt;

	if (*filename == '\0')
		ft_putstr("NO FILE");
	raw_txt = malloc(sizeof(char) * (ft_open_file(filename) + 1));
	ft_read_file(filename, raw_txt);
	split_txt = ft_split(raw_txt, "\n");
	free(raw_txt);
	return (split_txt);
}
