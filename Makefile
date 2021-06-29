CC				=	clang $(FLAGS)
MEM				=	-fsanitize=address

RM				=	rm -rf

LIB				=	libft/libft.a

PS_EXEC			=	push_swap
PS_SRC_DIR		=	src/
PS_SRC_FILES	=	commands_1_swap_push.c \
					commands_2_rotation.c \
					exit.c \
					init.c \
					main.c \
					parsing.c \
					sort_lowests.c \
					sort_radix.c \
					sort_three_elem.c \
					sort_utils.c \
					utils_linked_list.c \
					utils_numbers.c
PS_SRC			=	$(addprefix $(PS_SRC_DIR), $(PS_SRC_FILES))

PS_OBJ_DIR			=	ps_obj/
PS_OBJ_FILES		=	$(PS_SRC_FILES:.c=.o)
PS_OBJ				=	$(addprefix $(PS_OBJ_DIR), $(PS_OBJ_FILES))

all: $(PS_EXEC)

$(PS_EXEC): $(PS_OBJ)
	@echo -n "\n"
	@echo -n "NOW COMPILING LIBFT..."
	@make -s -C libft/
	@echo "\033[32m\t\t\t[OK]\033[0m"
	@echo -n "\nNOW GENERATING PUSH_SWAP..."
	@$(CC) $(PS_OBJ) $(LIB) -o $(PS_EXEC)
	@echo "\033[32m\t\t[OK]\033[0m\n"

$(PS_OBJ_DIR)%.o: $(PS_SRC_DIR)%.c
	@mkdir -p ps_obj
	@$(CC) -c $< -o $@

clean:
	@make -s clean -C libft/
	$(RM) $(PS_OBJ_DIR)

fclean: clean
	@make -s fclean -C libft/
	$(RM) $(PS_EXEC)

re: fclean all

.PHONY: all clean fclean re
