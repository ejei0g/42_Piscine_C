/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:24:13 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/24 00:45:57 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int a;

	a = '1';
	while (a <= '9')
	{
		write(1, &a, 1);
		a++;
	}
}

int		main(void)
{
	ft_print_numbers();
	return (0);
}
