/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 00:25:40 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/16 23:51:10 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*check_name(t_lem *stt, char *name)
{
	t_room	*r;

	r = stt->r;
	while (r)
	{
		if (!ft_strcmp(r->name, name))
			return (r);
		r = r->next;
	}
	return (NULL);
}

static int		add_pipe(t_room *r, t_room *n)
{
	t_links	*tmp;
	t_links	*new;

	tmp = r->links;
	if (!(new = (t_links*)malloc(sizeof(t_links))))
		return (-2);
	new->i = 0;
	new->next = NULL;
	new->r = n;
	if (!tmp)
		r->links = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

static int		set_pipe(t_lem *stt, char *n1, char *n2)
{
	t_room	*r1;
	t_room	*r2;
	t_links	*tmp;

	r1 = NULL;
	r2 = NULL;
	if ((r1 = check_name(stt, n1))
		&& (r2 = check_name(stt, n2)))
	{
		tmp = r1->links;
		while (tmp)
		{
			if (tmp->r == r2)
				return (0);
			tmp = tmp->next;
		}
		if (add_pipe(r1, r2) < 0)
			return (-2);
		if (add_pipe(r2, r1) < 0)
			return (-2);
		return (0);
	}
	return (-2);
}

static int		pipe_fmt(t_lem *stt, char *line)
{
	int		i;
	char	*n1;
	char	*n2;

	if (!line || line[0] == 'L')
		return (-1);
	i = 0;
	while (line[i] && line[i] != '-' && line[i] != ' ')
		i++;
	if (line[i] != '-')
		return (-1);
	n1 = ft_strndup(line, i);
	i++;
	n2 = ft_strdup(&line[i]);
	if (!n1 || !n2 || !ft_strcmp(n1, n2))
		return (-2);
	else
		i = set_pipe(stt, n1, n2);
	ft_strdel(&n1);
	ft_strdel(&n2);
	return (i < 0 ? i : 0);
}

int				get_pipe(t_lem *stt, char *l)
{
	char	*line;
	int		ret;
	int		i;

	i = pipe_fmt(stt, l);
	if (i == -1)
		i = -2;
	while (!i && (ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == '#' && line[1] == '#')
			i = check_cmd(stt, line);
		if (!i && line[0] != '#')
			i = pipe_fmt(stt, line);
		if (!(line = join(stt, &stt->lstr, line)))
			return (-1);
	}
	return (ret < 0 || i < 0 ? i : 0);
}
