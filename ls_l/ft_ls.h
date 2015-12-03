/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <yalaouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 19:11:05 by yalaouf           #+#    #+#             */
/*   Updated: 2015/11/25 20:11:48 by yalaouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include "libft/libft.h"
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct		s_file
{
	char			*name;
	struct stat		*stats;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

//All flags functions
//void				ls_1(void);
//void				ls_a(void);
void				ls_l(void);
//void				ls_R(void);

//All ls -l functions:
void				permissions_proprio(struct stat stats);
void				permissions_locataire(struct stat stats);
void				permissions_babacar(struct stat stats);
void				nationalite(struct stat stats, struct dirent *lecture);
void				letters(struct stat stats, struct dirent *lecture);
int					*max(void);
void				display_size_right(int max_size, struct stat stats);
void				display_link_right(int max_link, struct stat stats);
void				ft_putstr_space(char *str, int nbr_sp);
void				display_date_right(char **tab);
void				total_block(void);
void				affect(struct stat stats, struct dirent *lecture);
void				ifslnk(struct stat stats, struct dirent *lecture);
void				date(struct stat stats);

//All lists functions
t_file				*new_lst(t_file *list, char *name);
void				push_lst(t_file **list, t_file *elem);
t_file				*rewind_lst(t_file *elem);

#endif
