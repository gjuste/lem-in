/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 22:41:44 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/03 18:36:59 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_tabint(int y, int x)
{
	int		**tab;
	int		i;
	int		j;

	if (!(tab = (int **)malloc(sizeof(int *) * y)))
		return (NULL);
	i = 0;
	while (i < y)
	{
		tab[i] = NULL;
		if (!(tab[i] = (int *)malloc(sizeof(int) * x)))
			return (NULL);
		j = 0;
		while (j < x)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}
