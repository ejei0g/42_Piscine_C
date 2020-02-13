/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dic_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:20:41 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/09 23:18:54 by sohpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	[DESCRIPTION]
**	This function checks the file's validity and returns
**	the length of the texts in the file.
*/

int				ft_get_file(char *filename)
{
	int		fd;
	char	buf;
	int		text_length;

	text_length = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Dict Error\n");
		return (fd);
	}
	while (read(fd, &buf, 1))
		text_length++;
	close(fd);
	return (text_length);
}

void			ft_read(char *filename, char *raw_text)
{
	int		fd;
	char	buf;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		raw_text[i] = buf;
		i++;
	}
	close(fd);
	raw_text[i] = '\0';
}

t_dict_data		*ft_add_struct(char **split_text, int line_count)
{
	int			i;
	t_dict_data	*dict;

	i = 0;
	dict = (t_dict_data *)malloc(sizeof(t_dict_data) * line_count + 1);
	while (i < line_count)
	{
		ft_input_key_value(dict[i].key, dict[i].value, split_text[i]);
		i++;
	}
	return (dict);
}

int				ft_line_count(char **split_text)
{
	int	length;

	length = 0;
	while (split_text[length])
		length++;
	return (length);
}

/*
**	[DESCRIPTION]
**	This function tidies up the raw text, and store them
**	in a structure array named "dictionary".
*/

int				create_dic(char *filename)
{
	char		*raw_text;
	int			line_count;
	char		**split_text;
	t_dict_data	*dictionary;
	char		*file;

	if (*filename == '\0')
		file = "numbers.dict";
	else
		file = filename;
	if (ft_get_file(file) < 0)
		return (-1);
	raw_text = malloc(sizeof(char) * (ft_get_file(file) + 1));
	ft_read(file, raw_text);
	split_text = ft_split(raw_text, '\n');
	free(raw_text);
	line_count = ft_line_count(split_text);
	dictionary = ft_add_struct(split_text, line_count);
	ft_stack_data(dictionary, line_count);
	free(dictionary);
	return (0);
}
