# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/12 20:19:31 by yalaouf           #+#    #+#              #
#    Updated: 2015/06/02 20:13:32 by yalaouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror
LIBFT = libft.a
OBJ_PATH = ./obj
SRC =	./srcs/*/*.c

LINK = $(SRC:.c=.o)

all: $(LIBFT)

$(LIBFT):
	@mkdir $(OBJ_PATH)
	@gcc -c $(SRC)
	@mv *.o $(OBJ_PATH)
	@ar rc $(LIBFT) ./obj/*.o
	@ranlib $(LIBFT)
	@echo "COMPILATION DONE"

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(LIBFT)
	@echo "FCLEAN DONE"

re: fclean all
