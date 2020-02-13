/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:41:42 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 17:14:38 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_split.h"
#include "make_square.h"

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		count_strs(char *str, char *charset)
{
	int word_counts;
	int i;

	i = 0;
	word_counts = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
			word_counts++;
		while (str[i] && !is_charset(str[i], charset))
			i++;
		while (str[i] && is_charset(str[i], charset))
			i++;
	}
	return (word_counts);
}

void	put_str(char **strs, char *str, char *charset)
{
	int word_count;
	int str_len;
	int i;

	i = 0;
	word_count = 0;
	str_len = 0;
	while (str[i] && strs[word_count] != 0)
	{
		if (!is_charset(str[i], charset))
		{
			strs[word_count][str_len] = str[i];
			str_len++;
		}
		if (!is_charset(str[i], charset)
				&& (is_charset(str[i + 1], charset) || str[i + 1] == 0))
		{
			word_count++;
			str_len = 0;
		}
		i++;
	}
}

void	alloc_str(char **strs, char *str, char *charset)
{
	int	word_counts;
	int str_len;
	int i;

	i = 0;
	word_counts = 0;
	str_len = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			str_len++;
		}
		if (!is_charset(str[i], charset)
				&& (is_charset(str[i + 1], charset) || str[i + 1] == 0))
		{
			strs[word_counts] = malloc(sizeof(char) * str_len + 1);
			strs[word_counts][str_len] = 0;
			str_len = 0;
			word_counts++;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		word_counts;

	word_counts = count_strs(str, charset);
	strs = malloc(sizeof(char *) * word_counts + 1);
	if (strs == 0)
		return (strs);
	if (word_counts != 0)
	{
		alloc_str(strs, str, charset);
		put_str(strs, str, charset);
	}
	strs[word_counts] = 0;
	return (strs);
}
