/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:08:36 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/14 00:26:33 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	get_nb_ants(t_lem *stt)
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
		ft_error(stt, ret < 0 ? 2 : 3);
}

void		parser(t_lem *stt)
{
	char	*line;
	int		ret;
	int		i;

	get_nb_ants(stt);
	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!line)
			break;
		i = 0;
		if (line[0] == '#' && line[1] == '#')
			check_cmd(stt, line);
		if ((line[0] != '#' && !room_fmt(line)) && !(i = pipe_fmt(line)) && !ret)
		{
			ft_strdel(&line);
			ft_error(stt, 3);
		}
		else if (i)
			i = get_pipe(stt, line);			
		ft_strdel(&line);
	}
	if (ret <= 0 && !i)
		ft_error(stt, ret < 0 ? 4 : 3);
}
