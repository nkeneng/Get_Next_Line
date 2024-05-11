NAME = get_next_line.out

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = *.c

all: $(NAME)

$(NAME):: clean
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} -D BUFFER_SIZE=5 && ./${NAME} | cat -e

clean:
	-rm *.out

debug:
	gdb ${NAME}
.PHONY: all
