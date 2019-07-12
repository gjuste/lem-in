/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:06:43 by jpelleti          #+#    #+#             */
/*   Updated: 2019/06/21 14:17:58 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *d)
{
	int i;
	int j;

	i = 0;
	if (!s)
		return (0);
	if (!d[0])
		return ((char*)(s));
	while (s[i])
	{
		j = 0;
		while (s[i + j] == d[j] || !d[j])
		{
			if (!d[j])
				return ((char*)(s + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
