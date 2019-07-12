/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_num1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:47:11 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/04 14:34:28 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_conv(t_ptf *stt, va_list ap)
{
	long long int	i;
	int				cpt;
	int				len;
	int				n;

	i = d_conv_misc(stt, ap);
	n = i < 0;
	len = stt->arglen;
	cpt = stt->prec > len ? stt->prec : len;
	cpt += stt->opt & SPC ? 1 : 0;
	if (stt->field == '0')
		ft_write_sign(n, stt);
	if (!(stt->opt & MNS))
		place_field(stt, cpt + (stt->opt & PLS || n) - (!i && !stt->prec)
			- (n && stt->prec < len));
	if (stt->field != '0')
		ft_write_sign(n, stt);
	while (len++ < stt->prec + n)
		write_count("0", stt, 1);
	if (i != 0 || stt->prec != 0)
		ft_putnbr_base(i < 0 ? -i : i, 10, 0);
	if ((stt->opt & MNS))
		place_field(stt, cpt + (stt->opt & PLS || n) - (!i && !stt->prec)
			- (n && stt->prec < stt->arglen));
}

void	u_conv(t_ptf *stt, va_list ap)
{
	unsigned long long int	i;
	int						cpt;
	int						len;

	i = u_conv_misc(stt, ap);
	len = stt->arglen;
	cpt = stt->prec > len ? stt->prec : len;
	if (!(stt->opt & MNS))
		place_field(stt, cpt - (!i && !stt->prec));
	while (len < stt->prec)
	{
		write_count("0", stt, 1);
		len++;
	}
	if (i != 0 || stt->prec != 0)
		ft_putnbr_unsigned_base(i, 10, 0);
	if ((stt->opt & MNS))
		place_field(stt, cpt - (!i && !stt->prec));
}

void	o_conv(t_ptf *stt, va_list ap)
{
	long long int	i;
	int				cpt;
	int				len;

	i = o_conv_misc(stt, ap);
	len = stt->arglen;
	cpt = stt->prec > len ? stt->prec : len;
	cpt += stt->prec <= stt->arglen && stt->opt & HST ? 1 : 0;
	if (!(stt->opt & MNS))
		place_field(stt, cpt - (!i && !stt->prec));
	if (stt->opt & HST && (i != 0 || stt->prec == 0))
	{
		write_count("0", stt, 1);
		len++;
	}
	while (len < stt->prec)
	{
		write_count("0", stt, 1);
		len++;
	}
	if (i != 0 || stt->prec != 0)
		ft_putnbr_unsigned_base(i, 8, 1);
	if ((stt->opt & MNS))
		place_field(stt, cpt - (!i && !stt->prec));
}

void	b_conv(t_ptf *stt, va_list ap)
{
	unsigned int	i;
	int				cpt;
	int				len;

	i = va_arg(ap, unsigned int);
	len = ft_intlen(i, 2);
	cpt = stt->prec != -1 ? stt->prec : len;
	stt->w += len;
	if (!(stt->opt & MNS))
		place_field(stt, cpt);
	while (len++ < cpt)
		write_count("0", stt, -1);
	ft_putnbr_unsigned_base(i, 2, 0);
	if (stt->opt & MNS)
		place_field(stt, cpt);
}

void	find_num1(t_ptf *stt, va_list ap)
{
	if (stt->c == 'i' || stt->c == 'd')
		d_conv(stt, ap);
	if (stt->c == 'u')
		u_conv(stt, ap);
	if (stt->c == 'o')
		o_conv(stt, ap);
	if (stt->c == 'b')
		b_conv(stt, ap);
}
