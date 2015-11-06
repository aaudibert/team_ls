/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:09:28 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/06 17:32:01 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include "libft/includes/libft.h"

# define FLAG_R		0
# define FLAG_RR	1
# define FLAG_L		2
# define FLAG_A		3
# define FLAG_T		4

extern int			*g_flags;

typedef struct			s_file
{
	struct s_file		*next;
	struct s_file		*prev;
	char				*path;
	char				*f_name;
	struct stat			*stat;
}						t_file;

typedef struct			t_path
{
	struct t_path		*next;
	char				**path;
}						t_path;

typedef struct			dirent	t_dirent;

//fonction
int			parser(int ac, char **av);
void		get_data(char *path);
void		lst_push(t_file *elem, t_file **lst);
t_file		*lst_new(char *f_name, char *path);
void		print_dir(t_file *dir);
#endif
