/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_misc_num2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:45:53 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/04 14:23:56 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int	hex_conv_misc(t_ptf *stt, va_list ap)
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
	stt->arglen = ft_unsigned_nblen(i, 16);
	stt->w += !i && !stt->prec ? 0 : stt->arglen;
	stt->field = stt->opt & ZER && stt->prec == -1 && !(stt->opt & MNS)
		? '0' : ' ';
	if (stt->prec == -1)
		stt->prec = ft_unsigned_nblen(i, 16);
	return (i);
}

long double				f_conv_misc(t_ptf *stt, va_list ap)
{
	long double				i;

	if (stt->opt & LNG)
		i = (long double)va_arg(ap, long double);
	else
		i = va_arg(ap, double);
	return (i);
}

void					f_prec(char *str, int i)
{
	if (str[i] == '.' && str[i + 1] >= '5')
		i++;
	if (str[i] >= '5' && str[i - 1] != '.')
	{
		str[i - 1] += 1;
		if (str[i - 1] > '9')
			f_prec(str, i - 1);
	}
	else if (str[i - 1] == '.')
	{
		str[i - 2]++;
		if (str[i - 2] > '9')
			f_prec(str, i - 2);
	}
	while (str[i])
	{
		if (str[i] == ':')
			str[i] = '0';
		i++;
	}
}

void					unblank_offset(char *str, int offset)
{
	int j;

	j = 0;
	while (j < offset)
	{
		if (str[j] == 0)
			str[j] = '0';
		j++;
	}
}

int						check_float(t_ptf *stt, t_f_bit u)
{
	char	*str;
	int		n;

	n = 0;
	if (u.s.exponent == 2047)
	{
		str = u.s.mantisse == 0 ? "inf" : "nan";
		n = u.s.mantisse == 0 && u.s.sign ? 1 : 0;
		if (!(stt->opt & MNS))
			place_field(stt, 3 + (n ? 1 : 0));
		if (n)
			write_count("-", stt, -1);
		write_count(str, stt, -1);
		if (stt->opt & MNS)
			place_field(stt, 3 + (n ? 1 : 0));
		return (1);
	}
	else if (u.s.exponent == 0)
	{
		if (u.s.mantisse == 0)
			ft_print_float(stt, u, "0.", 1);
		return (1);
	}
	return (0);
}
