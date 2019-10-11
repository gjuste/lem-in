/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:57:23 by jpelleti          #+#    #+#             */
/*   Updated: 2019/10/11 17:28:20 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_queue	*add_queue(t_lem *stt, t_queue *first, t_queue *last, t_room *add)
{
	t_queue *new;

	if (!(new = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	new->i = 0;
	new->r = add;
	new->next = NULL;
	if (new->r->marque == 0)
		new->r->marque = 1;
	if (new->r != stt->end)
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
		if (lnk->r == to_find && lnk->i == 1 && loop != stt->start)
			return (loop);
		lnk = lnk->next;
	}
	return (NULL);
}


t_room			*find_up(t_lem *stt, t_queue *q, t_queue **lst, t_room *r)
{
	t_room	*tmp;
	t_links	*lnk;

	lnk = r->links;
	while (lnk)
	{
		if ((tmp = find_reverse(stt, r, lnk->r)))
		{
			if (!(add_queue(stt, q, *lst, lnk->r)))
				return (NULL);
			(*lst) = (*lst)->next;
			(*lst)->r->parent = q->r;
			(*lst)->r->marque = q->r->marque - 1;
			// ft_printf("%s -> %d\n", (*lst)->r->name, (*lst)->r->marque);
			return (tmp);
		}
		lnk = lnk->next;
	}
	return (NULL);
}

int				find_paths(t_lem *stt, t_queue *q, t_queue **lst)
{
	t_links	*lnk;
	t_links	*tmp;
	int i;

	tmp = NULL;
	lnk = q->r->links;
	while(lnk)
	{
		if (lnk->r == stt->end && lnk->i == 0)
		{
			if ((stt->p_nb == 0 && stt->avp == 0) || (stt->p_nb > 0 && stt->avp > 0
			&& (stt->avp + stt->ants + q->r->marque + 1) / (stt->p_nb + 1) < stt->sim))
			{
				if (!(stt->p_nb == 0 && stt->avp == 0))
				ft_printf("%d || %d || ", (stt->avp + stt->ants + q->r->marque + 1) / (stt->p_nb + 1), (stt->avp + stt->ants) / (stt->p_nb));
				stt->sim = (stt->avp + stt->ants + q->r->marque + 1) / (stt->p_nb + 1);
				lnk->r->parent = q->r;
				stt->avp -= lnk->r->marque;
				lnk->r->marque = q->r->marque + 1;
				stt->avp += lnk->r->marque - 1;
				ft_printf("%d\n", stt->avp);
			}
			return (0);
		}
		else if (q->r->parent && q->r->done == 1 && q->r->parent->done == 0
			&& lnk->r->bfs == 0 && lnk->i == 0)
			find_up(stt, q, lst, q->r);
		else if (lnk->r->bfs == 0 && lnk->i == 0)
		{
			if (!add_queue(stt, q, *lst, lnk->r))
				return (-1);
			(*lst) = (*lst)->next;
			(*lst)->r->parent = q->r;
			i = q->r->done == 0 || q->r == stt->start ? 1 : -1;
			(*lst)->r->marque = q->r->marque + i;
		}
		lnk = lnk->next;
	}
	return (0);
}

int				bfs(t_lem *stt)
{
	t_queue	*q;
	t_queue	*begin;
	t_queue	*last;

	if (!(begin = add_queue(stt, NULL, NULL, stt->start)))
		return (-1);
	q = begin;
	last = q;
	while(q)
	{
		// if (q->r->marque == 0)
		// 	ft_printf("parent ->> %s marque %d done %d : %s ->> WARNING\n",q->r->parent->name, q->r->parent->marque, q->r->parent->done, q->r->name);
		if (find_paths(stt, q, &last))
			return (-1);
		q = q->next;
	}
	ft_printf("\n");
	if (stt->end->marque == 0)
		return (-1);
	if (do_path(stt) == -1)
		return (-1);
	stt->end->marque = 0;
	free_queue(begin);
	return (0);
}
