# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 16:06:59 by vdaviot           #+#    #+#              #
#    Updated: 2016/01/06 16:07:00 by vdaviot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRCS = src/main.c src/content_list.c src/term_mode.c src/simple_list.c

OBJ = $(SRCS:.c=.o)

INCLUDES = includes/

CMP = clang -Werror -Wall -Wextra 

all: comp

comp: $(OBJ)
	$(CMP) -c $(SRCS) -I includes/
	$(CMP) $(OBJ) -o $(NAME) -lncurses includes/libft/libft.a

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: re clean fclean all