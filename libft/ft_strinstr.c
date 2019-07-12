/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:15:05 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/20 17:09:45 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strinstr(char *str, char *in)
{
	size_t	len;

	if (!str || !in)
		return (0);
	len = ft_strlen(in);
	while (*str)
	{
		if (*str == *in)
			if (ft_strnstr(str, in, len) == str)
				return (1);
		str++;
	}
	return (0);
}
