EXECUTABLE = push_swap
SRC = $(wildcard *.c)
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR)/includes

# Ajout de la variable ARGS pour spécifier les arguments du programme
ARGS = arg1 arg2 arg3

all: $(OBJ_DIR) $(EXECUTABLE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJ) $(LIBFT)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXECUTABLE)

re: fclean all

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

.PHONY: all clean fclean re run
