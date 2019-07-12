/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:16:49 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/04 14:44:32 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_do_it(const char *s, char c, char **res)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			res[k][j] = s[i];
			j++;
			i++;
		}
		res[k][j] = '\0';
		if (s[i] || s[i - 1] != c)
			k++;
		if (s[i + 1] == '\0')
			i++;
	}
	res[k] = NULL;
	return (res);
}
