NAME 			= push_swap
LIBFT			= $(addprefix $(LIBFT_DIR)/,libft.a)
LIBFT_DIR		= includes/libft
FT_PRINTF		= $(addprefix $(FT_PRINTF_DIR)/,libftprintf.a)
FT_PRINTF_DIR	= includes/ft_printf
LIBS			= $(LIBFT) $(FT_PRINTF)
OBJ_FILES		= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
OBJ_DIR 		= objects
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

# ifdef BONUS
# SRC_FILES	= 
# SRC_DIR 	= 
# else
SRC_FILES 	= main.c stack.c swap.c push.c rotate.c reverse_rotate.c
SRC_DIR 	= sources
# endif

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(OBJ_FILES) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS):
	make bonus -C $(LIBFT_DIR)
	make -C $(FT_PRINTF_DIR)

clean:
	$(RM)r $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

bonus:
	$(MAKE) BONUS=1 all

.PHONY: all, clean, fclean, re