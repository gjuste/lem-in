/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:13:10 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/12 10:17:00 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = NULL;
	if (s != NULL)
	{
		if (!(str = malloc(sizeof(char) * ft_strlen((char*)s) + 1)))
			return (NULL);
		while (s[i])
		{
			str[i] = (char)(*f)(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
