EXECUTABLE_PUSH_SWAP = push_swap
EXECUTABLE_CHECKER = checker
SRC_PUSH_SWAP = $(wildcard *.c)
SRC_CHECKER = $(wildcard checker_files/*.c)
OBJ_DIR_PUSH_SWAP = obj
OBJ_DIR_CHECKER = checker_files/obj
OBJ_PUSH_SWAP = $(addprefix $(OBJ_DIR_PUSH_SWAP)/, $(SRC_PUSH_SWAP:.c=.o))
OBJ_CHECKER = $(addprefix $(OBJ_DIR_CHECKER)/, $(notdir $(SRC_CHECKER:.c=.o)))
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR)/includes

ARGS = 312 -3249456 3452 12 9 423 0 -43522 043895 99994 8888885 3 455554 32777 34778 77838549 89845 7327854 8473478 4587 548 38249 9450 9873 97 74 354 7238 2 98 1 6 908 -34254 -43256 -324321 -234969 32006 6004 5642 1121 113 044443 5885 344441 879835 3487754 -243904 -3 -5 43994 -4 -7 239491 88 99 335121 1114111 -1111 -232228 -7843541 4423

all: $(OBJ_DIR_PUSH_SWAP) $(OBJ_DIR_CHECKER) $(EXECUTABLE_PUSH_SWAP) $(EXECUTABLE_CHECKER)

$(OBJ_DIR_PUSH_SWAP):
	mkdir -p $(OBJ_DIR_PUSH_SWAP)

$(OBJ_DIR_CHECKER):
	mkdir -p $(OBJ_DIR_CHECKER)

$(EXECUTABLE_PUSH_SWAP): $(OBJ_PUSH_SWAP)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXECUTABLE_PUSH_SWAP) $(OBJ_PUSH_SWAP) $(LIBFT)

$(EXECUTABLE_CHECKER): $(OBJ_CHECKER) $(OBJ_DIR_PUSH_SWAP)/stack_util.o
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(EXECUTABLE_CHECKER) $(OBJ_CHECKER) $(OBJ_DIR_PUSH_SWAP)/stack_util.o $(LIBFT)

$(OBJ_DIR_PUSH_SWAP)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_PUSH_SWAP)/stack_util.o: stack_util.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Ajout des dépendances explicites pour les fichiers objets dans checker_a/obj
$(OBJ_DIR_CHECKER)/%.o: checker/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(OBJ_DIR_CHECKER)/checker.o: checker_files/checker.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_CHECKER)/%.o: checker/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR_PUSH_SWAP) $(OBJ_DIR_CHECKER)

fclean: clean
	rm -f $(EXECUTABLE_PUSH_SWAP) $(EXECUTABLE_CHECKER)

re: fclean all

run_push_swap: $(EXECUTABLE_PUSH_SWAP)
	./$(EXECUTABLE_PUSH_SWAP) $(ARGS)

run_checker: $(EXECUTABLE_CHECKER)
	./$(EXECUTABLE_CHECKER) $(ARGS)

.PHONY: all clean fclean re run_push_swap run_checker
