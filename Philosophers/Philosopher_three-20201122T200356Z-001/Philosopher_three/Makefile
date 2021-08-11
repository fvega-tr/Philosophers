EOC = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m
ORANGE = \033[48:5:208m

NAME = philo_three

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = philosopher_three.h

RM = rm -rf

SRCS =	main.c check_error.c init.c\
		create_forks.c forks_and_eat.c\
		clear.c message.c semaphore.c\
		several.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	@echo "$(BOLD)$(ORANGE)Make$(EOC): $(NAME)"


$(NAME): $(OBJS) $(HEADER)
			@$(CC) $(CFLAGS) $(OBJS) -o $@ 

clean:
	@echo "$(BOLD)$(YELLOW)Remove......... |$(GREEN)| done$(EOC)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(BOLD)$(YELLOW)Remove all..... |$(GREEN)| done$(EOC)"
	@$(RM) $(NAME)

.PHONY: all clean fclean re