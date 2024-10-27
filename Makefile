NAME = libftprintf.a

HEADERS = /libft.h ft_printf.h push_swap.h

SOURCES_LIBFT = sources_ft_printf/ft_printf.c sources_ft_printf/ft_putcharlen.c sources_ft_printf/ft_putnbrhexlen.c \
		sources_ft_printf/ft_putnbrlen.c sources_ft_printf/ft_putptrlen.c sources_ft_printf/ft_putstrlen.c \
		sources_libft/ft_strlen.c sources_libft/ft_atoi.c sources_libft/ft_itoa.c sources_libft/ft_isdigit.c \
		sources_libft/ft_free.c sources_libft/ft_split.c sources_libft/ft_strcmp.c sources_libft/ft_strdup.c \
		sources_libft/ft_strlcpy.c sources_libft/ft_substr.c sources_libft/ft_nb_words.c

SOURCES_PRINTF = sources_ft_printf/ft_printf.c sources_ft_printf/ft_putcharlen.c sources_ft_printf/ft_putnbrhexlen.c \
		sources_ft_printf/ft_putnbrlen.c sources_ft_printf/ft_putptrlen.c sources_ft_printf/ft_putstrlen.c

SOURCES_PUSH_SWAP = sources_push_swap/utils/check_errors.c sources_push_swap/instructions/instructions.c \
					sources_push_swap/instructions/push.c sources_push_swap/instructions/rotate.c \
					sources_push_swap/instructions/swap.c sources_push_swap/instructions/reverse.c \
					sources_push_swap/algo/turkish.c sources_push_swap/algo/ft_sort.c \
					sources_push_swap/algo/ft_sort_three.c sources_push_swap/utils/print_stack.c \
					sources_push_swap/algo/ft_sort_10.c sources_push_swap/algo/tools.c \

PROGRAM = push_swap.c

PROGRAMME_OUT = push_swap

ARGS = 1 5 8 3 4 9

INFO = libft printf push_swap

OBJECTS = $(SOURCES_LIBFT:.c=.o) $(SOURCES_PRINTF:.c=.o) $(SOURCES_PUSH_SWAP:.c=.o)

CFLAGS = -Werror -Wall -Wextra -g3

CC = cc

AR = ar rcs

RM = rm -f

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "              $(YELLOW) **** >>>>> Compiling: $(INFO) <<<<< **** $(DEF_COLOR)"
	$(AR) $@ $^
	@echo ""
	@echo ""
	@echo "$(MAGENTA)>>>>> $(INFO) compiled!$(DEF_COLOR)"

all: push_swap.c
	@echo ""
	@echo "$(GREEN)          () ()$(DEF_COLOR)"
	@echo "$(GREEN)          (>.<) $(DEF_COLOR)"
	@echo "$(GREEN)          ( . ) $(DEF_COLOR)"
	@echo "$(GREEN)           n_n $(DEF_COLOR)"
	$(CC) $(CFLAGS) $(PROGRAM) $(NAME) -o $(PROGRAMME_OUT)
	@echo ""
	@echo "$(MAGENTA)>>>>> Programme : $(PROGRAMME_OUT) compiled!$(DEF_COLOR)"
	@echo ""
#	@echo "$(CYAN)>>>>> Launching $(PROGRAMME_OUT) with arguments : $(ARGS)$(DEF_COLOR)"
	@echo ""
#	./$(PROGRAMME_OUT) $(ARGS)


clean:
	$(RM) $(OBJECTS)
	@echo "$(MAGENTA)CLEAN OBJECTS FOR :  $(OBJECTS) ! $(DEF_COLOR)"
	
fclean: clean
	$(RM) $(NAME)
	@echo "$(MAGENTA)CLEAN NAME FOR :  $(OBJECTS) ! $(DEF_COLOR)"


re: fclean all

.PHONY: clean fclean all re
