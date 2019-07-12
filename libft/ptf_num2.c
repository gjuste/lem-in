/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_num2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:41 by jpelleti          #+#    #+#             */
/*   Updated: 2019/05/22 09:28:26 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_low_conv(t_ptf *stt, va_list ap)
{
	unsigned long long int	i;
	int						cpt;
	int						len;

	i = hex_conv_misc(stt, ap);
	len = stt->arglen;
	cpt = stt->prec > len ? stt->prec : len;
	cpt += stt->opt & HST ? 2 : 0;
	if (stt->opt & HST && i != 0 && stt->field == '0')
		write_count("0x", stt, 2);
	if (!(stt->opt & MNS))
		place_field(stt, cpt - (!i && !stt->prec));
	if (stt->opt & HST && i != 0 && stt->field != '0')
		write_count("0x", stt, 2);
	while (len < stt->prec)
	{
		write_count("0", stt, 1);
		len++;
	}
	if (i != 0 || stt->prec != 0)
		ft_putnbr_unsigned_base(i, 16, 0);
	if ((stt->opt & MNS))
		place_field(stt, cpt - (!i && !stt->prec));
}

void	hex_upp_conv(t_ptf *stt, va_list ap)
{
	unsigned long long int	i;
	int						cpt;
	int						len;

	i = hex_conv_misc(stt, ap);
	len = stt->arglen;
	cpt = stt->prec > len ? stt->prec : len;
	cpt += stt->opt & HST ? 2 : 0;
	if (!(stt->opt & MNS))
		place_field(stt, cpt - (!i && !stt->prec));
	if (stt->opt & HST && i != 0)
		write_count("0X", stt, 2);
	while (len < stt->prec)
	{
		write_count("0", stt, 1);
		len++;
	}
	if (i != 0 || stt->prec != 0)
		ft_putnbr_unsigned_base(i, 16, 1);
	if ((stt->opt & MNS))
		place_field(stt, cpt - (!i && !stt->prec));
}

void	ft_print_float(t_ptf *stt, t_f_bit u, char *str, int i)
{
	int		len;
	int		cpt;
	int		save;
	int		n;

	n = u.s.sign ? 1 : 0;
	cpt = stt->prec >= 0 ? stt->prec : 6;
	cpt += cpt ? 1 : 0;
	cpt += stt->opt & HST && !stt->prec ? 1 : 0;
	len = ft_strlen(str);
	if (!(stt->opt & MNS))
		place_field(stt, cpt + i + (n ? 1 : 0));
	if (n)
		write_count("-", stt, -1);
	if (len > i + cpt)
		f_prec(str, i + cpt);
	write_count(str, stt, i + cpt);
	save = i;
	i += cpt - len;
	while (i-- > 0 && str[0] >= '0' && str[0] <= '9')
		write_count("0", stt, -1);
	if ((stt->opt & MNS))
		place_field(stt, cpt + save + (n ? 1 : 0) + (i > 0 ? i : 0));
}

void	f_conv(t_ptf *stt, va_list ap)
{
	t_f_bit	u;
	char	str[5000];
	int		i;

	ft_bzero(str, 5000);
	u.nb = f_conv_misc(stt, ap);
	if (check_float(stt, u))
		return ;
	ft_calc_ent(str, u);
	ft_strcrev(str);
	i = ft_strlen(str);
	str[i] = '.';
	ft_calc_dec(&str[i + 1], u);
	ft_print_float(stt, u, str, i);
}

void	find_num2(t_ptf *stt, va_list ap)
{
	if (stt->c == 'x')
		hex_low_conv(stt, ap);
	if (stt->c == 'X')
		hex_upp_conv(stt, ap);
	if (stt->c == 'f')
		f_conv(stt, ap);
}
