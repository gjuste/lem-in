/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:06:36 by jpelleti          #+#    #+#             */
/*   Updated: 2019/05/07 11:46:46 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_power(unsigned long long nb, int pow)
{
	unsigned long long	i;
	int					cpt;

	cpt = 1;
	i = nb;
	if (pow == 0)
		return (1);
	while (cpt < pow)
	{
		i *= nb;
		cpt++;
	}
	return (i);
}
