RESET   = \033[0m
WHITE   = \033[1;37m
NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread
RM = rm -rf

SRCS =  main.c\
		utils.c\
		mutex.c\


OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "(WHITE)  _____  _     _ _                       _                   $(RESET)"
	echo "(WHITE) |  __ \| |   (_) |                     | |                  $(RESET)"
	echo "(WHITE) | |__) | |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ ___ $(RESET)"
	echo "(WHITE) |  ___/| '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __|$(RESET)"
	echo "(WHITE) | |    | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \$(RESET)"
	echo "(WHITE) |_|    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/$(RESET)"
	echo "(WHITE)                                  | |                        $(RESET)"
	echo "(WHITE)                                  |_|                        $(RESET)"
	echo "$(GREEN)Philosophers executable is ready!$(RESET)"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all