NAME := libftprintf.a
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

SRCS := ft_printf.c ft_putter.c
OBJS := $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	-$(RM) $(OBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
