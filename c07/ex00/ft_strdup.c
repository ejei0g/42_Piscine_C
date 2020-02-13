/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 00:33:59 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/10 17:38:13 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*rtn_str;
	int		i;

	i = 0;
	rtn_str = (char *)malloc((sizeof(char) * str_len(src)) + 1);
	while (i < str_len(src))
	{
		rtn_str[i] = src[i];
		i++;
	}
	rtn_str[i] = '\0';
	return (rtn_str);
}
