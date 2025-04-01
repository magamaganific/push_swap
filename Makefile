NAME = push_swap
LIB_DIR = libft
PTF_DIR = libft/ft_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs
RM = rm -f

SRCS = main.c utils.c org_frees.c\
		org_inputprep.c org_moves.c\
		org_push-swap.c org_rotations.c\
		org_simplesorts.c ft_atol.c ksort.c\
		index_utils.c
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(LIB_DIR)/*.o
PTR_OBJS = $(PTF_DIR)/*.o

BP = \033[35m
NRM = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	$(CC) $(OBJS) $(LIB_OBJS) $(PTR_OBJS) -o  $(NAME)
	@echo "$(BP)\n-----push_swap created properly---\n$(NRM)"

$(LIB_OBJS):
	@make -C $(LIB_DIR)

norminette:
	@norminette | grep "Error"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS) $(BOBJS)
	@make clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus