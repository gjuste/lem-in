/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:06:53 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/19 20:15:07 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*tab;
	size_t	i;

	i = 0;
	if ((int)n < 0)
		return (NULL);
	if (!(tab = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
