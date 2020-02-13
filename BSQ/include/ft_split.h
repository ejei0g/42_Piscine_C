/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:51:26 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 17:13:28 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

# include <unistd.h>

int		is_charset(char c, char *charset);
int		count_strs(char *str, char *charset);
void	put_str(char **strs, char *str, char *charset);
void	alloc_str(char **strs, char *str, char *charset);
char	**ft_split(char *str, char *charset);

#endif
