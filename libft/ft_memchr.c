/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:52:42 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/07 13:56:57 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (*((unsigned char*)s + i) == (unsigned char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
