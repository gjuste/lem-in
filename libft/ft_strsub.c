/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:21:04 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/24 16:18:38 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (len == 0)
		return (ft_strnew(0));
	if (!(tab = ft_strnew((len + start > l ? l - start : len))))
		return (NULL);
	while (i < len && start + i < l)
	{
		tab[i] = s[start + i];
		i++;
	}
	return (tab);
}
