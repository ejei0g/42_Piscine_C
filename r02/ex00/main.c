/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:47:36 by sohpark           #+#    #+#             */
/*   Updated: 2020/02/09 23:18:42 by sohpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	[OVERALL PROCEDURE]
**	1.	We retrieve the raw text from "numbers.dict" file.
**		We tidy up the data so that they can be stored as structure
**		which has two members: key and value.
**	2.	We create two arrays: numbers and hundreds.
**		We check the key in the structure, and change the key to integer.
**		This integer works as the index for the two arrays.
**		ex) if the key is "10", we store the value of that structure
**		in that array's index.
**	3.	When we receive the string input(which is the number),
**		we go through following procedure.
**		a) Get the number of words we need to print.
**		b) Using that number, we create string array.
**		c) In that array,
**		   we assign strings that need to be printed in reverse order.
**		   This is achieved by cutting the number string into three sections
**		   and increasing the depth everytime we enter new recursive function.
**	4.	Print the strings stored in string array(output) in reverse order.
**
**
**	[NAMING CONVENTION]
**	-	Snake case
**	-	Global variables start with "g_"
*/

/*
**	[DESCRIPTION]
**	This is the main function! :) YAY~
**	In the main functions, we check the argument's validity,
**	and use the "numbers_to_words" function to conver the number to texts
**	and print them.
*/

int		is_input_valid(char *str)
{
	if (is_all_numeric(str) == 0)
		return (-1);
	else if (is_all_numeric(str) && ft_strlen(str) > 1)
	{
		if (str[0] == '0')
			return (-1);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	char *input;
	char *filename;

	filename = "";
	if (argc == 2 || argc == 3)
	{
		if (is_input_valid(argv[argc - 1]) == -1)
		{
			ft_putstr("Input Invalid. Please type proper number.\n");
			return (0);
		}
		else
			input = argv[argc - 1];
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
		filename = argv[1];
	number_to_words(input, filename);
	return (0);
}
