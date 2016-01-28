/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 17:09:28 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/28 17:58:25 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"
# include <time.h>
# include <pwd.h>
# include <grp.h>

# define FLAG_R			0
# define FLAG_RR		1
# define FLAG_L			2
# define FLAG_A			3
# define FLAG_T			4

extern int				*g_flags;

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct			s_file
{
	char				*path;
	char				*f_name;
	t_stat				*stat;
	struct s_file		*next;
	struct s_file		*prev;
}						t_file;

typedef struct			s_prm
{
	int					d;
	int					e;
	int					f;
	char				**error;
	char				**file;
	char				**ddir;
}						t_prm;

int						parser(int ac, char **av);
t_prm					*check_params(char **paths, t_prm *s, int i);
char					**checks(char **paths, int f);
t_file					*file_l(char **file);
void					get_data(char *path);
void					lst_push(t_file *elem, t_file **lst);
t_file					*lst_new(char *f_name, char *path, int i);
t_file					*rewind_lst(t_file *lst);
void					print_dir(t_file *dir, int i);
int						opt_a(t_file *dir);
void					ft_recurs(t_file *dir);
void					sort_params(char **tab);
void					sort_dir(t_file *dir);
void					sort_date(t_file *dir);
void					rsort_dir(t_file *dir);
void					rsort_date(t_file *dir);
int						swap_dir(t_file *dir);
void					ls_l(t_file *dir, int i);
void					permissions_proprio(struct stat stats);
void					permissions_locataire(struct stat stats);
void					permissions_babacar(struct stat stats);
void					nationalite(struct stat stats);
void					letters(struct stat stats);
unsigned int			*max(t_file *dir);
void					display_size_right(int max_size, struct stat stats);
void					display_link_right(int max_link, struct stat stats);
void					ft_putstr_space(char *str, int nbr_sp);
void					display_date_right(char **tab);
void					total_block(t_file *dir);
void					affect(struct stat stats);
void					ifslnk(struct stat stats, t_file *dir);
void					date(struct stat stats);
void					del_link(t_file *dir);
void					ft_free_dir_lst(t_file *dir);
void					del_struct(t_prm s);
#endif