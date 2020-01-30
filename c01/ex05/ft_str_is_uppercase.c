/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 23:17:57 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/27 23:44:44 by jaeylee          ###   ########.fr       */
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

int		ft_str_is_uppercase(char *str)
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
		if (65 <= str[i] && str[i] <= 90)
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
