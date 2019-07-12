/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mesure_let.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:15:46 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/16 10:12:41 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_mesure_let(const char *s, char sep, int count)
{
	int i;
	int j;
	int save;

	i = 0;
	j = 0;
	while (s[i] && j <= count)
	{
		while (s[i] == sep)
			i++;
		save = i;
		j++;
		while (s[i] != sep && s[i])
			i++;
	}
	return (i - save);
}
