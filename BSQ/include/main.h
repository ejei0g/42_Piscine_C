/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 03:51:58 by dopark            #+#    #+#             */
/*   Updated: 2020/02/12 15:56:13 by jaeylee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include "main.h"

int		is_enter(char *str);
int		chk_map_len(char *str);
int		set_map(void);
void	set_maps(char *argv, int argc, int cnt);
#endif
