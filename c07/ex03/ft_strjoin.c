/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:42:18 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/12 03:47:32 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_total_len(int size, char **strs, char *sep)
{
	int total_len;
	int i;

	total_len = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	return (total_len);
}

void	str_concen(int size, char **strs, char *sep, char *str)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			*str++ = strs[i][j];
			j++;
		}
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
			{
				*str++ = sep[j];
				j++;
			}
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		str_len;
	int		i;

	i = 0;
	if (size == 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		return (str);
	}
	str_len = ft_total_len(size, strs, sep);
	if (!(str = (char *)malloc(sizeof(char) * str_len + 1)))
		return (0);
	str_concen(size, strs, sep, str);
	str[str_len] = '\0';
	return (str);
}
