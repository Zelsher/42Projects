# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 18:06:01 by eboumaza          #+#    #+#              #
#    Updated: 2023/08/29 18:06:01 by eboumaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx/mlx_Linux -Lminilibx/mlx -L/usr/lib -Imlx_linux -lXext -lX11 
LIB = Libft/libft.a minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
OBJ_DIR = obj
SRC = so_long.c \
      main.c \
      so_long_color.c \
	  so_long_frame.c \
	  so_long_hook.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
EXEC = so_long

RM = rm -f

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ $(LIB) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_DIR) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
