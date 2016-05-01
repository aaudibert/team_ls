/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudiber <aaudiber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:35:32 by aaudiber          #+#    #+#             */
/*   Updated: 2016/05/01 19:58:29 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			g_rec;

void		act_flag(char flag)
{
	if (flag == 'l')
		g_flags[FLAG_L] = 1;
	else if (flag == 'r')
		g_flags[FLAG_R] = 1;
	else if (flag == 'R')
		g_flags[FLAG_RR] = 1;
	else if (flag == 't')
		g_flags[FLAG_T] = 1;
	else if (flag == 'a')
		g_flags[FLAG_A] = 1;
	else if (flag == 'G')
		g_flags[FLAG_GG] = 1;
	else if (flag == 'T')
		g_flags[FLAG_TT] = 1;
	else if (flag == 'A')
		g_flags[FLAG_AA] = 1;
}

void		wrong_flag(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-AGRTalrt] [file ...]");
	ft_putchar('\n');
	exit(1);
}

int			check_flags(char flag)
{
	if (flag == 'R' || flag == 'l' || flag == 'r' || flag == 'a'
			|| flag == 't' || flag == 'G' || flag == 'T' || flag == 'A')
		return (1);
	return (0);
}

void		check_opt(char *opt)
{
	int i;

	i = 1;
	while (opt[i] != '\0')
	{
		if (check_flags(opt[i]) == 0)
			wrong_flag(opt[i]);
		else
			act_flag(opt[i]);
		i++;
	}
}

int			parser(int ac, char **av)
{
	int	f;
	int	i;

	g_rec = 0;
	f = 0;
	i = 1;
	while (ac > i && av[i][0] == '-')
	{
		if (av[i][0] == '-' && av[i][1])
		{
			check_opt(av[i]);
			f++;
		}
		i++;
	}
	return (f);
}
