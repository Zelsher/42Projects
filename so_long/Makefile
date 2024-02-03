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
	  so_long_hook.c \
	  so_long_map.c \
	  so_long_checker.c \
	  so_long_parsing.c \
	  so_long_moove.c \
	  so_long_init.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
EXEC = so_long

RM = rm -f

all: libft $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) $^ $(LIB) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC_DIR) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $@

libft:
	@make -C Libft

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C Libft clean

fclean: clean
	@$(RM) $(EXEC)
	@$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re libft
