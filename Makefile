NAME = push_swap
B_NAME = checker

SRCS = SRC/main.c \
		SRC/func00.c \
		SRC/func01.c \
		SRC/func02.c \
		SRC/linked_list.c \
		SRC/operation.c \
		SRC/sort.c \
		SRC/sorting_util.c \
		SRC/sort_util_2.c \
		SRC/func04.c \

SRCS_BONUS = get_next_line/get_next_line.c \
			 get_next_line/get_next_line_utils.c \
			 bonus/main.c \
			 bonus/check_av.c \
			 bonus/func.c \
			 bonus/func2b.c \
			 bonus/instruction.c \
			 bonus/ln_list.c \
			 bonus/instruction02.c \

OBJS = $(SRCS:.c=.o)

B_OBJS = $(SRCS_BONUS:.c=.o)

CC = cc -g

CFLAGS = -Werror -Wall -Wextra

RM = rm -f

all:    $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(B_NAME):$(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS)  -o $(B_NAME) 

bonus: $(B_NAME)

clean:
		$(RM) $(OBJS) $(B_OBJS)

fclean:    clean
	$(RM) $(NAME) $(B_NAME)

re:    fclean all

.PHONY: all clean fclean re