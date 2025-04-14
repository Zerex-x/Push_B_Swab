SRCS	= things.c things_two.c moving_one.c moving_two.c parsing.c push_swap.c large_numbers.c sorting.c ft_atoi.c ft_strjoin.c ft_split.c utils.c utils_two.c\

NAME = push_swap

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

doth = push_swap.h

all: $(NAME)

%.o: %.c ${doth}
	cc ${FLAGS} -c $< -o $@

$(NAME) : $(OBJS)
	cc $^ ${FLAGS} -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
