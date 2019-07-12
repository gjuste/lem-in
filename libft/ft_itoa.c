/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:27:44 by jpelleti          #+#    #+#             */
/*   Updated: 2019/04/16 13:09:38 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*rdu;
	long	stock;

	stock = n;
	i = ft_intlen(n, 10) - 1;
	if (!(rdu = malloc(sizeof(char) * ft_intlen(n, 10) + 1)))
		return (NULL);
	if (stock < 0)
	{
		rdu[0] = '-';
		stock = -stock;
	}
	if (n == 0)
		rdu[i] = '0';
	while (stock != 0)
	{
		rdu[i] = (stock % 10) + 48;
		stock = stock / 10;
		i--;
	}
	rdu[ft_intlen(n, 10)] = '\0';
	return (rdu);
}
