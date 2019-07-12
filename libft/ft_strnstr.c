/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:56:45 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/20 17:11:35 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	save;

	i = 0;
	if (*need == '\0')
		return ((char *)hay);
	while (hay[i] != '\0' && i < len)
	{
		y = 0;
		if (hay[i] == need[y])
		{
			save = i;
			while (hay[save] == need[y] && save < len)
			{
				if (need[y + 1] == '\0')
					return ((char *)&hay[i]);
				y++;
				save++;
			}
		}
		i++;
	}
	return (NULL);
}
