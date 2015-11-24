/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:09:34 by rlechapt          #+#    #+#             */
/*   Updated: 2015/11/24 15:52:31 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"*/
#include "ft_ls.h"


/*void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
*/
void	sort(char **tab)
{
	int	i;
	char *tmp;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

/*int		main(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*) * 8);
	tab[0] = "Makefile";
	tab[1] = "234567";
	tab[2] = "24567";
	tab[3] = "moumou";
	tab[4] = "Mate";
	tab[5] = "zozo";
	tab[6] = "@#$%^";
	tab[7] = NULL;
	print_tab(tab);
	sort(tab);
	printf("\n");
	print_tab(tab);
	return (0);
}*/
