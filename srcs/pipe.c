/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 00:25:40 by gjuste            #+#    #+#             */
/*   Updated: 2019/07/15 03:36:06 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_room	*check_name(t_lem *stt, char* name)
{
	t_room	*r;

	r = stt->r;
	while (r->next)
	{
		if (ft_strstr(r->name, name))
			return (r);
		r = r->next;
	}
	return (NULL);
}

static void		add_pipe(t_room *r, char *n) // pas de reele protection faite
{
	char	**tmp;
	int		i;

	i = 0;
	while (r->pipe && r->pipe[i])
		i++;
	if (!(tmp = (char**)malloc(sizeof(char *) * (i + (!r->pipe ? 1 : 0) + 1))))
		return ;
	ft_printf("%d\n", i);
	tmp[i + 1] = NULL;
	if (!(tmp[i] = ft_strdup(n)))
		return ;
	while (i > 0)
	{
		i--;
		if (!(tmp[i] = ft_strdup(r->pipe[i])))
			return ;
		ft_strdel(&(r->pipe[i]));
	}
	if (r->pipe)
		free(r->pipe);
	r->pipe = tmp;
}

static void		set_pipe(t_lem *stt, char *n1, char *n2)
{
	t_room	*r1;
	t_room	*r2;

	r1 = NULL;
	r2 = NULL;
	if ((r1 = check_name(stt, n1)) && (r2 = check_name(stt, n2)))
	{
		add_pipe(r1, n2);
		add_pipe(r2, n1);
	}
}

static void		pipe_fmt(t_lem *stt, char *line)
{
	int		i;
	char	*n1;
	char	*n2;

	if (!line || line[0] == 'L')
		return ;
	i = 0;
	while (line[i] && line[i] != '-' && line[i] != ' ')
		i++;
	if (line[i] == ' ')
		ft_error(stt, 5);
	n1 = ft_strndup(line, i);
	i++;
	n2 = ft_strdup(&line[i]);
	if (n1 == n2 || !n1 || !n2)
		ft_error(stt, 5);
	else
		set_pipe(stt, n1, n2);
}

int				get_pipe(t_lem *stt, char *line)
{
	int		ret;

	stt->start = stt->start;
	pipe_fmt(stt, line);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!line)
			break;
		pipe_fmt(stt, line);
		ft_strdel(&line);
	}
	return (1);
}
