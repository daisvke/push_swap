CC				=	clang $(FLAGS)
FLAGS			=	-Wall -Wextra -Werror -g $(MEM)
MEM				=	-fsanitize=address

RM				=	rm -rf

LIB				=	libft/libft.a

#
# PUSH SWAP
#
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

PS_OBJ_DIR		=	ps_obj/
PS_OBJ_FILES	=	$(PS_SRC_FILES:.c=.o)
PS_OBJ			=	$(addprefix $(PS_OBJ_DIR), $(PS_OBJ_FILES))

#
# CHECKER
#
CH_EXEC			=	checker
CH_SRC_DIR		=	src_checker/
CH_SRC_FILES	=	checker_utils.c \
					commands_1_swap_push.c \
					commands_2_rotation.c \
					exit.c \
					init.c \
					main.c \
					parsing.c \
					utils_linked_list.c
CH_SRC			=	$(addprefix $(CH_SRC_DIR), $(CH_SRC_FILES))

CH_OBJ_DIR		=	ch_obj/
CH_OBJ_FILES	=	$(CH_SRC_FILES:.c=.o)
CH_OBJ			=	$(addprefix $(CH_OBJ_DIR), $(CH_OBJ_FILES))

all: $(PS_EXEC) $(CH_EXEC)

# PUSH SWAP
$(PS_EXEC): $(PS_OBJ)
	@echo -n "\n"
	@echo -n "NOW COMPILING LIBFT..."
	@make -s -C libft/
	@echo "\033[32m\t\t\t[OK]\033[0m"
	@echo -n "\n"
	@echo -n "NOW GENERATING PUSH_SWAP..."
	@$(CC) $(PS_OBJ) $(LIB) -o $(PS_EXEC)
	@echo "\033[32m\t\t[OK]\033[0m\n"

$(PS_OBJ_DIR)%.o: $(PS_SRC_DIR)%.c
	@mkdir -p ps_obj
	@$(CC) -c $< -o $@

# CHECKER
$(CH_EXEC): $(CH_OBJ)
	@echo -n "NOW GENERATING CHECKER..."
	@$(CC) $(CH_OBJ) $(LIB) -o $(CH_EXEC)
	@echo "\033[32m\t\t[OK]\033[0m\n"
	
$(CH_OBJ_DIR)%.o: $(CH_SRC_DIR)%.c
	@mkdir -p ch_obj
	@$(CC) -c $< -o $@

clean:
	@make -s clean -C libft/
	$(RM) $(PS_OBJ_DIR) $(CH_OBJ_DIR)

fclean: clean
	@make -s fclean -C libft/
	$(RM) $(PS_EXEC) $(CH_EXEC)

re: fclean all

.PHONY: all clean fclean re
