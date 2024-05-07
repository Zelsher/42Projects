NAME			= philo

INC				= inc/
SRC_DIR			= src/
OBJ_DIR			= obj/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=thread -I $(INC)
RM				= rm -f

SRC				=	$(SRC_DIR)main.c \
					$(SRC_DIR)philosopher.c \
					$(SRC_DIR)death_checker.c \
					$(SRC_DIR)wait.c \
					$(SRC_DIR)philo_utils.c \
					$(SRC_DIR)extern_utils.c \

OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: 			$(NAME)

bonus:			$(NAME)

$(NAME): 		$(OBJ) $(INC)
				@echo $(G)Compiling [$(SRC)]$(X) 
				@$(CC) -o $(NAME) $(OBJ) -fsanitize=thread
				@echo $(G)Compiling [$(NAME)]$(X) 


$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@echo $(G)delete [$(OBJ)]$(X) 
				@$(RM) -r $(OBJ_DIR)

fclean: 		clean
				@echo $(G)delete [$(NAME)]$(X)	
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re