/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:46:05 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/28 00:06:39 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

int		ft_str_is_printable(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (ft_strlen(str) == 0)
	{
		ret = 1;
		return (ret);
	}
	while (str[i] != '\0')
	{
		if (31 < str[i] && str[i] < 127)
			ret = 1;
		else
		{
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}
