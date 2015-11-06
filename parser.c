/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:35:32 by aaudiber          #+#    #+#             */
/*   Updated: 2015/11/06 18:06:40 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		act_flag(char flag)
{
	ft_putendl("yolo");
	if (flag == 'l')
		g_flags[FLAG_L] = 1;
	else if (flag == 'r')
		g_flags[FLAG_R] = 1;
	else if (flag == 'R')
		g_flags[FLAG_RR] = 1;
	else if (flag == 't')
		g_flags[FLAG_T] = 1;
	else if (flag == 'a')
	{
		g_flags[FLAG_A] = 1;
		ft_putendl("mdr");
	}
	ft_putendl("yolo");
}

void		wrong_flag(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-Ralrt] [file ...]");
	ft_putchar('\n');
	exit(1);
}

int			check_flags(char flag)
{
	if (flag == 'R'
		|| flag == 'l'
		|| flag == 'r'
		|| flag == 'a'
		|| flag == 't')
		return (1);
	return (0);
}

void		check_opt(char *opt)
{
	int i;

	i = 1;
	while (opt[i] != '\0')
	{
		ft_putendl("dbt wh opt");
		if (check_flags(opt[i]) == 0)
			wrong_flag(opt[i]);
		else
		{
			ft_putendl("else opt");
			act_flag(opt[i]);
		}
		ft_putendl("fin while opt");
		i++;
	}
}

int			parser(int ac, char **av)
{
	int	f;
	int	i;

	f = 0;
	i = 1;
		ft_putendl("opt");
	while (i <= ac && av[i][0] == '-')
	{
		ft_putendl("dbt wh pars");
		if (av[i][0] == '-')
		{
			ft_putendl("if pars");
			check_opt(av[i]);
			f++;
		}
		ft_putendl("fin wh pars");
		i++;
	}
		ft_putendl("opt");
	return (f);
}
