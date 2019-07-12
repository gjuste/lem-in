/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:35:45 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/13 15:28:14 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	tmp[len];

	i = 0;
	if (len > 100000000)
		return (dst);
	while (i < len)
	{
		*(tmp + i) = *((unsigned char*)src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*((unsigned char*)dst + i) = *(tmp + i);
		i++;
	}
	return (dst);
}
