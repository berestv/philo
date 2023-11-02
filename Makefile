RESET   = \033[0m
WHITE   = \033[1;37m
GREEN	= \033[1;32m

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g
RM = rm -rf

SRCS =  main.c\
		utils.c\
		mutex.c\
		status.c\
		errors.c\
		functions.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	clear
	echo "  _____  _       _                       _                    "
	echo " |  __ \| |   (_) |                     | |                   "
	echo " | |__) | |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ ___  "
	echo " |  ___/| |_ \| | |/ _ \/ __|/ _ \| |_ \| |_ \ / _ \ |__/ __| "
	echo " | |    | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \ "
	echo " |_|    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/ "
	echo "                                  | |                         "
	echo "                                  |_|                         "
	echo "$(GREEN) Philosophers executable is ready! $(RESET)"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.SILENT:
