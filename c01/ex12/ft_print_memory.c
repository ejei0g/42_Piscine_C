/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:05:27 by jaeylee           #+#    #+#             */
/*   Updated: 2020/01/30 15:14:13 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int n)
{
	int temp;

	if (n < 10)
	{
		temp = n + 48;
		write(1, &temp, 1);
	}
	else
	{
		temp = n + 87;
		write(1, &temp, 1);
	}
}

void	ft_print_add(int n)
{
	if (n == 0)
		return ;
	ft_print_add(n / 16);
	ft_write(n % 16);
}

void	print_hexadd(unsigned long add)
{
	unsigned char	address[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		address[i] = 0;
		i++;
	}
	i = 15;
	while (i > 0)
	{
		address[i] = add % 16;
		add = add / 16;
		i--;
	}
	while (i < 16)
	{
		ft_write(address[i]);
		i++;
	}
}

void	print_line(unsigned char *add)
{
	int i;

	print_hexadd((unsigned long)add);
	write(1, ": ", 2);
	i = 0;
	while (i < 16)
	{
		if (add[i] == '\0')
			write(1, "  ", 2);
		ft_print_add((int)add[i]);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	i = 0;
	while (add[i] != '\0' && i < 16)
	{
		if (add[i] < 32 || 126 < add[i])
			write(1, ".", 1);
		else
			write(1, (add + i), 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		print_line(addr);
		addr += 16;
		i += 16;
	}
	return (addr);
}

int		main(void)
{
	char *addr = "Bonjour les aminches...c est fo u.tout.ce qu on peut faire avec...print_memory.. ..lol.lol\xff\xff\xff. asldkf.";
	unsigned int size;
	size = 0;
	while (addr[size])
	{
//		write(1, addr++, 1);
		size++;
	}
	write(1,"\n",1);
	ft_print_memory(addr, size);
	return (0);
}
