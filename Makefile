NAME = push_libft.a

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libftprintf.a

HEADERS = libft.h ft_printf.h push_swap.h get_next_line.h

SOURCES_PUSH_SWAP = sources_push_swap/utils/check_errors.c \
                    sources_push_swap/utils/print_stack.c sources_push_swap/utils/tools.c \
                    sources_push_swap/instructions/rotate.c sources_push_swap/instructions/push.c \
                    sources_push_swap/instructions/rev_rotate.c sources_push_swap/instructions/swap.c \
                    sources_push_swap/algo/ft_sort_three_node.c sources_push_swap/algo/ft_sort_10_node.c \
                    sources_push_swap/algo/ft_index_sort.c sources_push_swap/utils/ft_make_node.c \
                    sources_push_swap/utils/ft_free_mem.c

SOURCES_CHECKER = sources_push_swap/checker_bonus.c

OBJECTS = $(SOURCES_PUSH_SWAP:.c=.o)

PROGRAM = sources_push_swap/push_swap.c

PROGRAMME_OUT = push_swap

BONUS_CHECKER_OUT = checker_bonus

CFLAGS = -Werror -Wall -Wextra -g3

CC = cc

AR = ar rcs

RM = rm -f

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(PROGRAMME_OUT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAMME_OUT): $(LIBFT) $(OBJECTS)
	@echo "              $(YELLOW) **** >>>>> Compiling: $(INFO) <<<<< **** $(DEF_COLOR)"
	$(CC) $(CFLAGS) $(PROGRAM) $(OBJECTS) -L$(LIBFT_DIR) -lftprintf -o $(PROGRAMME_OUT)
	@echo ""
	@echo ""
	@echo "$(GREEN)          () () $(DEF_COLOR)"
	@echo "$(GREEN)          (>.<) $(DEF_COLOR)"
	@echo "$(GREEN)          ( . ) $(DEF_COLOR)"
	@echo "$(GREEN)           n_n  $(DEF_COLOR)"
	@echo "$(MAGENTA)>>>>> $(INFO) compiled!$(DEF_COLOR)"

bonus: $(LIBFT) $(OBJECTS)
	@echo "$(YELLOW)**** Compiling checker_bonus ****$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(SOURCES_CHECKER) $(OBJECTS) -L$(LIBFT_DIR) -lftprintf -o $(BONUS_CHECKER_OUT)
	@echo "$(GREEN)Checker bonus created successfully!$(DEF_COLOR)"

clean:
	$(RM) $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(MAGENTA)CLEAN OBJECTS FOR :  $(OBJECTS) ! $(DEF_COLOR)"
	
fclean: clean
	$(RM) $(PROGRAMME_OUT) $(BONUS_CHECKER_OUT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(MAGENTA)CLEAN NAME FOR :  $(OBJECTS) ! $(DEF_COLOR)"

re: fclean all

.PHONY: clean fclean all re bonus
