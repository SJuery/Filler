# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 11:28:46 by sjuery            #+#    #+#              #
#    Updated: 2018/01/22 20:07:33 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= sjuery.filler

SRC		= 	srcs/filler.c \
			srcs/algorithm.c \
			srcs/visualizer.c \

OBJ 	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror -g
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	printf '\033[31m[...] %s\n\033[0m' "Creating Filler Player"
	make -C libft/
	gcc $(CFLAG) -L minilibx libft/libft.a -lmlx -framework OpenGL -framework AppKit -I minilibx $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created Filler Player"

clean:
	printf '\033[31m[...] %s\n\033[0m' "Cleaning Filler Player"
	make fclean -C libft/
	/bin/rm -f srcs/*.o
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned filler Player"

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
