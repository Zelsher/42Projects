NAME			= sed_for_losers

INC				=
SRC_DIR			=
OBJ_DIR			= obj/

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98 -I $(INC)
RM				= rm -f

SRC				=	$(SRC_DIR)main.cpp \
					$(SRC_DIR)file.cpp \


OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

all: 			$(NAME)

bonus:			$(NAME)

$(NAME): 		$(OBJ) $(INC)
				@echo $(G)Compiling [$(SRC)]$(X) 
				@$(CC) -o $(NAME) $(OBJ)
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