/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 00:25:22 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/05 15:58:05 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int num;

	num = nb;
	if (num < 0)
		return (0);
	if (num == 0)
		return (1);
	if (num == 1)
		return (1);
	return (num) * ft_recursive_factorial(num - 1);
}
