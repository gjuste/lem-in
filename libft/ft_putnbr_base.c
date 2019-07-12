/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:26:22 by jpelleti          #+#    #+#             */
/*   Updated: 2019/05/17 13:35:31 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long n, int base, int opt)
{
	char c;

	c = (opt == 0 ? 'a' : 'A');
	if (n - 1 == 9223372036854775807)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (n < 0)
		n = -n;
	if (n >= base)
	{
		ft_putnbr_base(n / base, base, opt);
		ft_putchar(n % base <= 9 ? n % base + '0' : n % base + c - 10);
	}
	if (n < base)
		ft_putchar(n % 10 + 48);
}
