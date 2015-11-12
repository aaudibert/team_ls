# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/05 16:18:14 by aaudiber          #+#    #+#              #
#    Updated: 2015/11/12 20:34:03 by aaudiber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c\
	  parser.c\
	  get_data.c\
	  lst_new.c\
	  lst_push.c\
	  print_dir.c\
	  rewind_lst.c\
	  opt_a.c\
#	  check_params.c\

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
