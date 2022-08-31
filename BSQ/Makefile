NAME	= bsq
SRCS	= calc_max_sqr.c check_map.c clean_array.c find_biggest.c ft_atoi.c fts_symbols.c loop.c main.c print_sol.c process_array.c read_file.c
OBJS	= ${SRCS:.c=.o}
DEL		= stdin.txt
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS} ${DEL}

fclean: clean
	${RM} ${NAME}

re: fclean all
