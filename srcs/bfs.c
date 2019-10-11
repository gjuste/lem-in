/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:57:23 by jpelleti          #+#    #+#             */
/*   Updated: 2019/10/09 15:57:41 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_queue	*add_queue(t_queue *first, t_queue *last, t_room *add)
{
	t_queue *new;

	if (!(new = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	new->i = 0;
	new->r = add;
	new->next = NULL;
	if (new->r->marque == 0)
		new->r->marque = 1;
	new->r->bfs = 1;
	if (!first || !last)
		return (new);
	last->next = new;
	return (first);
}

t_room			*find_reverse(t_lem *stt, t_room *to_find, t_room *loop)
{
	t_links *lnk;

	lnk = loop->links;
	while (lnk)
	{
		if (lnk->r == to_find && lnk->i == 1 && lnk->r != stt->start)
			return (loop);
		lnk = lnk->next;
	}
	return (NULL);
}

t_room			*find_exit(t_lem *stt, t_room *r)
{
	t_links	*lnk;

	lnk = r->links;
	while (lnk)
	{
		if (!(find_reverse(stt, r, lnk->r)))
			return (r);
		lnk = lnk->next;
	}
	return (NULL);
}

t_room			*find_up(t_lem *stt, t_queue *q, t_queue **lst, t_room *r)
{
	t_room	*tmp;
	t_links	*lnk;

	tmp = r;
	if (r == stt->start)
		return (NULL);
	lnk = tmp->links;
	while (!find_reverse(stt, tmp, lnk->r)) // lnk rajouter pour voir
	{
		lnk = lnk->next;
		if (!lnk)
			return (NULL);
	}
	tmp = lnk->r;
	tmp->parent = r;
	if (find_exit(stt, tmp))
	{
		if (!add_queue(q, *lst, lnk->r))
			return (NULL);
		(*lst) = (*lst)->next;
		(*lst)->r->parent = q->r;
	}
	else if (!(find_up(stt, q, lst, lnk->r)))
		return (NULL);
	return (tmp);
}

int				find_paths(t_lem *stt, t_queue *q, t_queue **lst)
{
	t_links	*lnk;
	t_links	*tmp;
	t_room	*r;
	int		i;

	tmp = NULL;
	lnk = q->r->links;
	i = 0;
	while(lnk)
	{
		if (lnk->r->bfs == 0 && lnk->i == 0 && lnk->r->done == 1)
			tmp = lnk;
		if (lnk->r->bfs == 0 && lnk->i == 0 && lnk->r->done == 0)
		{
			i++;
			if (!add_queue(q, *lst, lnk->r))
				return (-1);
			(*lst) = (*lst)->next;
			(*lst)->r->parent = q->r;
		}
		lnk = lnk->next;
	}
	if (!i && tmp)
	{
		if ((r = find_up(stt, q, lst, tmp->r)))
		{
			tmp->r->parent = q->r;
			r->parent = tmp->r;
		}
	}
	return (0);
}

int				bfs(t_lem *stt)
{
	t_queue	*q;
	t_queue	*begin;
	t_queue	*last;

	if (!(begin = add_queue(NULL, NULL, stt->start)))
		return (-1);
	q = begin;
	last = q;
	while(q && q->r != stt->end)
	{
		if (find_paths(stt, q, &last))
			return (-1);
		q = q->next;
	}
	if (stt->end->bfs == 0)
		return (-1);
	if (do_path(stt) == -1)
		return (-1);
	free_queue(begin);
	return (0);
}
