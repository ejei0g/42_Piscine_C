/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeylee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:36:16 by jaeylee           #+#    #+#             */
/*   Updated: 2020/02/05 16:53:09 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_adr(char **str1, char **str2)
{
	char *tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

int		ft_asc_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] > str2[i])
			return (1);
		else
			i++;
	}
	return (0);
}

void	ft_sort_argv(char **argv, int argc)
{
	int i;

	i = 1;
	if (argc == 1)
		return ;
	while (i < argc - 1)
	{
		if (ft_asc_strcmp(argv[i], argv[i + 1]))
			ft_swap_adr(&argv[i], &argv[i + 1]);
		i++;
	}
	ft_sort_argv(argv, argc - 1);
}

void	ft_printf(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (argv[i][0])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	ft_sort_argv(argv, argc);
	ft_printf(argv, argc);
	return (0);
}
