#	Compiler and Flags
CC = CC
CFLAG = -Wall -Wextra -Werror


#	Push Swap
NAME = push_swap
LIBC = ar rcs

# add all function in here
SRCS =  add_to_stack.c algorithm.c algorithm_utils.c \
		check_stack.c create_stack.c error_check.c \
		main.c push_operators.c reverse_rotate.c \
		rotate_operators.c setting_chunks.c swap_operators.c \
		revise_split.c
		
#	#	#	#
OBJS = ${SRCS:.c=.o}


#	include Directory
INC_DIR = .
RM = rm -f

#	Rules
all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAG} -I${INC_DIR} ${OBJS} -o ${NAME}

# ${LIBFT_LIB}:
# 	@make -C ${LIBFT_DIR}

%.o: %.c
	${CC} ${CFLAG} -c $< -o $@

clean:
	${RM} ${OBJS}


fclean: clean
	${RM} ${NAME}


re: flean all

.PHONY: all clean fclean re