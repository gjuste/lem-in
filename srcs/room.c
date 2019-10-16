/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:59:10 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/16 13:44:15 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*creat_room(void)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	new->name = NULL;
	new->x = 0;
	new->y = 0;
	new->ants = 0;
	new->marque = 0;
	new->bfs = 0;
	new->done = 0;
	new->nb_r = 0;
	new->links = NULL;
	new->next = NULL;
	new->parent = NULL;
	return (new);
}

static int		get_room_in(t_lem *stt, t_room *new)
{
	t_room	*r;
	int		ret;

	ret = 0;
	if (!stt->r)
	{
		stt->r = new;
		return (0);
	}
	r = stt->r;
	while (r->next)
	{
		if (!ret)
			if (!ft_strcmp(r->name, new->name)
				|| (r->x == new->x && r->y == new->y))
				ret = -1;
		r = r->next;
	}
	if (!ret)
		if (!ft_strcmp(r->name, new->name)
			|| (r->x == new->x && r->y == new->y))
			ret = -1;
	r->next = new;
	return (ret);
}

static int		get_name(t_room *tmp, char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '-')
		i++;
	if (!(tmp->name = ft_strndup(line, i)))
		return (-1);
	return (i + 1);
}

static int		get_infos(char *line, t_room *tmp)
{
	int		i;
	int		ret;

	if ((i = get_name(tmp, line)) == -1)
		return (-1);
	ret = i;
	while (line[i] && (ft_isdigit(line[i]) || (ret == i && line[ret] == '-')))
		i++;
	tmp->x = ft_atoi(&line[ret]);
	ret -= i;
	if (!line[i] || line[i] != ' ' || ret == 0)
		return (-1);
	ret = ++i;
	while (line[i] && (ft_isdigit(line[i]) || (ret == i && line[ret] == '-')))
		i++;
	tmp->y = ft_atoi(&line[ret]);
	ret -= i;
	return (ret && !line[i] ? 0 : -1);
}

int				room_fmt(t_lem *stt, char *line)
{
	t_room	*tmp;

	if (!line || line[0] == 'L' || !ft_strstr(line, " "))
		return (-1);
	if (!(tmp = creat_room()))
		return (-1);
	if (get_infos(line, tmp) == -1)
	{
		if (tmp->name)
			ft_strdel(&(tmp->name));
		free(tmp);
		return (-1);
	}
	if (get_room_in(stt, tmp) == -1)
		return (-1);
	return (0);
}
