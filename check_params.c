/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 17:05:49 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/06 18:41:18 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
char		**check_params(int ac, char **av, int f)
{
	int				i;
	char			**true_path;
	DIR				*dir;
	struct stat		t;

	i = f;
	while (av[i])
	{
		dir = opendir(av[i]);
		if (dir)
			// set tab DIR;
		else
		{
			stat(av[i], &t);
			if (t.st_mode & S_IFMT)
				// set tab FILE
			else
				// set tab ERROR
		}
		i++;
	}
	return (true_path);
}*/

/*
int		main(int ac, char **av)
{
	check_params(ac, av, 1);
	return (0);
}
*/
