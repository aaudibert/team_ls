/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:21:17 by aaudiber          #+#    #+#             */
/*   Updated: 2016/04/28 16:38:02 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

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
		if (dir || errno)
		{
			s->d++;
			if (dir)
				closedir(dir);
		}
		if (v != 0)
			s->e++;
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
	while (err[i])
	{
		ft_putstr("ls: ");
		ft_putstr(err[i]);
		ft_putendl(": No such file or directory");
		i++;
	}
}

void		print_file(char **file)
{
	t_file	*dir;

	dir = file_l(file);
	if (g_flags[FLAG_R] == 1)
		rsort_dir(dir);
	else
		sort_dir(dir);
	if (g_flags[FLAG_L] == 1)
		ls_l(dir, 1, NULL);
	else
		print_dir(dir, 1);
	ft_free_dir_lst(dir);
}

char		**get_dir(char **a)
{
	int		i;
	char	**ret;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * arr_size(a) + 1);
	ret[arr_size(a)] = NULL;
	while (a[i])
	{
		ret[i] = ft_strdup(a[i]);
		i++;
	}
	return (ret);
}

char		**checks(char **paths, int i)
{
	t_prm	s;
	char	**ret;

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
	{
		ret = get_dir(s.ddir);
		sort_params(ret);
	}
	return (ret);
}
