/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:11:48 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/31 01:32:55 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *dest)
{
	int len;

	len = 0;
	while (dest[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int d_len;
	int s_len;
	int i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	while (src[i])
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + s_len] = '\0';
	return (dest);
}
