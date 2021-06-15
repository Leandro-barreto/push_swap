NAME = push_swap
LIB = push_swap.a

SRCS = src/push_swap.c \
	   src/cmd.c \
	   src/final_check.c\
	   src/sort.c \
	   src/sort_onehundred.c \
	   src/sort_fivehundred.c \
	   src/stats_moves.c
SRCCHECK = src/checker.c src/cmd.c src/final_check.c

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
UTILS = src/libft/libft.a 
OBCHECK = $(SRCCHECK:.s=.o)
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@cd src/libft/ && make
	@ar rc $(LIB) $(OBJS)
	@clang $(CFLAGS) $(OBJS) $(UTILS) -o $(NAME)
	
checker: $(OBCHECK) $(NAME)
	clang -o meuchecker $(OBCHECK) src/libft/libft.a

%.o: %.c
	clang $(CFLAGS) $<

clean:
	rm -f src/*.o
	rm -f src/checker/*.o
	cd src/libft/ && make clean

fclean: clean
	rm -f $(NAME)
	rm -f checker
	cd src/libft/ && rm -f libft.a

re: fclean all

.PHONY: all clean flcean re color
