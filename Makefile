NAME = get_next_line.out

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = *.c

all: $(NAME)

$(NAME):: clean
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} -D BUFFER_SIZE=1000000 && ./${NAME} | cat -e

clean:
	-rm *.out

fclean:
	-rm *.out

debug:
	gdb ${NAME}

valgrind:
	valgrind ./${NAME} --leak-check=full

.PHONY: all clean debug valgrind
