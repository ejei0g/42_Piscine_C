/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:26:17 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/31 02:50:19 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *dest)
{
	unsigned int len;

	len = 0;
	while (dest[len])
		len++;
	return (len);
}

char				*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int d_len;
	unsigned int s_len;
	unsigned int i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	while (i < nb && src[i])
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (dest);
}
