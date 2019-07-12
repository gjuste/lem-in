/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:55:44 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/12 10:12:56 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (s != NULL)
	{
		if (!(str = malloc(sizeof(char) * ft_strlen((char*)s) + 1)))
			return (NULL);
		while (s[i])
		{
			str[i] = (char)(*f)(s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
