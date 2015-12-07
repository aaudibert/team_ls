/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:09:28 by aaudiber          #+#    #+#             */
/*   Updated: 2015/12/04 18:16:47 by jumiguel         ###   ########.fr       */
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
# include <time.h>

# define FLAG_R		0
# define FLAG_RR	1
# define FLAG_L		2
# define FLAG_A		3
# define FLAG_T		4

extern int			*g_flags;

typedef struct		s_file
{
	struct s_file	*next;
	struct s_file	*prev;
	char			*path;
	char			*f_name;
	int				izdir;
	int				date;
	struct stat		*stat;
}					t_file;

typedef struct	s_prm
{
	int			d;
	int			e;
	int			f;
	char		**error;
	char		**file;
	char		**ddir;
}				t_prm;

typedef struct dirent	t_dirent;

//fonction
int			parser(int ac, char **av);
void		get_data(char *path);
void		lst_push(t_file *elem, t_file **lst);
t_file		*lst_new(char *f_name, char *path);
t_file		*rewind_lst(t_file *lst);
void		print_dir(t_file *dir);
int			opt_a(t_file *dir);
void		ft_recurs(t_file *dir);
void		ft_rrecurs(t_file *dir);
t_prm		*check_params(char **paths, t_prm *s, int i);
char		**checks(char **paths, int f);
void		sort_params(char **tab);
void		sort_dir(t_file *dir);
void		sort_date(t_file *dir);
#endif
