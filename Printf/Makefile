# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 18:05:58 by eboumaza          #+#    #+#              #
#    Updated: 2023/08/29 18:05:58 by eboumaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = ft_printf.h
FILES = ft_printf.c \
        ft_print_cspdi.c \
        ft_print_uxX.c \
        ft_putnbr.c \
        ft_int_to_hexa.c \
        ft_putptr.c \
        ft_putnbr_unsigned_int.c

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(FILES:.c=.o))

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re