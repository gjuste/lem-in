/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 10:22:58 by jpelleti          #+#    #+#             */
/*   Updated: 2019/10/15 15:37:38 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	break_connexion(t_lem *stt, t_room *prec, t_room *curr)
{
	t_links *tmp;

	tmp = curr->links;
	while (tmp)
	{
		if (tmp->r == prec)
		{
			remove_connection(stt, prec, curr);
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	set_link(t_room *prec, t_room *curr)
{
	t_links *tmp;

	tmp = prec->links;
	while (tmp)
	{
		if (tmp->r == curr)
		{
			if (tmp->i == 0)
				tmp->i = 1;
			return (0);
		}
		tmp = tmp->next;
	}
	return (-1);
}

int			check_connect(t_room *r, t_room *par)
{
	t_links *tmp;

	tmp = r->links;
	while (tmp)
	{
		if (tmp->i == 1 && tmp->r == par)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	run_path(t_lem *stt, t_room *r, int *i)
{
	(*i)++;
	if (r != stt->start)
	{
		if (r->parent->done == 1 && r->done == 1 && check_connect(r, r->parent))
			break_connexion(stt, r->parent, r);
		run_path(stt, r->parent, i);
		if (set_link(r->parent, r) == -1)
			return ;
	}
	if (r != stt->end)
		r->done = 1;
}

int			do_path(t_lem *stt)
{
	int i;

	i = 0;
	run_path(stt, stt->end, &i);
	return (0);
}
