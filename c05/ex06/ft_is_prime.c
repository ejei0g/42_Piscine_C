/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:05:18 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/05 15:56:55 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int num;

	if (nb < 2)
		return (0);
	num = 2;
	while (num <= nb / 2)
	{
		if (nb % num == 0)
			return (0);
		num++;
	}
	return (1);
}
