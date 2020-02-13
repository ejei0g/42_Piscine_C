.PHONY: all clean fclean re

SRCS	= main.c ft_input_key_value.c ft_dic_open.c ft_split.c check_raw_text.c ft_get_words.c ft_print_words.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

HEADER	= header.h

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all
