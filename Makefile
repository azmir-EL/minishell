GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

C = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src

SRC_B = $(SRC_DIR)/builtins
UTILS_DIR = utils
LIBFT_DIR = libft

NAME = minishell
LIBS = -lreadline
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = \
	$(SRC_DIR)/main.c \
	$(UTILS_DIR)/utils1.c \
	$(UTILS_DIR)/utils2.c \
	$(SRC_DIR)/executor.c \
	$(SRC_B)/echo.c \
	$(SRC_B)/cd.c \
	$(SRC_B)/exit.c\
	$(SRC_B)/env.c\
	$(SRC_B)/pwd.c\
	$(SRC_B)/unset.c\
	$(SRC_B)/export.c\

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(LIBS) -o $(NAME)
	@echo "$(GREEN)Build successful! $(NAME) is ready.$(RESET)"

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)Cleaned everything.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
