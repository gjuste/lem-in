/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nblen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:39:58 by jpelleti          #+#    #+#             */
/*   Updated: 2019/04/16 15:41:42 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unsigned_nblen(unsigned long long n, int base)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
