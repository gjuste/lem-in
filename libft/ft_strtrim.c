/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:48:33 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/15 15:33:02 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(s));
	j = ft_strlen((char*)s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (i == ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (j + i - 1))))
		return (NULL);
	if (s[i])
		str = ft_strsub(s, i, j - i + 1);
	return (str);
}
