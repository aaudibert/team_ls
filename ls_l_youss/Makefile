# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/19 14:20:18 by yalaouf           #+#    #+#              #
#    Updated: 2015/11/19 21:25:36 by yalaouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
LIBF = -L./libft -lft
NAME = ft_ls
SRCS =	./srcs/*.c
OBJ_PATH = ./obj
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME):
		@make -C libft/
		@mkdir $(OBJ_PATH)
		@gcc -c $(SRCS) -g
		@mv *.o $(OBJ_PATH)
		@gcc $(CFLAGS) $(LIBF) -o $(NAME) $(OBJ_PATH)/*.o
		@echo "FT_LS COMPILATION DONE !"

clean :
		@make clean -C libft/
		@rm -rf $(OBJ_PATH)
		@echo "FT_LS CLEANED !"

fclean : clean
		@make fclean -C libft/
		@rm -rf $(NAME)
		@echo "FT_LS ALL CLEANED !"

re : fclean all
