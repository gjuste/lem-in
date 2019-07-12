/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_misc_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:55:32 by jpelleti          #+#    #+#             */
/*   Updated: 2019/06/04 14:23:06 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_power(char *str, int pow)
{
	int		i;
	int		j;

	ft_bzero(str, 5000);
	str[0] = '1';
	i = 0;
	while (i < pow)
	{
		j = ft_strlen(str) - 1;
		while (j >= 0)
		{
			if (str[j] < 10)
				str[j] += '0';
			str[j] = ((str[j] - '0') * 2) + '0';
			if (str[j] > '9')
			{
				str[j + 1] += str[j + 1] == 0 ? '1' : 1;
				str[j] -= 10;
			}
			j--;
		}
		i++;
	}
	return (str);
}

char	*ft_str_power_dec(char *str, int pow)
{
	int		i;
	int		j;

	ft_bzero(str, 5000);
	str[0] = '1';
	i = 0;
	while (i < pow)
	{
		j = ft_strlen(str) - 1;
		while (j >= 0)
		{
			if (str[j] < 10)
				str[j] += '0';
			str[j] = ((str[j] - '0') * 5) + '0';
			if (str[j] > '9')
			{
				str[j + 1] += str[j + 1] == 0 ? (str[j] - 48) / 10 + '0'
				: (str[j] - 48) / 10;
				str[j] -= (str[j] - 48) / 10 * 10;
			}
			j--;
		}
		i++;
	}
	return (ft_strcrev(str));
}

void	ft_add_string(char *str, char *add)
{
	int i;

	i = 0;
	while (str[i] || add[i])
	{
		if (str[i] < 10)
			str[i] += '0';
		if (add[i] >= '0')
			str[i] += add[i] - '0';
		if (str[i] > '9')
		{
			str[i + 1] += str[i + 1] == 0 ? '1' : 1;
			str[i] -= 10;
		}
		i++;
	}
}

void	ft_add_string_dec(char *str, char *add, int offset)
{
	int i;
	int j;
	int q;

	i = offset;
	j = 0;
	while (str[i] || add[j])
	{
		q = 0;
		if (str[i] < 10)
			str[i] += '0';
		if (add[j] >= '0')
			str[i] += add[j] - '0';
		while (str[i - q] > '9')
		{
			str[i - q - 1] += str[i - q - 1] == 0 ? '1' : 1;
			str[i - q] -= 10;
			q++;
		}
		i++;
		j++;
	}
}

int		ft_offset(int i)
{
	int		offset;
	int		j;
	char	add[5000];

	ft_bzero(add, 5000);
	j = 0;
	offset = 0;
	while (i < j)
	{
		if (ft_strlen(ft_str_power_dec(add, -i))
			== ft_strlen(ft_str_power_dec(add, -i + 1)))
			offset++;
		i++;
	}
	return (offset);
}
