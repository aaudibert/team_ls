/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 19:40:16 by psaint-j          #+#    #+#             */
/*   Updated: 2015/11/12 21:15:02 by psaint-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void tab_trier(int *tab, int n)
{
	int i, tmp, permutation = 1;
	while (permutation == 1)
	{
		permutation = 0;
		i = 0;
		while (i < n-1)
		{
			if (tab[i] > tab[i+1])
			{
				tmp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = tmp;
				permutation = 1;
			}
			i++;
		}
	}
}

void tab_trier_ascii(char **tab, int n)
{
	int i, permutation = 1;
	char *tmp;

	while (permutation == 1)
	{
		permutation = 0;
		i = 0;
		while (i < n-1)
		{
			if (tab[i][0] > tab[i+1][0])
			{
				tmp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = tmp;
				permutation = 1;
			}
			i++;
		}
	}
}
