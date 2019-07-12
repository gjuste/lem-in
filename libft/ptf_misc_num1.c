/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_misc_num1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:08:37 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/04 14:23:50 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			d_conv_misc(t_ptf *stt, va_list ap)
{
	long long int			i;

	if (stt->opt & LLL)
		i = (long int)va_arg(ap, long int);
	else if (stt->opt & LER)
		i = (long long int)va_arg(ap, long long int);
	else if (stt->opt & HHH)
		i = (short int)va_arg(ap, int);
	else if (stt->opt & HER)
		i = (signed char)va_arg(ap, int);
	else
		i = va_arg(ap, int);
	stt->arglen = ft_intlen(i, 10);
	stt->w += !i && !stt->prec ? 0 : stt->arglen;
	stt->field = stt->opt & ZER && stt->prec == -1 && !(stt->opt & MNS)
		? '0' : ' ';
	return (i);
}

unsigned long long int	u_conv_misc(t_ptf *stt, va_list ap)
{
	unsigned long long int	i;

	if (stt->opt & LLL)
		i = (unsigned long int)va_arg(ap, unsigned long int);
	else if (stt->opt & LER)
		i = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (stt->opt & HHH)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else if (stt->opt & HER)
		i = (unsigned char)va_arg(ap, unsigned int);
	else
		i = va_arg(ap, unsigned int);
	stt->arglen = ft_unsigned_nblen(i, 10);
	stt->w += !i && !stt->prec ? 0 : stt->arglen;
	stt->field = stt->opt & ZER && stt->prec == -1 && !(stt->opt & MNS)
		? '0' : ' ';
	if (stt->prec == -1)
		stt->prec = ft_unsigned_nblen(i, 10);
	return (i);
}

long long int			o_conv_misc(t_ptf *stt, va_list ap)
{
	long long int			i;

	if (stt->opt & LLL)
		i = (unsigned long int)va_arg(ap, unsigned long int);
	else if (stt->opt & LER)
		i = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (stt->opt & HHH)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else if (stt->opt & HER)
		i = (unsigned char)va_arg(ap, unsigned int);
	else
		i = va_arg(ap, unsigned int);
	stt->arglen = ft_unsigned_nblen(i, 8);
	stt->w += !i && !stt->prec ? 0 : stt->arglen;
	stt->field = stt->opt & ZER && stt->prec == -1 && !(stt->opt & MNS)
		? '0' : ' ';
	if (stt->prec == -1)
		stt->prec = ft_unsigned_nblen(i, 8);
	return (i);
}

void					ft_write_sign(int n, t_ptf *stt)
{
	if (n && stt->field == '0')
		write(1, "-", 1);
	else if (stt->opt & PLS && !n && stt->field == '0')
		write_count("+", stt, 1);
	else if (stt->opt & PLS && !n && stt->field != '0')
		write_count("+", stt, 1);
	else if (n && stt->field != '0')
		write(1, "-", 1);
	else if (stt->opt & SPC && !(stt->opt & PLS))
		write_count(" ", stt, 1);
}
