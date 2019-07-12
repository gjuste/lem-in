/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:14:31 by jpelleti          #+#    #+#             */
/*   Updated: 2019/06/04 14:34:46 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_convert(const char *fmt, t_ptf *stt)
{
	int error;

	error = 0;
	while (*fmt == 'l' || *fmt == 'h' || *fmt == 'L')
	{
		if (*fmt == 'L')
			stt->opt & LNG ? error = 1 : (stt->opt += LNG);
		if (*fmt == 'l')
			stt->opt & LER ? error = 1 : (stt->opt += LLL);
		if (*fmt == 'h')
			stt->opt & HER ? error = 1 : (stt->opt += HHH);
		if ((stt->opt & LLL && stt->opt & HHH) || (stt->opt & LLL
				&& stt->opt & LNG) || (stt->opt & LNG && stt->opt & HHH)
			|| (stt->opt & LLL && stt->opt & HER) || (stt->opt & LER
				&& stt->opt & LNG) || (stt->opt & LNG && stt->opt & HER)
			|| (stt->opt & LER && stt->opt & HHH) || error == 1)
		{
			stt->i--;
			return (-1);
		}
		fmt++;
		stt->i++;
	}
	return (0);
}

int		parse_handle(const char *fmt, t_ptf *stt)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (*fmt == 'd' || *fmt == 's' || *fmt == 'c' || *fmt == 'i'
			|| *fmt == 'p' || *fmt == 'o' || *fmt == 'u' || *fmt == 'x'
			|| *fmt == 'X' || *fmt == 'f' || *fmt == '%' || *fmt == 'b')
		{
			stt->c = *fmt;
			return (0);
		}
		else if (*fmt != 'l' && *fmt != 'L' && *fmt != 'h')
			return (-1);
		i++;
		fmt++;
	}
	return (-1);
}

int		parse_opt(const char *c, t_ptf *stt)
{
	stt->opt = (*c == ' ' ? SPC | stt->opt : stt->opt);
	stt->opt = (*c == '+' ? PLS | stt->opt : stt->opt);
	stt->opt = (*c == '-' ? MNS | stt->opt : stt->opt);
	stt->opt = (*c == '0' ? ZER | stt->opt : stt->opt);
	stt->opt = (*c == '#' ? HST | stt->opt : stt->opt);
	if ((*c != ' ' && *c != '+' && *c != '-' && *c != '0' && *c != '#'
			&& (*c > '0' || *c <= '9')))
		return (1);
	return (0);
}

void	set_prec(const char *fmt, t_ptf *stt)
{
	stt->prec = ft_atoi(fmt);
	stt->i++;
}

int		ptf_parser(const char *fmt, t_ptf *stt)
{
	while (*fmt == ' ' || *fmt == '+' || *fmt == '-' || *fmt == '#'
		|| (*fmt >= '0' && *fmt <= '9') || *fmt == '.')
	{
		while (parse_opt(fmt, stt) == 0)
		{
			stt->i++;
			fmt++;
		}
		if (parse_opt(fmt, stt) == -1)
			return (-1);
		if (*fmt >= '1' && *fmt <= '9')
			stt->lrg_cmp = ft_atoi(fmt);
		if (*fmt == '.')
			set_prec(++fmt, stt);
		while (*fmt >= '0' && *fmt <= '9')
		{
			fmt++;
			stt->i++;
		}
	}
	if (parse_convert(fmt, stt) == -1 || parse_handle(fmt, stt) == -1)
		return (-1);
	return (0);
}
