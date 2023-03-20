NAME		= libftprintf.a
INCLUDES	= ./include
LIBFT		= ../libft/libft.a
SRC_DIR		= sources
OBJ_DIR		= objects
SRC_FILES	= ft_printf.c ft_put.c ft_uitoa.c ft_uitoa_hex.c
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar -rs
OBJ_FILES	= $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	$(AR) $(NAME) $(OBJ_FILES) 

#$(LIBFT):
#	make bonus -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@	

clean:
	$(RM)r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
			
re: fclean all