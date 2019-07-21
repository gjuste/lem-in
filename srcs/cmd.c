/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:54:50 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/20 16:31:30 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room	*get_cmd(t_lem **stt, char *l_tmp)
{
	int		ret;
	t_room	*r;

	r = NULL;
	if (!(ret = room_fmt(*stt, l_tmp)))
	{
		r = (*stt)->r;
		while (r->next)
			r = r->next;
	}
	if (ret == -1 || !r)
		return (NULL);
	return (r);
}

int		check_cmd(t_lem *stt, char *line)
{
	t_room	**cmd;
	char	*l_tmp;
	int		ret;
	int		check;

	if (!ft_strcmp(line, "##start"))
		cmd = &(stt->start);
	else if (!ft_strcmp(line, "##end"))
		cmd = &(stt->end);
	else
		return (0);
	check = 0;
	while (!check && (ret = get_next_line(0, &l_tmp)) > 0)
	{
		if (l_tmp && l_tmp[0] != '#')
		{
			if ((*cmd = get_cmd(&stt, l_tmp)) == NULL)
				ret = -1;
			check++;
		}
		ft_printf("%s\n", l_tmp);
		ft_strdel(&l_tmp);
	}
	return (ret <= 0 ? -1 : 0);
}
