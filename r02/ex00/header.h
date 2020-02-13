/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:35:06 by sohpark           #+#    #+#             */
/*   Updated: 2020/02/09 22:47:21 by sohpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char			*g_numbers[999];
char			*g_hundreds[126];

typedef struct	s_three_digits
{
	int			hundred;
	int			ten;
	int			one;
}				t_three;

typedef struct	s_dict_data
{
	char		key[255];
	char		value[255];
}				t_dict_data;

int				is_separator(char c, char sep);
int				ft_get_file(char *filename);
void			ft_read(char *filename, char *dic);
t_dict_data		*ft_add_struct(char **dictionary, int line_count);
int				create_dic(char *filename);
int				is_all_numeric(char *str);
int				count_zero(char *str);
int				is_all_zero(char *str);
int				ft_atoi(char *str);
void			ft_stack_data(t_dict_data *dic, int line_count);
int				is_separator(char c, char sep);
int				get_words_nb(char *str, char sep);
int				write_str(char **arr, char *str, char sep);
char			**ft_split(char *str, char sep);
void			ft_input_key_value(char *key, char *value, char *src);
void			number_to_words(char *input, char *filename);
int				is_input_valid(char *str);
void			print_output(char **strs, int words);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				get_count(t_three *section, int depth, int *count);
void			count_words(int depth, int len, char *input, int *count);
void			get_section(int depth, char *input, int count, char **output);

#endif
