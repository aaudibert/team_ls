/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:21:17 by aaudiber          #+#    #+#             */
/*   Updated: 2016/01/26 19:10:52 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_prm		*count_params(char **paths, t_prm *s, int i)
{
	int				v;
	DIR				*dir;
	struct stat		t;

	s->d = 0;
	s->f = 0;
	s->e = 0;
	while (paths[i])
	{
		dir = opendir(paths[i]);
		v = stat(paths[i], &t);
		if (dir)
			s->d++;
		if (v != 0)
		{
			s->e++;
		}
		else if ((t.st_mode & S_IFREG))
			s->f++;
		i++;
	}
	return (s);
}

void		print_err(char **err)
{
	int i;

	i = 0;
	if (g_flags[FLAG_R] == 1)
	{
		while (err[i])
			i++;
		while (--i >= 0)
		{
			ft_putstr("ls: ");
			ft_putstr(err[i]);
			ft_putendl(" No such file or directory");
		}
	}
	else
	{
		while (err[i])
		{
			ft_putstr("ls: ");
			ft_putstr(err[i]);
			ft_putendl(" No such file or directory");
			i++;
		}
	}
}

void		print_file(char **file)
{
	int i;

	i = 0;
	if (g_flags[FLAG_R] == 1)
	{
		while (file[i])
			i++;
		while (--i >= 0)
		{
			ft_putstr(file[i]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	else
	{
		while (file[i++])
		{
			ft_putstr(file[i]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

char		**checks(char **paths, int i)
{
	t_prm	s;
	t_file	*dir;

	count_params(paths, &s, i);
	check_params(paths, &s, i);
	if (s.error)
	{
		sort_params(s.error);
		print_err(s.error);
	}
	if (s.file)
	{
		dir = file_l(s.file);
		if (g_flags[FLAG_R] == 1)
			rsort_dir(dir);
		else
			sort_dir(dir);
		if (g_flags[FLAG_L] == 1)
			ls_l(dir, 1);
		else
			print_dir(dir);
		/*if (s.file[1] && (g_flags[FLAG_T] || g_flags[FLAG_L]))
			file_tl(s.file);
		else
		{
			sort_params(s.file);
			print_file(s.file);
		}*/
	}
	if (s.ddir && (s.file || s.error))
		ft_putchar('\n');
	if (s.ddir)
		sort_params(s.ddir);
	return (s.ddir);
}
