/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_strc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:51:11 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 17:12:20 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_STRC_H
# define FILE_STRC_H

# include <fcntl.h>

int		ft_open_file(char *filename);
void	ft_read_file(char *filename, char *raw_txt);
char	**create_map(char *filename);
#endif
