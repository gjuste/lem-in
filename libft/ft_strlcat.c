/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:13:41 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/16 11:08:24 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	len = size - ft_strlen(dst) - 1;
	while (dst[i])
		i++;
	while (src[j] && j <= len)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (j <= len)
		dst[i + j] = '\0';
	else
		dst[i + j - 1] = '\0';
	if (size == 0)
		return (ft_strlen(dst));
	return (i + ft_strlen(src));
}
