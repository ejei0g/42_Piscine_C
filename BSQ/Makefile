# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dopark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 20:06:23 by dopark            #+#    #+#              #
#    Updated: 2020/02/12 20:23:34 by dopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = error_test.c file_strc.c ft_split.c ft_string.c init.c main.c make_square.c ft_print.c
HEADERS = error_test.h file_strc.h ft_split.h ft_string.h init.h main.h make_square.h ft_print.h
SRCS_PATH = srcs/
INCLUDES_PATH = include/
SRCS = $(addprefix $(SRCS_PATH), $(SOURCES))
INCLUDES = $(addprefix $(INCLUDES_PATH), $(HEADERS))
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = bsq

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	$(CC) -c $(CFLAGS) $(SRCS) -I$(INCLUDES_PATH)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all