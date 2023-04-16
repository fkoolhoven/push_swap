NAME 			= 	push_swap
LIBFT			= 	$(addprefix $(LIBFT_DIR)/,libft.a)
LIBFT_DIR		= 	includes/libft
FT_PRINTF		= 	$(addprefix $(FT_PRINTF_DIR)/,libftprintf.a)
FT_PRINTF_DIR	= 	includes/ft_printf
LIBS			= 	$(LIBFT) $(FT_PRINTF)
CC 				= 	cc
CFLAGS 			= 	-Wall -Wextra -Werror
RM				= 	rm -f
OBJ_DIR 		= 	objects
OBJ_FILES		= 	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
SRC_DIR 		= 	sources
SRC_FILES 		= 	main.c \
					validate_input.c \
					initialize_stack.c \
					stack_utils.c \
					patience_lists.c \
					seperate_stacks.c \
					merge_stacks.c \
					merge_options.c \
					merge_distance.c \
					merge_checker.c \
					merge_optimal.c \
					merge_execute.c \
					operation_push.c \
					operation_reverse_rotate.c \
					operation_rotate.c \
					operation_swap.c \
					final_rotate.c

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

.PHONY: all, clean, fclean, re