/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:08:36 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/16 21:58:39 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	set_nb_ants(t_lem *stt, char *line)
{
	int		i;

	i = 0;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (!line[i])
		stt->ants = ft_atoi(line);
	else
		return (-2);
	return (-1);
}

static int	get_nb_ants(t_lem *stt)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	i = 0;
	while (!i && (ret = get_next_line(0, &line)))
	{
		i++;
		if (!line)
			return (-1);
		ft_printf("%s\n", line);
		if (line[0] == '#' && line[1] != '#')
			i = 0;
		else
			i = set_nb_ants(stt, line);
		ft_strdel(&line);
	}
	if (ret <= 0 || i == -2 || stt->ants <= 0)
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
