# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/05 16:18:14 by aaudiber          #+#    #+#              #
#    Updated: 2016/02/11 14:02:29 by psaint-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ./srcs/ft_ls.c\
	  ./srcs/parser.c\
	  ./srcs/get_data.c\
	  ./srcs/lst_new.c\
	  ./srcs/lst_push.c\
	  ./srcs/print_dir.c\
	  ./srcs/rewind_lst.c\
	  ./srcs/opt_a.c\
	  ./srcs/ft_recurs.c\
	  ./srcs/sort.c\
	  ./srcs/check_params.c\
	  ./srcs/checks.c\
	  ./srcs/flag.c\
	  ./srcs/ls_l_tools.c\
	  ./srcs/permission.c\
	  ./srcs/tools.c\
	  ./srcs/ft_free_dir_lst.c\
	  ./srcs/rsort.c\
	  ./srcs/get_path.c\
	  ./srcs/file_l.c\
	  ./srcs/free_tools.c

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	@/bin/echo "-----Compilating sources-----"
	@make -C ./libft
	@/bin/echo "---Done---"
	@/bin/echo "-----Creating executable-----"
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I./libft/includes/ ./libft/libft.a
	@/bin/echo "---Done---"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean:
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
