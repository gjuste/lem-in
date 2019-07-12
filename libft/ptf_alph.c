/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_alph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:35:54 by gjuste            #+#    #+#             */
/*   Updated: 2019/06/04 14:22:30 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percent_conv(t_ptf *stt)
{
	int		i;

	stt->field = stt->opt & ZER && !(stt->opt & MNS) ? '0' : ' ';
	i = 1;
	if (!(stt->opt & MNS))
		place_field(stt, i);
	write_count("%", stt, 1);
	if (stt->opt & MNS)
		place_field(stt, i);
}

void	c_conv(t_ptf *stt, va_list ap)
{
	char	c;

	stt->field = stt->opt & ZER && !(stt->opt & MNS) ? '0' : ' ';
	c = va_arg(ap, int);
	if (!(stt->opt & MNS))
		place_field(stt, 1);
	write_count(&c, stt, 1);
	if (stt->opt & MNS)
		place_field(stt, 1);
}

void	s_conv(t_ptf *stt, va_list ap)
{
	char	*s;
	int		i;

	stt->field = stt->opt & ZER && !(stt->opt & MNS) ? '0' : ' ';
	s = va_arg(ap, char*);
	if (!s)
		s = "(null)";
	i = (int)ft_strlen(s) > stt->prec && stt->prec != -1 ?
		stt->prec : ft_strlen(s);
	if (!(stt->opt & MNS))
		place_field(stt, i);
	write_count(s, stt, i);
	if (stt->opt & MNS)
		place_field(stt, i);
}

void	p_conv(t_ptf *stt, va_list ap)
{
	unsigned int	ptr;
	int				i;

	ptr = va_arg(ap, unsigned int);
	i = ptr ? ft_unsigned_nblen(ptr, 16) + 4 : ft_unsigned_nblen(ptr, 16);
	if (!(stt->opt & MNS))
		place_field(stt, i + 2 + (stt->prec > i ? stt->prec - i : 0));
	write_count("0x", stt, 2);
	while (i < stt->prec)
	{
		write_count("0", stt, 1);
		i++;
	}
	if (ptr)
		write_count("7fff", stt, 4);
	if (ptr != 0 || stt->prec != 0)
		ft_putnbr_unsigned_base(ptr, 16, 0);
	stt->w += ptr != 0 || stt->prec != 0 ? ft_intlen(ptr, 16) : 0;
	if ((stt->opt & MNS))
		place_field(stt, i + 2);
}

int		find_alph(t_ptf *stt, va_list ap)
{
	if (stt->c == 'c')
		c_conv(stt, ap);
	if (stt->c == 's')
		s_conv(stt, ap);
	if (stt->c == 'p')
		p_conv(stt, ap);
	if (stt->c == '%')
		percent_conv(stt);
	return (0);
}
