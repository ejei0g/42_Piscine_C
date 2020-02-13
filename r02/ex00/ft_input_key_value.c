/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_key_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:24:59 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/09 23:18:00 by sohpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	[DESCRIPTION]
**	This function checks every line in the file's text
**	and divide them into two sections.
** 	The divider is ':'.
**	The part before ':' will be the key, and the part after ':'
**	will be the value.
*/

void	ft_input_key_value(char *key, char *value, char *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (src[i] != ':')
	{
		if (47 < src[i] && src[i] < 58)
			key[i] = src[i];
		i++;
	}
	i++;
	while (src[i] == ' ')
		i++;
	while (src[i])
	{
		if (31 < src[i] && src[i] < 127)
		{
			value[j] = src[i];
			j++;
		}
		i++;
	}
}
