/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 00:25:40 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/16 16:49:58 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room	*check_name(t_lem *stt, char* name)
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
	t_room	**tmp;
	int		i;

	i = 0;
	while (r->links && r->links[i])
		i++;
	if (!(tmp = (t_room**)malloc(sizeof(t_room*) * (i + 2))))
		return (-1);
	tmp[i + 1] = NULL;
	tmp[i--] = n;
	while (i >= 0)
	{
		tmp[i] = r->links[i];
		i--;
	}
	if (r->links)
		free(r->links);
	r->links = tmp;
	return (0);
}

static int		set_pipe(t_lem *stt, char *n1, char *n2)
{
	t_room	*r1;
	t_room	*r2;
	int		i;

	r1 = NULL;
	r2 = NULL;
	i = 0;
	if ((r1 = check_name(stt, n1)) && (r2 = check_name(stt, n2)))
	{
		while (r1->links && r1->links[i])
		{
			if (r1->links[i] == r2)
				return (0);
			i++;
		}
		if (add_pipe(r1, r2) == -1)
			return (-1);
		if (add_pipe(r2, r1) == -1)
			return (-1);
		return (0);
	}
	return (-1);
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
	if (n1 == n2 || !n1 || !n2)
		return (-1);
	else
		i = set_pipe(stt, n1, n2);
	ft_strdel(&n1);
	ft_strdel(&n2);
	return (i == -1 ? -1 : 0);
}

int				get_pipe(t_lem *stt, char *line)
{
	int		ret;
	int		i;

	i = pipe_fmt(stt, line);
	// ft_strdel(&line);
	while (!i && (ret = get_next_line(0, &line)) > 0)
	{
		if (!line)
			return (-1);
		i = pipe_fmt(stt, line);
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	return (i == -1 ? -1 : 0);
}
