/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/17 16:43:56 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/25 17:59:33 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_prm	*count_params(char **paths, t_prm *s, int i)
{
	int				v;
	DIR				*dir;
	struct stat		t;

	s->d = 0;
	s->f = 0;
	s->e = 0;
	while (av[i])
	{
		dir = opendir(av[i]);
		v = stat(av[i], &t);
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
	if (g_flags[FLAG_R] != 1)
	{
		while(err[i])
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
	if (g_flags[FLAG_R] != 1)
	{
		while(file[i])
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
		while (file[i])
		{
			ft_putstr(file[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
}

char		**checks(char **paths, int i)
{
	t_prm	s;
	char	**true_path;

	count_params(paths, &s, 1);
	true_path = check_params(ac, paths, &s, 1);
	if (s.error)
		print_err(s.error);
	if (s.file)
		print_file(s.file);
	return (true_path);
}
