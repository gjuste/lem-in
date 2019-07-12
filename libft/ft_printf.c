/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:14:13 by jpelleti          #+#    #+#             */
/*   Updated: 2019/05/25 22:22:23 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_count(const char *fmt, t_ptf *stt, int len)
{
	int		len_str;

	len_str = ft_strlen(fmt);
	if (fmt[0] == 0)
		len_str = 1;
	if (len == -1 || len > len_str)
	{
		write(1, fmt, len_str);
		stt->w += len_str;
	}
	else
	{
		write(1, fmt, len);
		stt->w += len;
	}
}

int		set_parse(const char *fmt, t_ptf *stt)
{
	ft_bzero_stt(stt);
	if (ptf_parser(fmt, stt) < 0)
		return (-1);
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_ptf	stt;

	va_start(ap, fmt);
	stt.w = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (set_parse(++fmt, &stt) == 0)
				find_fct(&stt, ap);
			fmt += stt.i;
		}
		else
			write_count(fmt, &stt, 1);
		fmt++;
	}
	va_end(ap);
	return (stt.w);
}
