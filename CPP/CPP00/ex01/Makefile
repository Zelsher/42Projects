NAME			= phonebook

SRC_DIR			= 
OBJ_DIR			= 

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98
RM				= rm -f

SRC				= $(SRC_DIR)PhoneBook.cpp
HDR				= $(SRC_DIR)PhoneBook.hpp # Ajoutez tous vos fichiers .hpp ici

OBJ 			= $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC))

all: 			$(NAME)

$(NAME): 		$(OBJ)
				@echo "Compiling [$(SRC)]"
				@$(CC) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(HDR)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)

fclean: 		clean
				@echo "Deleting [$(NAME)]"
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re
