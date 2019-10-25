/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:54:50 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/16 23:50:57 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*get_cmd_room(t_lem *stt, char *l_tmp)
{
	int		ret;
	t_room	*r;

	r = NULL;
	if (!(ret = room_fmt(stt, l_tmp)))
	{
		r = stt->r;
		while (r->next)
			r = r->next;
	}
	if (ret == -1 || !r)
		return (NULL);
	return (r);
}

static t_room	**get_cmd(t_lem *stt, char *line)
{
	t_room	**cmd;

	if (!ft_strcmp(line, "##start"))
		cmd = &(stt->start);
	else if (!ft_strcmp(line, "##end"))
		cmd = &(stt->end);
	else
		return (NULL);
	return (cmd);
}

int				check_cmd(t_lem *stt, char *line)
{
	t_room	**cmd;
	char	*l_tmp;
	int		ret;
	int		check;

	if (!(cmd = get_cmd(stt, line)))
		return (0);
	if (*cmd)
		return (-1);
	check = 0;
	while (!check && (ret = get_next_line(0, &l_tmp)) > 0)
	{
		if (!(l_tmp = join(stt, &(stt->lstr), l_tmp)))
			return (-1);
		if (l_tmp && l_tmp[0] != '#')
		{
			if ((*cmd = get_cmd_room(stt, l_tmp)) == NULL)
				ret = -1;
		}
		else if (l_tmp[0] == '#' && l_tmp[1] == '#')
			ret = -1;
		if (l_tmp[0] != '#' || (l_tmp[0] == '#' && l_tmp[1] == '#'))
			check++;
	}
	return (ret <= 0 ? -1 : 0);
}
