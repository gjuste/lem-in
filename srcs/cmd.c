/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:54:50 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/14 00:01:11 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static char	*get_cmd(t_lem *stt, char *l_tmp)
{
	int		i;
	int		ret;
	char	*name;

	name = NULL;
	if ((ret = room_fmt(l_tmp)))
	{
		i = 0;
		while (l_tmp[i] != ' ')
			i++;
		name = ft_strndup(l_tmp, i);
	}
	if (ret == 0 || !name)
	{
		ft_strdel(&l_tmp);
		ft_error(stt, !i ? 1 : 3);
	}
	return (name);
}

void		check_cmd(t_lem *stt, char *line)
{
	char	**cmd;
	char	*l_tmp;
	int		ret;
	int		check;

	if (ft_strstr(line, "##start"))
		cmd = &(stt->start);
	else if (ft_strstr(line, "##end"))
		cmd = &(stt->end);
	else
		return;
	check = 0;
	while (!check && (ret = get_next_line(0, &l_tmp)) > 0)
	{
		if (l_tmp && l_tmp[0] != '#')
		{
			*cmd = get_cmd(stt, l_tmp);
			check++;
		}
		ft_strdel(&l_tmp);
	}
	// ft_printf("\033[32m%s %s\033[0m\n", stt->start, stt->end);
	if (ret <= 0)
		ft_error(stt, ret < 0 ? 4 : 3);
}
