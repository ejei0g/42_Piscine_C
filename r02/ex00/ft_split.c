/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 03:53:04 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/09 22:24:24 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_separator(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int		get_words_nb(char *str, char sep)
{
	int result;

	result = 0;
	while (*str)
	{
		if (!is_separator(*str, sep))
			result++;
		while (*str && !is_separator(*str, sep))
			str++;
		while (*str && is_separator(*str, sep))
			str++;
	}
	return (result);
}

int		add_str_to_array(char **strs, char *str, int total_words, int length)
{
	int	i;

	if (length != 0)
	{
		if (!(strs[total_words - 1] = malloc(sizeof(char) * length + 1)))
			return (0);
		strs[total_words - 1][length] = '\0';
	}
	i = 0;
	while (i < length)
	{
		strs[total_words - 1][i] = str[i];
		i++;
	}
	return (1);
}

int		write_str(char **strs, char *str, char sep)
{
	int total_words;
	int length;

	total_words = 0;
	while (*str)
	{
		length = 0;
		if (!is_separator(*str, sep))
		{
			total_words++;
		}
		while (str[length] && !is_separator(str[length], sep))
			length++;
		if (!add_str_to_array(strs, str, total_words, length))
			return (0);
		str = str + length;
		while (*str && is_separator(*str, sep))
			str++;
	}
	return (1);
}

char	**ft_split(char *str, char sep)
{
	int		total_words;
	char	**strs;

	total_words = get_words_nb(str, sep);
	if (!(strs = (char **)malloc(sizeof(char *) * total_words + 1)))
		return (0);
	strs[total_words] = 0;
	if (!write_str(strs, str, sep))
		return (0);
	return (strs);
}
