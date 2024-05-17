NAME = get_next_line.out

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = *.c

all: $(NAME)

$(NAME):: clean
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} -D BUFFER_SIZE=42 && ./${NAME} | cat -e

clean:
	-rm *.out

fclean:
	-rm *.out

debug:
	gdb ${NAME}

valgrind:
	valgrind --leak-check=full ./${NAME}

sanitize:
	#${CC} ${SRCS} ASAN_SYMBOLIZER_PATH=/usr/bin/llvm-symbolizer -fsanitize=address -o sanitize.out -D BUFFER_SIZE=10000000 && ./sanitize.out
	${CC} ${SRCS} -fsanitize=address -o sanitize.out -D BUFFER_SIZE=10000000 && ./sanitize.out

.PHONY: all clean debug valgrind
