/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:08:36 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/16 16:46:34 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	get_nb_ants(t_lem *stt)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(0, &line);
	if (line)
	{
		stt->ants = ft_atoi(line);
		ft_strdel(&line);
	}
	if (stt->ants <= 0)
		ret = -2;
	if (ret <= 0)
		return (-1);
	return (0);
}

int		parser(t_lem *stt)
{
	char	*line;
	int		ret;
	int		i;

	i = get_nb_ants(stt);
	line = NULL;
	while (!i && (ret = get_next_line(0, &line)) > 0)
	{
		if (!line)
			return (-1);
		ft_printf("%s\n", line);
		if (line[0] == '#' && line[1] == '#')
			i = check_cmd(stt, line);
		if (line[0] != '#' && (i = room_fmt(stt, line) == -1))
			i = get_pipe(stt, line);
		ft_strdel(&line);
	}
	return (ret < 0 || !stt->r || !stt->start
		|| !stt->end || i == -1 ? -1 : 0);
}
