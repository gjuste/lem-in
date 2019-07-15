/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:08:36 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/15 03:53:18 by gjuste           ###   ########.fr       */
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
	int		j;
	t_room	*tmp;

	get_nb_ants(stt);
	line = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!line)
			break;
		i = 0;
		if (line[0] == '#' && line[1] == '#')
			check_cmd(stt, line);
		if (line[0] != '#' && !(i = room_fmt(stt, line)))
			i = get_pipe(stt, line);		
		ft_strdel(&line);
	}
	tmp = stt->r;
	while (tmp->next) //debug affichage chaque maillon
	{
		j = 0;
		ft_printf("\033[36m%-3s\033[0m | %3d / %3d\n", tmp->name, tmp->x, tmp->y);
		while (tmp->pipe[j])
		{
			ft_printf("lol\n");
			ft_printf("\t\033[33m%s\033[0m\n", tmp->pipe[j]);
			j++;
		}
		tmp = tmp->next;
	}
	if (ret <= 0 && !i)
		ft_error(stt, ret < 0 ? 4 : 3);
}
