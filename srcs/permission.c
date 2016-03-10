/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalaouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:05:47 by yalaouf           #+#    #+#             */
/*   Updated: 2016/03/10 19:39:17 by aaudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	nationalite(struct stat stats)
{
	if (S_ISDIR(stats.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(stats.st_mode))
		ft_putchar('l');
	else if (S_ISFIFO(stats.st_mode))
		ft_putchar('p');
	else if (S_ISBLK(stats.st_mode))
		ft_putchar('b');
	else if (S_ISSOCK(stats.st_mode))
		ft_putchar('s');
	else if (S_ISCHR(stats.st_mode))
		ft_putchar('c');
	else if (S_ISREG(stats.st_mode))
		ft_putchar('-');
}

void	permissions_proprio(struct stat stats)
{
	if (stats.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IXUSR)
	{
		if (stats.st_mode & S_ISUID)
			ft_putchar('s');
		else
			ft_putchar('x');
	}
	else if (stats.st_mode & S_ISUID)
		ft_putchar('S');
	else
		ft_putchar('-');
}

void	permissions_locataire(struct stat stats)
{
	if (stats.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IXGRP)
	{
		if (stats.st_mode & S_ISGID)
			ft_putchar('s');
		else
			ft_putchar('x');
	}
	else if (stats.st_mode & S_ISGID)
		ft_putchar('S');
	else
		ft_putchar('-');
}

void	permissions_babacar(struct stat stats)
{
	if (stats.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (stats.st_mode & S_IXOTH)
	{
		if (stats.st_mode & S_ISVTX)
			ft_putchar('t');
		else
			ft_putchar('x');
	}
	else if (stats.st_mode & S_ISVTX)
		ft_putchar('T');
	else
		ft_putchar('-');
}

void	letters(struct stat stats)
{
	nationalite(stats);
	permissions_proprio(stats);
	permissions_locataire(stats);
	permissions_babacar(stats);
}
