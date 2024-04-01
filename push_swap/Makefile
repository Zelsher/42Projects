NAME			= push_swap

INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/
LIBFT			= Libft/libft.a

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -I $(INC)
RM				= rm -f

SRC				=	$(SRC_DIR)stack_moover.c \
					$(SRC_DIR)stack_util.c \
					$(SRC_DIR)ft_radix.c \
					$(SRC_DIR)ft_resolver.c \
					$(SRC_DIR)ft_easy_solver.c \
					$(SRC_DIR)push_swap.c \
					$(SRC_DIR)main.c 

OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: 			$(NAME)

bonus:			$(NAME)

run:
				n./checker_linux $(ARG)

$(NAME): 		$(OBJ) $(LIBFT) $(INC)
				@echo $(G)Compiling [$(SRC)]$(X) 
				@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
				@echo $(G)Compiling [$(NAME)]$(X) 

$(LIBFT)	:
				@echo $(G)Compiling [LIBFT]$(X) 
				@make -s -C Libft

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@echo $(G)delete [$(OBJ)]$(X) 
				@$(RM) -r $(OBJ_DIR)
				@make clean -s -C Libft

fclean: 		clean
				@echo $(G)delete [$(NAME)]$(X)	
				@$(RM) $(NAME)
				@echo $(G)delete [LIBFT]$(X)
				@make fclean -s -C Libft

re: 			fclean all

.PHONY: 		all clean fclean re

#432 95 4 12 3456 9546 5 32478 32 4509 87 38 21 3 2113 73 324 9285 3719 234 6 1 92 96525 16 19 37 7 44 65 43 61 8845 4555 55 2 1102 405