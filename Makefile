NAME			=		ft_ping
NAME_TEST		=		test
CC				=		cc
AR				=		ar rcs
RM				=		rm -rf
CFLAGS			=		-Wall -Wextra -Werror -Ofast
SRC				=		utils
SRC_FILES		=		$(addprefix src/, $(addsuffix .c, $(SRC)))
SRC_MAIN		=		src/main.c	$(SRC_FILES)
SRC_TEST		=		tests/test.c	$(SRC_FILES)
OBJ				=		$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_DIR			=		obj

RED = \033[31m
GREEN = \033[32m
RESET = \033[0m

$(NAME) : $(OBJ)
	@echo "----- Compiling ft_ping -----"
	# ${CC} ${SRC_MAIN} -o ${NAME}  ${LIBFT_LIB} ${GNL_LIB} ${CFLAGS}
	${CC} ${SRC_MAIN} -o ${NAME}  ${LIBFT_LIB} ${GNL_LIB}
	clear
	@echo "$(RED)╔═════════════════════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(RED)║$(GREEN)                             ft_ping Compiled!                             $(RED)║$(RESET)"
	@echo "$(RED)╚═════════════════════════════════════════════════════════════════════════════╝$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	
all: ${NAME}

clean:
	rm -rf $(OBJ_DIR)
	clear

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_TEST}
	clear
	
re: fclean all

test: $(OBJ)
	@echo "----- Compiling Test ft_ping -----"
	@time -p (	${CC} ${SRC_TEST} -o ${NAME_TEST} ${CFLAGS} )
	clear
	@echo "$(RED)╔════════════════════════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(RED)║$(GREEN)                           Compiling and Running Test ...                       $(RED)║$(RESET)"
	@echo "$(RED)╚════════════════════════════════════════════════════════════════════════════════╝$(RESET)"
	@echo
	@echo
	@./test
	@echo

valgrind :
	@valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --error-limit=no --tool=memcheck -s $(NAME_TEST)

.PHONY: all install clean fclean re