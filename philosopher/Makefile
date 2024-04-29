NAME			= philosopher

INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/
LIBFT			= Libft/libft.a

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3 -I $(INC)
RM				= rm -f

SRC				=	$(SRC_DIR)main.c \
					$(SRC_DIR)philosopher.c \
					$(SRC_DIR)philosopher_utils.c \

OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: 			$(NAME)

bonus:			$(NAME)

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