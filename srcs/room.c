/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:59:10 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/14 00:01:44 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		room_fmt(char *line)
{
	int		i;
	int		ret;

	if (!line || line[0] == 'L')
		return (0);
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	ret = ++i;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	ret -= i;
	if (!line[i] || line[i] != ' ' || ret == 0)
		return(0);
	ret = ++i;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	ret -= i;
	return (ret ? 1 : 0);
}
