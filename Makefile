NAME = minishell

SRCS =							\
		srcs/main.c				\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS =  -Wall -Wextra -Werror -I inc -g3

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "❄️ Operation Helsinki Completed ❄️"
	
all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma