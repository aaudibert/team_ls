/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:21:17 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/30 19:16:33 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_prm		*count_params(char **paths, t_prm *s, int i)
{
	struct stat		t;

	s->d = 0;
	s->f = 0;
	s->e = 0;
	while (paths[i])
	{
		if (lstat(paths[i], &t) != 0)
			s->e++;
		else if ((t.st_mode & S_IFREG) || (S_ISLNK(t.st_mode) &&
					paths[i][ft_strlen(paths[i])] == '/' &&
					g_flags[FLAG_L] == 1))
			s->f++;
		else if (S_ISDIR(t.st_mode))
			s->d++;
		i++;
	}
	return (s);
}

void		print_err(char **err)
{
	int i;
	struct stat		t;

	i = 0;
	while (err[i])
	{
		ft_putstr("ls: ");
		ft_putstr(err[i]);
		lstat(err[i++], &t);
		if (errno == EACCES)
			ft_putendl(": Permission denied");
		else
			ft_putendl(": No such file or directory");
	}
}

void		print_file(char **file)
{
	t_file	*dir;

	dir = file_l(file);
	if (no_perm(dir) && g_flags[FLAG_R] == 1 && g_flags[FLAG_T] == 1)
		rsort_date(dir);
	else if (g_flags[FLAG_R] == 1 && g_flags[FLAG_T] != 1)
		rsort_dir(dir);
	else if (no_perm(dir) && g_flags[FLAG_R] != 1 && g_flags[FLAG_T] == 1)
		sort_date(dir);
	else
		sort_dir(dir);
	if (g_flags[FLAG_L] == 1)
		ls_l(dir, 1, NULL);
	else
		print_dir(dir, 1);
	ft_free_dir_lst(dir);
}

t_file		*checks(char **paths, int i)
{
	t_prm	s;
	t_file	*ret;

	ret = NULL;
	count_params(paths, &s, i);
	check_params(paths, &s, i);
	if (s.error)
	{
		sort_params(s.error);
		print_err(s.error);
	}
	if (s.file)
		print_file(s.file);
	if (s.ddir && s.file)
		ft_putchar('\n');
	if (s.ddir)
		ret = sort_pdirs(s.ddir);
	return (ret);
}
