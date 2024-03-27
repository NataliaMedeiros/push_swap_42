# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: natalia <natalia@student.42.fr>              +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/13 11:10:51 by nmedeiro      #+#    #+#                  #
#    Updated: 2024/03/27 14:35:57 by nmedeiro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = my_library.a

FILES = ft_substr \
		ft_split \
		ft_atoi \
		ft_strlen \
		ft_strcmp \
		get_next_line \
		get_next_line_utils \
		ft_putendl \
		ft_isdigit \
		ft_atol \

CFILES = $(FILES:%=%.c)
OFILES = $(CFILES:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	@ar -rc $(NAME) $(OFILES)
	@echo "Compiled ✅ $^"

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo "Cleaned my_library ✅"

re: fclean all

.PHONY: all, clean, fclean, re