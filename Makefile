# 42 Pipex - Mandatory Part

NAME    := pipex
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rcs
RM      := rm -f

SRCS    := src/main.c src/exec.c src/path.c src/split.c src/utils.c src/error.c
OBJS    := $(SRCS:.c=.o)
INCS    := -I include

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

src/%.o: src/%.c include/pipex.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re