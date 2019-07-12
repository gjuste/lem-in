/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mesure_wor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:13:25 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/16 10:10:34 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_mesure_wor(const char *s, char sep)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		j++;
		if (!s[i])
			return (j);
		while (s[i] != sep && s[i])
			i++;
	}
	return (j);
}
