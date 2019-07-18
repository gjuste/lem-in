/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 23:59:10 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/18 13:56:26 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room	*set_room(void)
{
	t_room	*new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	new->name = NULL;
	new->x = 0;
	new->y = 0;
	new->links = NULL;
	new->next = NULL;
	return (new);
}

static t_room	*creat_room(t_lem *stt)
{
	t_room	*r;
	t_room	*new;

	if (!(new = set_room()))
		return (NULL);
	if (!stt->r)
	{
		stt->r = new;
		return (new);
	}
	r = stt->r;
	while (r->next)
		r = r->next;
	r->next = new;
	return (new);
}

static int		get_name(t_room *tmp, char *line)
{
	int		i;
	
	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	if (!(tmp->name = ft_strndup(line, i)))
		return (-1);
	return (i + 1);
}

int				room_fmt(t_lem *stt, char *line)
{
	t_room	*tmp;
	int		i;
	int		ret;

	if (!line || line[0] == 'L' || !ft_strstr(line, " "))
		return (-1);
	if (!(tmp = creat_room(stt)))
		return (-1);
	if ((i = get_name(tmp, line)) == -1)
		return (-1);
	ret = i;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	tmp->x = ft_atoi(&line[ret]);
	ret -= i;
	if (!line[i] || line[i] != ' ' || ret == 0)
		return (-1);
	ret = ++i;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	tmp->y = ft_atoi(&line[ret]);
	ret -= i;
	// ft_printf("ok | %s | %d | %d\n\n", line, ret, ret && !line[i] ? 1 : 0);
	return (ret && !line[i] && tmp->x >= 0 && tmp->y >= 0 ? 0 : -1);
}
