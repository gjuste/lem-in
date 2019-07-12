/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:41:58 by jpelleti          #+#    #+#             */
/*   Updated: 2018/11/12 13:45:36 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcrev(char *str)
{
	int		len;
	int		j;
	char	swpstr;
	char	*chaine;

	len = 0;
	j = 0;
	chaine = str;
	while (chaine[len] != '\0')
	{
		len++;
	}
	while (len > j)
	{
		len--;
		swpstr = chaine[len];
		chaine[len] = str[j];
		str[j] = swpstr;
		j++;
	}
	return (str);
}
