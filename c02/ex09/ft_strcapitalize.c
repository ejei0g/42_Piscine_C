/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:03:55 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/28 12:33:14 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_chkasc(char asc)
{
	int ret;

	ret = 0;
	if (47 < asc && asc < 58)
		ret = 1;
	else if (64 < asc && asc < 91)
		ret = 2;
	else if (96 < asc && asc < 123)
		ret = 3;
	else
		ret = 0;
	return (ret);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (ft_chkasc(str[0]) == 3)
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (ft_chkasc(str[i]) == 0 && ft_chkasc(str[i + 1]) == 3)
			str[i + 1] -= 32;
		else if (ft_chkasc(str[i]) == 2 && ft_chkasc(str[i + 1]) == 2)
			str[i + 1] += 32;
		else if (ft_chkasc(str[i]) == 3 && ft_chkasc(str[i + 1]) == 2)
			str[i + 1] += 32;
		i++;
	}
	return (str);
}
