/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:23:46 by sohpark           #+#    #+#             */
/*   Updated: 2020/02/09 23:19:22 by sohpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	[DESCRIPTION]
**	When we receive the string input(which is the number),
**	we go through the following procedure.
**		a) Get the number of the words we need to print.
**		b) Using that number, we create string array.
**		c) In that array,
**		   we assign strings that need to be printed in reverse order.
**		   This is achieved by cutting the number string into three sections
**		   and increasing the depth everytime we enter new recursive function.
**	Starting from the end of the input string,
**	we always check three digits together.
**	From each section, we can always get three digits' word expression.
**	By using "depth", we can also retrieve which hundreds digits we are on.
**	(for instance, thousand, million, billion, so on and so forth)
*/

int		get_count(t_three *section, int depth, int *w_count)
{
	if (depth >= 1 &&
			(section->hundred != 0 || section->ten != 0 || section->one != 0))
		(*w_count)++;
	if (section->one != 0)
		(*w_count)++;
	if (section->ten != 0)
	{
		if (section->ten == 10 && section->one != 0)
			(*w_count) = (*w_count);
		else if (section->ten == 10 && section->one == 0)
			(*w_count)++;
		else
			(*w_count)++;
	}
	if (section->hundred != 0)
		(*w_count) = (*w_count) + 2;
	free(section);
	return (*w_count);
}

void	count_words(int depth, int len, char *input, int *w_count)
{
	int		ones_i;
	t_three *section;

	ones_i = len - 1 - depth * 3;
	section = malloc(sizeof(t_three));
	if (ones_i - 2 >= 0)
		section->hundred = input[ones_i - 2] - '0';
	else
		section->hundred = 0;
	if (ones_i - 1 >= 0)
		section->ten = (input[ones_i - 1] - '0') * 10;
	else
		section->ten = 0;
	section->one = input[ones_i] - '0';
	*w_count = get_count(section, depth, w_count);
	if (ones_i <= 2)
		return ;
	else
		count_words(depth + 1, len, input, w_count);
	return ;
}

int		assign_section(t_three *section, int depth, char **output, int w_count)
{
	if (depth >= 1 &&
			(section->hundred != 0 || section->ten != 0 || section->one != 0))
		output[w_count++] = g_hundreds[depth];
	if (section->one != 0)
		output[w_count++] = g_numbers[section->one];
	if (section->ten != 0)
	{
		if (section->ten == 10 && section->one != 0)
			output[w_count - 1] = g_numbers[section->ten + section->one];
		else if (section->ten == 10 && section->one == 0)
			output[w_count++] = g_numbers[10];
		else
			output[w_count++] = g_numbers[section->ten];
	}
	if (section->hundred != 0)
	{
		output[w_count++] = g_hundreds[0];
		output[w_count++] = g_numbers[section->hundred];
	}
	free(section);
	return (w_count);
}

void	get_section(int depth, char *input, int w_count, char **output)
{
	int		ones_i;
	t_three *section;

	if (ft_strlen(input) <= depth * 3)
		return ;
	ones_i = ft_strlen(input) - 1 - depth * 3;
	section = malloc(sizeof(t_three));
	if (ones_i - 2 >= 0)
		section->hundred = input[ones_i - 2] - '0';
	else
		section->hundred = 0;
	if (ones_i - 1 >= 0)
		section->ten = (input[ones_i - 1] - '0') * 10;
	else
		section->ten = 0;
	section->one = input[ones_i] - '0';
	w_count = assign_section(section, depth, output, w_count);
	get_section(depth + 1, input, w_count, output);
}

void	number_to_words(char *input, char *filename)
{
	int		input_len;
	int		w_count;
	char	**output;
	int		error;

	w_count = 0;
	input_len = ft_strlen(input);
	count_words(0, input_len, input, &w_count);
	output = malloc(sizeof(char *) * (w_count + 1));
	output[w_count] = 0;
	if ((error = create_dic(filename)) < 0)
		return ;
	if (ft_strlen(input) == 1 && input[0] == '0')
	{
		ft_putstr(g_numbers[0]);
		return ;
	}
	get_section(0, input, 0, output);
	print_output(output, w_count);
	free(output);
}
