/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:13:50 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/17 13:14:15 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_queue(t_queue *q)
{
	if (q)
	{
		free_queue(q->next);
		q->r->bfs = 0;
		q->r->marque = 0;
		q->r->parent = NULL;
		free(q);
		q = NULL;
	}
}

void		free_links(t_links *l)
{
	if (l)
	{
		l->r = NULL;
		free_links(l->next);
		free(l);
		l = NULL;
	}
}

static void	free_room(t_room *r)
{
	if (r)
	{
		ft_strdel(&(r->name));
		free_links(r->links);
		r->links = NULL;
		free_room(r->next);
		free(r);
		r = NULL;
	}
}

static void	free_str(t_str *str)
{
	if (str)
	{
		ft_strdel(&str->line);
		free_str(str->next);
		free(str);
		str = NULL;
	}
}

void		free_all(t_lem *stt)
{
	stt->start = NULL;
	stt->end = NULL;
	stt->lstr = NULL;
	if (stt->p_size)
		free(stt->p_size);
	free_str(stt->str);
	free_room(stt->r);
}
