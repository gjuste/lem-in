/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_misc_ptf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:43:13 by jpelleti          #+#    #+#             */
/*   Updated: 2019/05/22 09:28:05 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	place_field(t_ptf *stt, int i)
{
	while (i < stt->lrg_cmp)
	{
		write_count(&stt->field, stt, 1);
		i++;
	}
}

void	ft_bzero_stt(t_ptf *stt)
{
	stt->field = ' ';
	stt->opt = 0;
	stt->lrg_cmp = 0;
	stt->prec = -1;
	stt->c = 0;
	stt->f = 0;
	stt->i = 0;
	stt->arglen = 0;
}

void	ft_calc_ent(char *str, t_f_bit u)
{
	unsigned long long	l;
	char				add[5000];
	int					i;
	int					j;

	j = 52;
	i = u.s.exponent - 1023;
	if (i >= 0)
		ft_add_string(str, ft_str_power(add, i));
	l = 1;
	while (i >= 0 && i >= u.s.exponent - 1023 - 52)
	{
		if ((l << j) & u.s.mantisse)
			ft_add_string(str, ft_str_power(add, i));
		i--;
		j--;
	}
	if (str[0] == '\0')
		str[0] = '0';
}

void	ft_calc_dec(char *str, t_f_bit u)
{
	unsigned long long	l;
	char				add[5000];
	int					offset;
	int					i;
	int					j;

	i = u.s.exponent - 1023;
	offset = ft_offset(i);
	if (i < 0)
		ft_add_string_dec(str, ft_str_power_dec(add, -i), offset);
	while (i >= 0)
		i--;
	l = 1;
	j = 52 - (u.s.exponent - 1023 - i);
	while (i >= u.s.exponent - 1023 - 52)
	{
		ft_str_power_dec(add, -i);
		if ((l << j) & u.s.mantisse)
			ft_add_string_dec(str, add, offset);
		if (ft_strlen(add) == ft_strlen(ft_str_power_dec(add, -i + 1)))
			offset++;
		i--;
		j--;
	}
	unblank_offset(str, offset);
}
