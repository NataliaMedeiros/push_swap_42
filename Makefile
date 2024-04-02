NAME = push_swap
BONUS = checker
MYLIB = my_library/my_library.a

FILES = push_swap \
		handle_errors \
		free_utils \
		linked_list \
		sort \
		operations \
		init_a_to_b \
		init_b_to_a \
		sort_bigger \
		sort_utils \
		init_utils \
		rotations \

BONUS_FILES = checker \
			bonus_error_check \
			bonus_utils \
			bonus_linked_list_utils \
			bonus_operations \

CFILES = $(FILES:%=%.c)
CBONUS = $(BONUS_FILES:%=%.c)

OFILES = $(CFILES:%.c=%.o)
OBONUS = $(CBONUS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MYLIBDIR = my_library

all: $(NAME)

$(MYLIB):
	@echo "Compiling ..."
	@make -C $(MYLIBDIR)
	@echo "Compiled ✅ $(MYLIB)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(MYLIBDIR)

$(NAME): $(MYLIB) $(OFILES)
#	@cp $(MYLIB) $(NAME)
#	@ar -rc $(NAME) $(OFILES) ${MYLIB}
	$(CC) $(CFLAGS) $(OFILES) $(MYLIB) -o $(NAME)
	@echo "Compiled push_swap ✅ $^"

bonus: $(MYLIB) $(OBONUS)
	$(CC) $(CFLAGS) $(OBONUS) $(MYLIB) -o $(BONUS)
	@echo "Compiled checker ✅ $^"

clean:
	@rm -f $(OFILES)
	@rm -f $(OBONUS)

fclean: clean
	@cd my_library && $(MAKE) fclean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@echo "Cleaned all ✅"

re: fclean all

.PHONY: all, clean, fclean, re, bonus
