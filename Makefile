NAME := minitalk
CFLAGS := -Wall -Wextra -Werror

CLIENT_SRCS := client.c
CLIENT_OBJS := $(CLIENT_SRCS:.c=.o)

SERVER_SRCS := server.c
SERVER_OBJS := $(SERVER_SRCS:.c=.o)

SUBDIRS := libftprintf
LIBS := $(addsuffix /$(notdir $(SUBDIRS)).a,$(SUBDIRS))

$(NAME): client server

all: $(NAME)

clean:
	-$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	-$(RM) client server
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

client: $(CLIENT_OBJS)
	$(MAKE) -C $(SUBDIRS)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) $(LIBS)

server: $(SERVER_OBJS)
	$(MAKE) -C $(SUBDIRS)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) $(LIBS)

.PHONY: all clean fclean re
