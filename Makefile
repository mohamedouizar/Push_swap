NAME = push_swap

SRCS = SRC/main.c \
		SRC/func00.c \
		SRC/func01.c \
		SRC/func02.c \
		SRC/linked_list.c \
		SRC/operation.c \
		SRC/sort.c \
		SRC/sorting_util.c \
		SRC/sort_util_2.c \

OBJS = $(SRCS:.c=.o)

CC = cc -g

CFLAGS = -Werror -Wall -Wextra

RM = rm -f

all:    $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS) 

fclean:    clean
	$(RM) $(NAME)

re:    fclean all

.PHONY: all clean fclean re