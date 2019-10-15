/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_this_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:32:36 by gjuste            #+#    #+#             */
/*   Updated: 2019/10/14 21:07:22 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_pdata	*create_pdata(t_lem *stt)
{
	t_pdata	*new;
	t_pdata	*tmp;

	if (!(new = (t_pdata*)malloc(sizeof(t_pdata))))
		return (NULL);
	new->sim = 0;
	new->path = NULL;
	new->next = NULL;
	if (!stt->path)
		stt->path = new;
	else
	{
		tmp = stt->path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_path	*create_t_path(t_room *r)
{
	t_path	*new;

	if (!(new = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new->size = 0;
	new->r = r;
	new->nr = NULL;
	new->np = NULL;
	return (new);
}

void	place_path(t_pdata *pdata, t_path *p, t_path *path)
{
	t_path	*tmp;

	tmp = pdata->path;
	while (tmp && tmp->np)
		tmp = tmp->np;
	if (!p)
	{
		if (tmp)
			tmp->np = path;
		else
			pdata->path = path;
	}
	else
		p->nr = path;
}

int		get_path(t_lem *stt, t_pdata *pdata, t_path *p, t_room *r)
{
	t_path	*path;
	t_links	*lnk;
	int		ret;

	ret = 0;
	if (!(path = create_t_path(r)))
		return (-1);
	place_path(pdata, p, path);
	lnk = r->links;
	while (lnk && lnk->i != 1)
		lnk = lnk->next;
	if (r != stt->end)
	{
		if (!lnk)
			return (-1);
		if ((ret = get_path(stt, pdata, path, lnk->r)) == -1)
			return (-1);
	}
	path->size = ++ret;
	return (ret);
}

// void	sort_path(t_pdata *pdata)
// {
// 	t_path	*p1;
// 	t_path	*p2;
// 	t_path	*tmp;
// 	t_path	*old1;
// 	t_path	*old2;

// 	p1 = pdata->path;
// 	while(p1->np)
// 	{
// 		p2 = p1->np;
// 		while (p2)
// 		{
// 			if (p2->size < p1->size)
// 			{
// 				if (p1 == pdata->path)
// 				{
// 					pdata->path = p2;
// 					tmp = p2->np;
// 					p2->np = p1->np;
// 				}
// 			}
// 			old2 = p2;
// 			p2 = p2->np;
// 		}
// 		old1 = p1;
// 		p1 = p1->np;
// 	}
// }

int		create_this_path(t_lem *stt)
{
	t_pdata	*pdata;
	t_links	*lnk;
	int		ret; // pour affichage
	int		sim; // pour affichage

	if (!(pdata = create_pdata(stt)))
		return (-1);
	sim = 0;
	lnk = stt->start->links;
	while (lnk)
	{
		ret = 0;
		if (lnk->i == 1)
		{
			if ((ret = get_path(stt, pdata, NULL, lnk->r)) == -1)
				return (-1);
			sim += ret;
			// ft_printf("%d | ", ret);
		}
		lnk = lnk->next;
	}
	// sort_path(pdata);
	sim = ((sim + stt->ants) * 1000) / (stt->p_nb + 1);
	pdata->sim = sim;
	if (sim < stt->sim || stt->sim == 0)
		stt->sim = sim;
	if (sim == stt->sim)
		ft_printf("p_nb : %d | sim : %s%d%s\t--> %d\n", stt->p_nb + 1, BR, pdata->sim, RS, pdata->sim / 1000);
	else
		ft_printf("p_nb : %d | sim : %d\t--> %d\n", stt->p_nb + 1, pdata->sim, pdata->sim / 1000);
	return (0);
}
